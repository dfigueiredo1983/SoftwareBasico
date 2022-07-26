#ifndef _H_TIPO
#define _H_TIPO

#include<bits/stdc++.h> 

#define vetor_string std::vector<std::string>
#define vetor_simbolos std::vector<Simbolo>

struct Simbolo{
    Simbolo(std::string texto="", int linha = 0)  : texto(texto), linha(linha) {}
    std::string texto;
    int linha;

    std::string valor;
    std::string section;
    bool simbolo_equ = false;
    bool simbolo_label = false;
};


// enum OPCODE{
//              // opcode  tamanho          açao  
//     ADD,     //  01       2         ACC <- ACC + men(OP)
//     SUB,     //  02       2         ACC <- ACC - men(OP)
//     MUL,     //  03       2         ACC <- ACC x men(OP)
//     DIV,     //  04       2         ACC <- ACC / men(OP)
//     JMP,     //  05       2         PC <- OP
//     JMPN,    //  06       2         Se ACC < 0 então PC <- OP
//     JMPP,    //  07       2         Se ACC > 0 então PC <- OP
//     JMPZ,    //  08       2         Se ACC = 0 então PC <- OP
//     COPY,    //  09       3         men(OP2) <- men(OP1)
//     LOAD,    //  10       2         ACC <- men(OP)
//     STORE,   //  11       2         men(OP) <- ACC
//     INPUT,   //  12       2         men(OP) <- entrada
//     OUTPUT,  //  13       2         saida <- men(OP)
//     STOP     //  14       1         suspende a execução
// };

// struct opcode{
//     opcode(OPCODE nome, int codigo, int n_parametros, int tamanho): nome(nome), codigo(codigo), n_parametros(n_parametros), tamanho(tamanho) {}
//     OPCODE nome;
//     int codigo;
//     int n_parametros;
//     int tamanho;
// };

// enum DIRETIVA{
//     SECTION,
//     SPACE,
//     CONST,
//     EQU,
//     IF
// };

// struct diretiva{
//     diretiva(DIRETIVA nome, int tamanho) : nome(nome), tamanho(tamanho) {};
//     DIRETIVA nome;
//     int tamanho;
// };

// namespace reservadas{
//     static std::map<std::string, opcode> comandos = {
//         { "ADD",   opcode(ADD,    1, 1,  2)},
//         { "SUB",   opcode(SUB,    1, 2,  2)},
//         { "MULT",  opcode(MUL,   1, 3,  2)},
//         { "DIV",   opcode(DIV,    1, 4,  2)},
//         { "JMP",   opcode(JMP,    1, 5,  2)},
//         { "JMPN",  opcode(JMPN,   1, 6,  2)},
//         { "JMPP",  opcode(JMPP,   1, 7,  2)},
//         { "JMPZ",  opcode(JMPZ,   1, 8,  2)},
//         { "COPY",  opcode(COPY,   2, 9,  3)},
//         { "LOAD",  opcode(LOAD,   1, 10, 2)},
//         { "STORE", opcode(STORE,  1, 11, 2)},
//         { "INPUT", opcode(INPUT,  1, 12, 2)},
//         { "OUTPUT",opcode(OUTPUT, 1, 13, 2)},
//         { "STOP",  opcode(STOP,   0, 14, 1)}
//     };

//     static std::map<std::string, diretiva> diretivas = {
//         {"SECTION", diretiva(SECTION,  1)},
//         {"SPACE",   diretiva(SPACE,    1)},
//         {"CONST",   diretiva(CONST,    1)},
//         {"EQU",     diretiva(EQU,      1)},
//         {"IF",      diretiva(IF,       1)}
//     };
// }


#endif
