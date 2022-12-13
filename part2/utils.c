// Estrutura da tabela de símbolos

#define TAM_TAB 100

struct elemTabSimbolos {
    char id[100];   // identificador
    int end;        // endereço
    int tip;         // tipo
} tabSimb[TAM_TAB], elemTab;

int posTab = 0;

int buscaSimbolo (char *id) {
    int i;
    for (i = posTab - 1; strcmp(tabSimb[i].id, id) && i >= 0; i--)
        ;
        if (i == -1)
            yyerror("Identificador não encontrado.");
    return i;
}

void insereSimbolo (struct elemTabSimbolos elem) {
    int i;
    if (posTab == TAM_TAB)
        yyerror("Tabela de Símbolos Cheia!");

    for (i = posTab - 1; strcmp(tabSimb[i].id, elem.id) && i >= 0; i--)
        ;
    if (i != -1)
        yyerror("Identificador duplicado!");
    tabSimb[posTab++] = elem;
}