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

    struct registro_de_cabeca{
        char status[1];
        int topo;
        char descricao[40];
        char desC1[22];
        char desC2[19];
        char desC3[24];
        char desC4[8];
        char codC5[1];
        char desC5[16];
        char codC6[1];
        char desC6[18];
        char codC7[1];
        char desC7[19];
        int proxRRN;
        int nroRegRem;
    };

    typedef struct registro_de_cabeca CABECAO;

    CABECAO cabecinha;
    strcpy(cabecinha.descricao, "LISTAGEM DA FROTA DOS VEICULOS NO BRASIL");
    strcpy(cabecinha.desC1, "CODIGO IDENTIFICADOR");
    strcpy(cabecinha.desC2, "ANO DE FABRICACAO");
    strcpy(cabecinha.desC3,"QUANTIDADE DE VEICULOS");
    strcpy(cabecinha.desC4, "ESTADO");
    strcpy(cabecinha.desC5, "NOME DO VEICULO");
    strcpy(cabecinha.desC6, "MARCA DE VEICULO");
    strcpy(cabecinha.desC7, "MODELO DO VEICULO");

    printf("%lu",sizeof(cabecinha));
    //entrada= fopen(nome_entrada, "rb");
    //fclose(entrada);


    //saida= fopen(nome_saida, "w+b");
    //fclose(saida);

}

void tipo2(char nome_entrada[30], char nome_saida[30]){
    FILE *entrada;
    FILE *saida;


    entrada= fopen(nome_entrada, "rb");
    fclose(entrada);


    saida= fopen(nome_saida, "w+b");
    fclose(saida);
}