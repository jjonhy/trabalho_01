//
// Created by conta on 22/05/2022.
//

#ifndef TRABALHO_01_REGISTROS_H
#define TRABALHO_01_REGISTROS_H

//registro de cabeçalho 1
struct registro_de_cabeca{
    char status;
    int topo;
    char descricao[40];
    char desC1[22];
    char desC2[19];
    char desC3[24];
    char desC4[8];
    char codC5;
    char desC5[16];
    char codC6;
    char desC6[18];
    char codC7;
    char desC7[19];
    int proxRRN;
    int nroRegRem;
};

//registro de cabeçalho 2
struct registro_de_cabeca2{
    //campos de tamanho fixo
    char status;
    long long int topo;
    char descricao[40];
    char desC1[22], desC2[19], desC3[24], desC4[8];
    char codC5, desC5[16], codC6, desC6[18], codC7, desC7[19];
    long long int proxByteOffset;
    int nroRegRem;
};

typedef struct registro_de_cabeca CABECAO;
typedef struct registro_de_cabeca2 CABECAO2;

//registro do arquivo tipo 1
struct registro_de_dados{
    char removido;
    int prox;
    int id;
    int ano;
    int qtt;
    char sigla[2];
    int tamCidade;
    char codC5;
    char *cidade;
    int tamMarca;
    char codC6;
    char *marca;
    int tamModelo;
    char codC7;
    char *modelo;
};

//registro do arquivo tipo 2
struct arquivo2{
    //campos para gerenciamento logico do registro
    char removido;
    int tamanhoRegistro;
    long long int prox;

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

typedef struct registro_de_dados DADAO;
typedef struct arquivo2 DADAO2;

CABECAO *set_cabecalho1();
CABECAO2 *set_cabecalho2();
void tipo1(char nome_entrada[30], char nome_saida[30]);
void tipo2(char nome_entrada[30], char nome_saida[30]);
DADAO *funcao1_tipo1(const char *line);
DADAO2 *funcao1_tipo2(const char *line);
void funcao2_tipo1(char nome_entrada[30]);
void funcao2_tipo2(char nome_entrada[30]);
void funcao3_tipo1(char nome_entrada[30], int quantidade);
void funcao3_tipo2(char nome_entrada[30], int quantidade);
void funcao4(char nome_entrada[30], int RRN);
void binarioNaTela(char *nomeArquivoBinario);
void scan_quote_string(char *str);
DADAO* retornainput(char nome_entrada[30], int i);
void escreverbin1(FILE *saida, const DADAO *input);
void escrevebin2(FILE *saida, const DADAO2 *input);
void printainput();
void buscaRRN(FILE *entrada, DADAO *input);
void printainput2(const DADAO2 *input);

#endif //TRABALHO_01_REGISTROS_H
