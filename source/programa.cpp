#include "programa.h"

int programa(std::string op, std::string input, std::string output){

   std::cout << "Op: " << op << std::endl;
   std::cout << "Input: " << input << std::endl;
   std::cout << "Output: " << output << std::endl;


   if(op.length() != 2){
      std::cout << "Erro na passagem do parametro op: " << op << std::endl;
      exit(-2);
   }
   
   switch (op[1]){
      case 'p': std::cout << "Pre processamento" << std::endl;
         break;
      case 'o': std::cout << "Montador" << std::endl;
         break;
      default:
         std::cout << "Opção inválida" << std::endl;
         exit(-2);
         break;
   }
   
   vetor_string file;
   if(!le_arquivo(input, &file)){
      std::cout << "Arquivo inexistente ou vazio." << std::endl;
   }
   
   vetor_string pre_precessado;
   vetor_simbolos simbolos;
   preprocesso(file, &pre_precessado, &simbolos);
   
   std::cout << "Imprimir a tabela de simbolos" << std::endl;
   for(const auto& value : simbolos){ // Veririca se a lista de simbolos foi criada com sucesso
      std::cout << "Linha: " << value.linha;
      std::cout << "   Simbolo: " << value.texto << std::endl;
   }

   std::cout << "Imprimir apenas as labels" << std::endl;
   for(const auto& value : simbolos){ // Veririca se a lista de simbolos foi criada com sucesso
      if(value.simbolo_label){
         std::cout << value.texto << std::endl;
      }
   }


   return 0;
}

bool le_arquivo(std::string input, vetor_string* file){
   std::ifstream file_string(input.c_str());

   if(!file_string)
      return false;

   std::string temp;
   while(std::getline(file_string, temp))
      file->push_back(std::string(temp.c_str()));
   
   return true;
}