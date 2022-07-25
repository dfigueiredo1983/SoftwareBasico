#ifndef _H_TIPO
#define _H_TIPO

#include<bits/stdc++.h> 

#define vetor_string std::vector<std::string>
#define vetor_simbolos std::vector<Simbolo>

struct Simbolo{
    Simbolo(std::string texto = "", int linha = 0)  : texto(texto), linha(linha){}
    std::string texto;
    int linha;

    bool simbolo_equ = false;
    bool simbolo_label = false;
};


#endif
