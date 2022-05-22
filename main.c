//
// Created by conta on 16/05/2022.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "registros.h"




int main() {
    char tipo[30];
    char nome_entrada[30];
    char nome_saida[30];
    int escolha;
    //scanf("%d %s %s %s",&escolha,tipo,nome_entrada,nome_saida);
    strcpy(tipo,"tipo1");
    strcpy(nome_entrada,"arquivoEntrada1.csv");
    strcpy(nome_saida,"bin.bin");


    printf("SIZE CABEÇALHO %lu\n",sizeof(CABECAO));
    printf("SIZE CABEÇALHO2 %lu\n",sizeof(CABECAO2));
    printf("SIZE DADO1 %lu\n",sizeof(DADAO));
    printf("SIZE DADO2 %lu\n",sizeof(DADAO2));


    if (strcmp(tipo, "tipo1") == 0){
        tipo1( nome_entrada, nome_saida);
        funcao2_tipo1(nome_entrada);
    } else if (strcmp(tipo, "tipo2") == 0){
        tipo2( nome_entrada, nome_saida);
    } else {
        printf("Tipo não está certo");
    }
    return 0;
}

