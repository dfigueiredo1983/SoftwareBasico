L1: EQU 0
L2: EQU 0
SECAO TEXTO
IF L1
LOAD SPACE
IF L2
INPUT SPACE
INPUT OLD_DATA ;Comentários
LOAD OLD_DATA
L1: DIV DOIS
STORE  NEW_DATA ;Comentários
MULT DOIS
            STORE TMP_DATA
LOAD OLD_DATA
SUB TMP_DATA                   ;Comantários daniel do carmo
STORE TMP_DATA
OUTPUT TMP_DATA
COPY NEW_DATA, OLD_DATA
            LOAD OLD_DATA
JMPP L1                         ;Deve ser excluído do arquivo de dados
STOP  
SECAO DADOS
                  DOIS: CONST 2 ;Comentário de ser excluído do arquivo de dados
OLD_DATA: SPACE
NEW_DATA: SPACE
TMP_DATA: SPACE ; Espaços em branco no início do documento devem ser removidos