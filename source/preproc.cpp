#include "preproc.h"

bool lista_simbolo(std::string linha, vetor_simbolos* lista_simbolos, int* numero_linha){ // Cria a lista de simbolos
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
        if(Simbolos->at(i).texto[tamanho-1] == ':'){
            std::cout << "Achou uma label: " << Simbolos->at(i).texto << std::endl;
            Simbolos->at(i).simbolo_label = true;
        }
//        std::cout << Simbolos->at(i).texto << " - " << Simbolos->at(i).texto.size() << std::endl;
    }
}

void preprocesso(vetor_string& entrada, vetor_string* saida, vetor_simbolos* simbolos){
    int numero_linhas = 1;
    for(auto linha : entrada)
        lista_simbolo(linha, simbolos, &numero_linhas);

    tabela_simbolos(simbolos);
}