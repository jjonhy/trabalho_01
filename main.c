/*
JOAO PEDRO MATOS DE DEUS - NUSP 12677492
Guilherme Makarovsky Galvão NUSP 5314920
*/

#include <stdio.h>
#include <string.h>
#include "registros.h"

int main() {
    char tipo[30];
    int escolha;
    char nome_entrada[30];
    char nome_saida[30];

    scanf("%d", &escolha);

    if (escolha == 1){
        scanf("%s %s %s",tipo,nome_entrada,nome_saida);
        if (strcmp(tipo, "tipo1") == 0){
            tipo1( nome_entrada, nome_saida);
        } else if (strcmp(tipo, "tipo2") == 0){
            tipo2( nome_entrada, nome_saida);
        } else {
            printf("Falha no processamento do arquivo.");
        }
    }
    if (escolha == 2){
        scanf("%s %s",tipo,nome_entrada);
        if (strcmp(tipo, "tipo1") == 0){
            funcao2_tipo1(nome_entrada);
        } else if (strcmp(tipo, "tipo2") == 0){
            funcao2_tipo2(nome_entrada);
        } else {
            printf("Falha no processamento do arquivo.");
        }
    }
    if (escolha == 3){
        int quantidade;
        scanf("%s %s",tipo,nome_entrada);
        scanf("%d",&quantidade);
        if (strcmp(tipo, "tipo1") == 0){
            funcao3_tipo1(nome_entrada, quantidade);
        } else if (strcmp(tipo, "tipo2") == 0){
            funcao3_tipo2(nome_entrada, quantidade);
        } else {
            printf("Falha no processamento do arquivo.");
        }
    }
    if (escolha == 4){
        int RRN;
        scanf("%s %s",tipo,nome_entrada);
        scanf("%d",&RRN);
        funcao4(nome_entrada, RRN);
    }

    return 0;
}

