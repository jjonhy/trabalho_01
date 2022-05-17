//
// Created by conta on 16/05/2022.
//

#include <stdio.h>
#include <string.h>

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

struct registro_de_dados{
    char removido[1];
    int prox;
    int id;
    int ano;
    int qtt;
    char sigla[2];
    int tamCidade;
    char codC5[1];
    char *cidade;
    int tamMarca;
    char codC6[1];
    char *marca;
    int tamModelo;
    char codC7[1];
    char *modelo;
};

typedef struct registro_de_dados DADAO;

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

    CABECAO cabecinha;
    strcpy(cabecinha.status,"1");
    cabecinha.topo = -1;
    strcpy(cabecinha.descricao, "LISTAGEM DA FROTA DOS VEICULOS NO BRASIL");
    strcpy(cabecinha.desC1, "CODIGO IDENTIFICADOR: ");
    strcpy(cabecinha.desC2, "ANO DE FABRICACAO: ");
    strcpy(cabecinha.desC3,"QUANTIDADE DE VEICULOS: ");
    strcpy(cabecinha.desC4, "ESTADO: ");
    strcpy(cabecinha.codC5, "0");
    strcpy(cabecinha.desC5, "NOME DA CIDADE");
    strcpy(cabecinha.codC6, "1");
    strcpy(cabecinha.desC6, "MARCA DE VEICULO");
    strcpy(cabecinha.desC7, "2");
    strcpy(cabecinha.codC7, "MODELO DO VEICULO");

    printf("%lu\n",sizeof(CABECAO));
    printf("%lu", sizeof(cabecinha.status));
    //entrada= fopen(nome_entrada, "r");

    //fread()

    //fclose(entrada);


    saida= fopen(nome_saida, "w+b");
    fwrite(&cabecinha,1, sizeof(CABECAO),saida);
    fclose(saida);

}

void tipo2(char nome_entrada[30], char nome_saida[30]){
    FILE *entrada;
    FILE *saida;


    entrada= fopen(nome_entrada, "rb");
    fclose(entrada);


    saida= fopen(nome_saida, "w+b");
    fclose(saida);
}