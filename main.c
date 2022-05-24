//
// Created by conta on 16/05/2022.
//

#include <stdio.h>
#include <string.h>
#include "registros.h"


int main() {
    char tipo[30];
    int escolha;
    char nome_entrada[30];
    char nome_saida[30];

    strcpy(tipo,"tipo1");
    escolha = 2;
    //strcpy(nome_entrada,"arquivoEntrada1.csv");
    //strcpy(nome_saida,"bin.bin");
    //scanf("%d", &escolha);
    strcpy(nome_entrada,"binario5.bin");

    printf("SIZE CABEÇALHO %lu\n",sizeof(struct registro_de_cabeca));
    printf("SIZE CABEÇALHO2 %lu\n",sizeof(CABECAO2));
    printf("SIZE DADO1 %lu\n",sizeof(DADAO));
    printf("SIZE DADO2 %lu\n",sizeof(DADAO2));

    if (escolha == 1){
        //scanf("%s %s %s",tipo,nome_entrada,nome_saida);
        if (strcmp(tipo, "tipo1") == 0){
            tipo1( nome_entrada, nome_saida);
        } else if (strcmp(tipo, "tipo2") == 0){
            tipo2( nome_entrada, nome_saida);
        } else {
            printf("Tipo não está certo");
        }
    }
    if (escolha == 2){
        //scanf("%s %s",tipo,nome_entrada);
        if (strcmp(tipo, "tipo1") == 0){
            funcao2_tipo1(nome_entrada);
        } else if (strcmp(tipo, "tipo2") == 0){
            funcao2_tipo2(nome_entrada);
        } else {
            printf("Tipo não está certo");
        }
    }
    if (escolha == 3){

    }
    if (escolha == 4){

    }




    return 0;
}

