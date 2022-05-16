//
// Created by conta on 16/05/2022.
//

#include <stdio.h>
#include <string.h>

void tipo1(char nome_entrada[30], char nome_saida[30]);
void tipo2(char nome_entrada[30], char nome_saida[30]);

int main() {
    char tipo[30];
    char nome_entrada[30];
    char nome_saida[30];
    scanf("%s %s %s",tipo,nome_entrada,nome_saida);

    if (strcmp(tipo, "tipo1") == 0){
        tipo1( nome_entrada, nome_saida);
    } else if (strcmp(tipo, "tipo2") == 0){
        tipo2( nome_entrada, nome_saida);
    } else {
        printf("Tipo não está certo");
    }
    return 0;
}

void tipo1(char nome_entrada[30], char nome_saida[30]){
    FILE *entrada;
    FILE *saida;


    entrada= fopen(nome_entrada, "rb");
    fclose(entrada);


    saida= fopen(nome_saida, "w+b");
    fclose(saida);

}

void tipo2(char nome_entrada[30], char nome_saida[30]){

}