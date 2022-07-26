#include "preproc.h"
#include "tipo.h"

bool lista_simbolo(std::string linha, vetor_simbolos* lista_simbolos, int* numero_linha){
    while(linha[0] == ' ')
        linha.erase(0,1);

    Simbolo simbolo;
    std::string temp;
    std::stringstream li(linha);
    while(li >> temp){
        std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        if(temp.compare(0,1,";") == 0)
            break;
        
        simbolo.texto = temp;
        simbolo.linha = *numero_linha;
        lista_simbolos->push_back(simbolo);
    }

    *numero_linha = *numero_linha + 1;
    return true;
}

void tabela_simbolos(vetor_simbolos* Simbolos){
    for(size_t i=0; i < Simbolos->size(); ++i){
        int tamanho = Simbolos->at(i).texto.size();
        if(Simbolos->at(i).texto[tamanho-1] == ':'){ // verifica se é uma label
            Simbolos->at(i).simbolo_label = true;
            if(Simbolos->at(i+1).texto.compare("EQU") == 0){
                Simbolos->at(i).simbolo_equ = true;
                Simbolos->at(i).valor = Simbolos->at(i+2).texto;               
            }
        }
    }
}

void verifica_secao(vetor_simbolos* Simbolos){

    bool secao_texto = false;
    bool secao_dados = false;

    for(size_t i=0; i < Simbolos->size(); ++i){
        if(Simbolos->at(i).texto.compare("SECAO") == 0 && Simbolos->at(i+1).texto.compare("TEXTO") == 0){
            secao_texto = true;
            secao_dados = false;
        }
        if(Simbolos->at(i).texto.compare("SECAO") == 0 && Simbolos->at(i+1).texto.compare("DADOS") == 0){
            secao_dados = true;
            secao_texto = false;
        }

        if(secao_texto){
            Simbolos->at(i).section = "TEXTO";
        }else if(secao_dados){
            Simbolos->at(i).section = "DADOS";            
        }else{
            Simbolos->at(i).section = "EQU";
        }

        if(Simbolos->at(i).simbolo_label && (Simbolos->at(i+1).texto.compare("SPACE") == 0)){
            Simbolos->at(i).valor = "0";
        }

        if(Simbolos->at(i).simbolo_label && (Simbolos->at(i+1).texto.compare("CONST") == 0)){
            Simbolos->at(i).valor = Simbolos->at(i+2).texto;
        }
   }
}

void expande_if(vetor_string* saida, vetor_simbolos* Simbolos){ // IF inclui a instrução se a linha com IF for != de zero

    vetor_simbolos aux;
    vetor_simbolos lista_IF;
    for(size_t i=0; i < Simbolos->size(); ++i){
        if(Simbolos->at(i).section.compare("EQU") == 0 && Simbolos->at(i).simbolo_label){
            lista_IF.push_back(Simbolos->at(i));
        }
    }

    for(size_t i=0; i < Simbolos->size(); ++i){
        if(Simbolos->at(i).section.compare("TEXTO") == 0 || Simbolos->at(i).section.compare("DADOS") == 0){
            if(Simbolos->at(i).texto.compare("IF") == 0){
                for(size_t y=0; y < lista_IF.size(); ++y){
                    std::string alvo = Simbolos->at(i+1).texto + ":";
                    if(lista_IF.at(y).texto.compare(alvo) == 0){
                        Simbolos->at(i+1).valor = lista_IF.at(y).valor;
                    }
                }
            }
            aux.push_back(Simbolos->at(i));
        }
    }

    std::vector<int> lista_remover_IF;
    for(size_t i=0; i < aux.size(); ++i){
        while(aux.at(i).texto.compare("IF") == 0){
            lista_remover_IF.push_back(i);
            ++i;
            lista_remover_IF.push_back(i);
            if(aux.at(i).valor.compare("0") == 0){// Se == 0 não inlcui a proxima linha
                ++i;
                lista_remover_IF.push_back(i);
                while(aux.at(i).linha == aux.at(i+1).linha){
                    ++i;
                    lista_remover_IF.push_back(i);
                }
                ++i;
            }else{
                ++i;
            }
            std::cout << std::endl;
        }
    }

    std::cout << "Lista de itens que devem ser removidos" << std::endl;
    for(size_t i=0; i < lista_remover_IF.size(); ++i){
        std::cout << "Item: " << lista_remover_IF.at(i) << std::endl;
        aux.erase( aux.begin() + lista_remover_IF.at(i) - i  );
    }

    for(size_t i=0; i < aux.size(); ++i){
        std::string word = aux.at(i).texto + " ";
        while( (i+1 < aux.size()) && (aux.at(i).linha == aux.at(i+1).linha) ){
            word += aux.at(i+1).texto;
            word += " ";
            ++i;
        }
        saida->push_back(word);
    }



    // for(size_t i=0; i < aux.size(); ++i){
    //     std::cout << "Simbolo: " << aux.at(i).texto << " Linha: " << aux.at(i).linha << std::endl;
    // }

    // vetor_simbolos temp;
    // for(size_t i=0; i < aux.size(); ++i){
    //     while(aux.at(i).texto.compare("IF") == 0){
    //         ++i;
    //         if(aux.at(i).valor.compare("0") == 0){// Se == 0 não inlcui a proxima linha
    //             ++i;
    //             while(aux.at(i).linha == aux.at(i+1).linha){
    //                 ++i;
    //             }
    //             ++i;
    //         }else{
    //             ++i;
    //         }
    //         std::cout << std::endl;
    //     }
    //     temp.push_back(aux.at(i));
    // }

    // for(size_t i=0; i < temp.size(); ++i){
    //     std::string word = temp.at(i).texto + " ";
    //     while( (i+1 < temp.size()) && (temp.at(i).linha == temp.at(i+1).linha) ){
    //         word += temp.at(i+1).texto;
    //         word += " ";
    //         ++i;
    //     }
    //     saida->push_back(word);
//        std::cout << "Simbolo: " << temp.at(i).texto << " Linha: " << temp.at(i).linha << std::endl;
    // }

}

void preprocesso(vetor_string& entrada, vetor_string* saida, vetor_simbolos* simbolos){
    int numero_linhas = 1;
    for(auto linha : entrada)
        lista_simbolo(linha, simbolos, &numero_linhas); // Cria uma lista de simbolos de cada strring

    tabela_simbolos(simbolos); // Insere as características de cada simbolo, label , equ, valor
    verifica_secao(simbolos); // marca as seções de cada label
    expande_if(saida, simbolos);
}