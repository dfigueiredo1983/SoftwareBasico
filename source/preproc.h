#ifndef _H_PREPROC
#define _H_PREPROC

#include "tipo.h"

void preprocesso(vetor_string&, vetor_string*, vetor_simbolos*);
bool lista_token(std::string, vetor_simbolos*, int*);
void tabela_simbolos(vetor_simbolos*);
void verifica_secao(vetor_simbolos*);
void expande_if(vetor_string*, vetor_simbolos*);


# endif