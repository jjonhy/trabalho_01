//
// Created by conta on 16/05/2022.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

typedef struct arquivo1{
    //campos de tamanho fixo
    int id, ano, qtt;
    char sigla[2];

    //campos de tamanho variavel
    int tamCidade;
    char codC5, *cidade;
    int tamMarca;
    char codC6, *marca;
    int tamModelo;
    char codC7, *modelo;

};

typedef struct arquivo1 REGISTRO1;

void tipo1(char nome_entrada[30], char nome_saida[30]);
void tipo2(char nome_entrada[30], char nome_saida[30]);

REGISTRO1 *pegapega(const char *line);

int main() {
    char tipo[30];
    char nome_entrada[30];
    char nome_saida[30];
    //scanf("%s %s %s",tipo,nome_entrada,nome_saida);
    strcpy(tipo,"tipo1");
    strcpy(nome_entrada,"arquivoEntrada1.csv");
    strcpy(nome_saida,"bin.bin");

    if (strcmp(tipo, "tipo1") == 0){
        tipo1( nome_entrada, nome_saida);
    } else if (strcmp(tipo, "tipo2") == 0){
        tipo2( nome_entrada, nome_saida);
    } else {
        printf("Tipo não está certo");
    }
    return 0;
}

char* getfield(char* line, int num)
{
    char* tok;
    for (tok = strtok(line, ",");
    num--;
    tok = strtok(NULL, ",\n"))
    {
        if (num == 0)
            return tok;
    }
    return NULL;
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
    printf("%lu\n", sizeof(cabecinha.status));

    char line[1024];
    entrada= fopen(nome_entrada, "r");
    fgets(line,1024,entrada);

    while(fgets(line,1024,entrada)){
        //printf("tam de line %lu\n", strlen(line));
        REGISTRO1 *input = pegapega(line);
        printf("%d\n", input->id);
    }
    fclose(entrada);
/*
    while(!feof(entrada)){
        fscanf(entrada, "%c", &caracter);
        string[tam_string-1] = caracter;
        //printf("%c", caracter);
        if (caracter == ',' && cont == 0){
            input->id = atoi(string);
            printf(" ID: %d ", input->id);
            tam_string=0;
            help = 1;
        }
        if (caracter == ',' && cont == 1){
            if (char_anterior == ','){
                printf("null ");
            }
            else{
                input->ano = atoi(string);
                printf("ANO: %d ", input->ano);
            }
            help = 1;
            tam_string=0;
        }
        if (caracter == ',' && cont == 2){
            if (char_anterior == ','){
                printf("null ");
            }
            else{
                string[tam_string-1] = '\0';
                input->cidade = (char*) malloc(tam_string * sizeof(char));
                strcpy(input->cidade, string);
                printf("CIDADE: %s ", input->cidade);
            }
            help = 1;
            tam_string=0;
        }
        if (caracter == ',' && cont == 3){
            if (char_anterior == ','){
                printf("null ");
            }
            else{
                input->qtt = atoi(string);
                printf("QUANTIDADE: %d ", input->qtt);
            }
            help = 1;
            tam_string=0;
        }
        if (caracter == ',' && cont == 4){
            if (char_anterior == ','){
                printf("null ");
            }
            else{
                string[tam_string-1] = '\0';
                strcpy(input->sigla, string);
                printf("SIGLA: %s ", input->sigla);
            }
            help = 1;
            tam_string=0;
        }
        if (caracter == ',' && cont == 5){
            if (char_anterior == ','){
                printf("null ");
            }
            else{
                string[tam_string-1] = '\0';
                input->marca = (char*) malloc(tam_string * sizeof(char));
                strcpy(input->marca, string);
                printf("MARCA: %s ", input->marca);
            }
            help = 1;
            tam_string=0;
        }
        if (caracter == '\n' && cont == 6){
            if (char_anterior == ','){
                printf("null ");
            }
            else{
                string[tam_string-1] = '\0';
                input->modelo = (char*) malloc(tam_string * sizeof(char));
                strcpy(input->modelo, string);
                printf("MODELO: %s ", input->modelo);
            }
            help = 1;
            tam_string=0;
        }
        if (cont == 7){
            printf("\n");
            cont = 0;
            tam_string=0;
        }
        if (help == 1)
            cont++;
        char_anterior = caracter;
        tam_string++;
        string = realloc( string ,tam_string * sizeof(char));
        help = 0;
    }
*/

    saida= fopen(nome_saida, "w+b");
    fwrite(&cabecinha,1, sizeof(CABECAO),saida);
    fclose(saida);

}

REGISTRO1 *pegapega(const char *line) {
    char caracter;
    char char_anterior = 'c';
    int i=0, tam_string = 1, help=0;
    int cont = 0;
    REGISTRO1 *input = (REGISTRO1 *) malloc(sizeof (REGISTRO1));
    char *string = malloc( tam_string * sizeof(char));
    for (i = 0; i < strlen(line) ; i++){
        caracter = line[i];
        string[tam_string-1] = caracter;
        //printf("%c", caracter);
        if (caracter == ',' && cont == 0){
            string[tam_string-1] = '\0';
            input->id = atoi(string);
            printf(" ID: %d ", input->id);
            tam_string=0;
            help = 1;
        }
        if (caracter == ',' && cont == 1){
            if (char_anterior == ','){
                printf("null ");
            }
            else{
                string[tam_string-1] = '\0';
                input->ano = atoi(string);
                printf("ANO: %d ", input->ano);
            }
            help = 1;
            tam_string=0;
        }
        if (caracter == ',' && cont == 2){
            if (char_anterior == ','){
                printf("null ");
            }
            else{
                string[tam_string-1] = '\0';
                input->cidade = (char*) malloc(tam_string * sizeof(char));
                strcpy(input->cidade, string);
                printf("CIDADE: %s ", input->cidade);
            }
            help = 1;
            tam_string=0;
        }
        if (caracter == ',' && cont == 3){
            if (char_anterior == ','){
                printf("null ");
            }
            else{
                string[tam_string-1] = '\0';
                input->qtt = atoi(string);
                printf("QUANTIDADE: %d ", input->qtt);
            }
            help = 1;
            tam_string=0;
        }
        if (caracter == ',' && cont == 4){
            if (char_anterior == ','){
                printf("null ");
            }
            else{
                string[tam_string-1] = '\0';
                strcpy(input->sigla, string);
                printf("SIGLA: %s ", input->sigla);
            }
            help = 1;
            tam_string=0;
        }
        if (caracter == ',' && cont == 5){
            if (char_anterior == ','){
                printf("null ");
            }
            else{
                string[tam_string-1] = '\0';
                input->marca = (char*) malloc(tam_string * sizeof(char));
                strcpy(input->marca, string);
                printf("MARCA: %s ", input->marca);
            }
            help = 1;
            tam_string=0;
        }
        if ( caracter == '\r' && cont == 6){
            if (char_anterior == ','){
                printf("null ");
            }
            else{
                string[tam_string-1] = '\0';
                input->modelo = (char*) malloc(tam_string * sizeof(char));
                strcpy(input->modelo, string);
                printf("MODELO: %s ", input->modelo);
            }
            help = 1;
            tam_string=0;
        }
        if (cont == 7){
            printf("\n");
            cont = 0;
            tam_string=0;
            return input;
        }
        if (help == 1)
            cont++;
        char_anterior = caracter;
        tam_string++;
        string = realloc( string ,tam_string * sizeof(char));
        help = 0;
    }
}

void tipo2(char nome_entrada[30], char nome_saida[30]){
    FILE *entrada;
    FILE *saida;


    entrada= fopen(nome_entrada, "rb");
    fclose(entrada);


    saida= fopen(nome_saida, "w+b");
    fclose(saida);
}