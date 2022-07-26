#include "programa.h"

int main(int argc, char* argv[]){

   if(argc != 4){
      std::cout << "Erro na passagem dos parâmetros\n" << std::endl;
      exit (-1);
   }
   
   std::string op	= argv[1];
   std::string input	= argv[2];
   std::string output	= argv[3];

   return programa(op, input, output);
}
