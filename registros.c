//
// Created by conta on 22/05/2022.
//
#include <stdio.h>
#include "registros.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

CABECAO *set_cabecalho1()
{
    //criando e alocando espaço para o registro
    CABECAO *cab_return;
    cab_return = (CABECAO *)malloc(sizeof(CABECAO));

    //prenchendo o registro com as informações iniciais
//    cab_return->status = '0';
    strcpy(cab_return->status, "0");
    cab_return->topo = -1;
    strcpy(cab_return->descricao,"LISTAGEM DA FROTA DOS VEICULOS NO BRASIL");
    strcpy(cab_return->desC1, "CODIGO IDENTIFICADOR: ");
    strcpy(cab_return->desC2,"ANO DE FABRICACAO: ");
    strcpy(cab_return->desC3, "QUANTIDADE DE VEICULOS: ");
    strcpy(cab_return->desC4, "ESTADO: ");
    strcpy(cab_return->desC5, "NOME DA CIDADE: ");
    strcpy(cab_return->desC6, "MARCA DO VEICULO: ");
    strcpy(cab_return->desC7, "MODELO DO VEICULO: ");
//    cab_return->codC5 = '0';
//    cab_return->codC6 = '1';
//    cab_return->codC7 = '2';
    strcpy(cab_return->codC5, "0");
    strcpy(cab_return->codC6, "1");
    strcpy(cab_return->codC7, "2");
    cab_return->proxRRN = 0;
    cab_return->nroRegRem = 0;

    return cab_return;
}
CABECAO2 *set_cabecalho2()
{
    //criando e alocando espaço para o registro
    CABECAO2 *cab_return;
    cab_return = (CABECAO2*)malloc(sizeof(CABECAO2));

    //prenchendo o registro com as informações iniciais
    cab_return->status = '0';
    cab_return->topo = -1;
    strcpy(cab_return->descricao,"LISTAGEM DA FROTA DOS VEICULOS NO BRASIL");
    strcpy(cab_return->desC1, "CODIGO IDENTIFICADOR: ");
    strcpy(cab_return->desC2,"ANO DE FABRICACAO: ");
    strcpy(cab_return->desC3, "QUANTIDADE DE VEICULOS: ");
    strcpy(cab_return->desC4, "ESTADO: ");
    strcpy(cab_return->desC5, "NOME DA CIDADE: ");
    strcpy(cab_return->desC6, "MARCA DO VEICULO: ");
    strcpy(cab_return->desC7, "MODELO DO VEICULO: ");
    cab_return->codC5 = '0';
    cab_return->codC6 = '1';
    cab_return->codC7 = '2';
    cab_return->proxByteOffset = 0;
    cab_return->nroRegRem = 0;


    return cab_return;
}
void tipo1(char nome_entrada[30], char nome_saida[30]){
    FILE *entrada;
    FILE *saida;

    CABECAO *cabecinha = set_cabecalho1();

    entrada= fopen(nome_entrada, "r");
    saida= fopen(nome_saida, "w+b");

    fwrite(cabecinha,1, sizeof(CABECAO),saida);

    char line[1024];
    fgets(line,1024,entrada);
    while(fgets(line,1024,entrada)){
        //printf("tam de line %lu\n", strlen(line));
        DADAO *input = funcao1_tipo1(line);
        fwrite(input, 1, sizeof(DADAO), saida);
        //printf("%d\n", input->id);
    }
    binarioNaTela(nome_entrada);
    fclose(entrada);
    fclose(saida);
}
void tipo2(char nome_entrada[30], char nome_saida[30]){
    FILE *entrada;
    FILE *saida;

    CABECAO2 *cabecinha = set_cabecalho2();

    entrada= fopen(nome_entrada, "r");
    saida= fopen(nome_saida, "w+b");
    fwrite(cabecinha,1, sizeof(CABECAO2),saida);

    char line[1024];
    fgets(line,1024,entrada);
    while(fgets(line,1024,entrada)){
        //printf("tam de line %lu\n", strlen(line));
        DADAO2 *input = funcao1_tipo2(line);
        fwrite(input, 1, sizeof(DADAO), saida);
        //printf("%d\n", input->id);
    }

    binarioNaTela(nome_entrada);
    fclose(entrada);
    fclose(saida);
}
DADAO *funcao1_tipo1(const char *line) {
    char caracter;
    char char_anterior = 'c';
    int i=0, tam_string = 1, help=0;
    int cont = 0;
    DADAO *input = (DADAO *) malloc(sizeof (DADAO));
    char *string = malloc( tam_string * sizeof(char));
    for (i = 0; i < strlen(line) ; i++){
        caracter = line[i];
        string[tam_string-1] = caracter;
        //printf("%c", caracter);
        if (caracter == ',' && cont == 0){
            string[tam_string-1] = '\0';
            input->id = atoi(string);
            //printf(" ID: %d ", input->id);
            tam_string=0;
            help = 1;
        }
        if (caracter == ',' && cont == 1){
            if (char_anterior == ','){
                //printf("null ");
                input->ano = -1;
            }
            else{
                string[tam_string-1] = '\0';
                input->ano = atoi(string);
                //printf("ANO: %d ", input->ano);
            }
            help = 1;
            tam_string=0;
        }
        if (caracter == ',' && cont == 2){
            if (char_anterior == ','){
                //printf("null ");
                input->cidade = NULL;
            }
            else{
                string[tam_string-1] = '\0';
                input->cidade = (char*) malloc(tam_string * sizeof(char));
                strcpy(input->cidade, string);
                //printf("CIDADE: %s ", input->cidade);
            }
            help = 1;
            tam_string=0;
        }
        if (caracter == ',' && cont == 3){
            if (char_anterior == ','){
                //printf("null ");
                input->qtt = -1;
            }
            else{
                string[tam_string-1] = '\0';
                input->qtt = atoi(string);
                //printf("QUANTIDADE: %d ", input->qtt);
            }
            help = 1;
            tam_string=0;
        }
        if (caracter == ',' && cont == 4){
            if (char_anterior == ','){
                //printf("null ");
            }
            else{
                string[tam_string-1] = '\0';
                strcpy(input->sigla, string);
                //printf("SIGLA: %s ", input->sigla);
            }
            help = 1;
            tam_string=0;
        }
        if (caracter == ',' && cont == 5){
            if (char_anterior == ','){
                input->marca = NULL;
                //printf("null ");
            }
            else{
                string[tam_string-1] = '\0';
                input->marca = (char*) malloc(tam_string * sizeof(char));
                strcpy(input->marca, string);
                //printf("MARCA: %s ", input->marca);
            }
            help = 1;
            tam_string=0;
        }
        if ( caracter == '\r' && cont == 6){
            if (char_anterior == ','){
                //printf("null ");
                input->modelo = NULL;
            }
            else{
                string[tam_string-1] = '\0';
                input->modelo = (char*) malloc(tam_string * sizeof(char));
                strcpy(input->modelo, string);
                //printf("MODELO: %s ", input->modelo);
            }
            help = 1;
            tam_string=0;
        }
        if (cont == 7){
            //printf("\n");
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
DADAO2 *funcao1_tipo2(const char *line) {
    char caracter;
    char char_anterior = 'c';
    int i=0, tam_string = 1, help=0;
    int cont = 0;
    DADAO2 *input = (DADAO2 *) malloc(sizeof (DADAO2));
    char *string = malloc( tam_string * sizeof(char));
    for (i = 0; i < strlen(line) ; i++){
        caracter = line[i];
        string[tam_string-1] = caracter;
        //printf("%c", caracter);
        if (caracter == ',' && cont == 0){
            string[tam_string-1] = '\0';
            input->id = atoi(string);
            //printf(" ID: %d ", input->id);
            tam_string=0;
            help = 1;
        }
        if (caracter == ',' && cont == 1){
            if (char_anterior == ','){
                input->ano = -1;
                //printf("null ");
            }
            else{
                string[tam_string-1] = '\0';
                input->ano = atoi(string);
                //printf("ANO: %d ", input->ano);
            }
            help = 1;
            tam_string=0;
        }
        if (caracter == ',' && cont == 2){
            if (char_anterior == ','){
                //printf("null ");
                input->cidade = NULL;
            }
            else{
                string[tam_string-1] = '\0';
                input->cidade = (char*) malloc(tam_string * sizeof(char));
                strcpy(input->cidade, string);
                //printf("CIDADE: %s ", input->cidade);
            }
            help = 1;
            tam_string=0;
        }
        if (caracter == ',' && cont == 3){
            if (char_anterior == ','){
                //printf("null ");
                input->qtt = -1;
            }
            else{
                string[tam_string-1] = '\0';
                input->qtt = atoi(string);
                //printf("QUANTIDADE: %d ", input->qtt);
            }
            help = 1;
            tam_string=0;
        }
        if (caracter == ',' && cont == 4){
            if (char_anterior == ','){
                //printf("null ");
            }
            else{
                string[tam_string-1] = '\0';
                strcpy(input->sigla, string);
                //printf("SIGLA: %s ", input->sigla);
            }
            help = 1;
            tam_string=0;
        }
        if (caracter == ',' && cont == 5){
            if (char_anterior == ','){
                //printf("null ");
                input->marca = NULL;
            }
            else{
                string[tam_string-1] = '\0';
                input->marca = (char*) malloc(tam_string * sizeof(char));
                strcpy(input->marca, string);
                //printf("MARCA: %s ", input->marca);
            }
            help = 1;
            tam_string=0;
        }
        if ( caracter == '\r' && cont == 6){
            if (char_anterior == ','){
                //printf("null ");
                input->modelo = NULL;
            }
            else{
                string[tam_string-1] = '\0';
                input->modelo = (char*) malloc(tam_string * sizeof(char));
                strcpy(input->modelo, string);
                //printf("MODELO: %s ", input->modelo);
            }
            help = 1;
            tam_string=0;
        }
        if (cont == 7){
            //printf("\n");
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
void funcao2_tipo1(char nome_entrada[30]){
    FILE *entrada;
    entrada= fopen(nome_entrada, "rb");
   // CABECAO *cabecalho = (CABECAO*) malloc(sizeof(CABECAO));
   // fread(cabecalho, sizeof(CABECAO), 1, entrada);
    fseek(entrada,182, SEEK_SET);
    //char line[1024];
    //fgets(line,1024,entrada);
    int i = 0;
    do{
        fseek(entrada,182 + 97*i, SEEK_SET);
        DADAO *input = (DADAO*) malloc(sizeof(DADAO));
        //removido
        fread(&(input->removido), sizeof(char ), 1 , entrada);
        //prox
        fread(&(input->prox), sizeof(int), 1 , entrada);
        //id
        fread(&(input->id), sizeof(int), 1 , entrada);
        //ano
        fread(&(input->ano), sizeof(int), 1 , entrada);
        //quantidade
        fread(&(input->qtt), sizeof(int), 1 , entrada);
        //sigla
        fread(input->sigla, 2, 1 , entrada);
        //marca,modelo e cidade
        for(int j = 0; j<3;j++){
            char auxc;
            int auxnumero;
            fread(&auxnumero, sizeof(int), 1, entrada);
            fread(&auxc, sizeof(char ), 1 , entrada);
            if (auxc == '0'){
                input->tamCidade = auxnumero;
                input->codC5 = auxc;
                input->cidade = malloc(input->tamCidade * sizeof(char ));
                fread(input->cidade, input->tamCidade,1, entrada);
            }
            if (auxc == '1'){
                input->tamMarca = auxnumero;
                input->codC6 = auxc;
                input->marca = malloc(input->tamMarca * sizeof(char ));
                fread(input->marca, input->tamMarca,1, entrada);
            }
            if (auxc == '2'){
                input->tamModelo = auxnumero;
                input->codC7 = auxc;
                input->modelo = malloc(input->tamModelo * sizeof(char ));
                fread(input->modelo, input->tamModelo,1, entrada);
            }
        }
        if ( input->marca == NULL){
            printf("MARCA DO VEICULO: NAO PREENCHIDO\n");
        }
        else{
            printf("MARCA DO VEICULO: %s\n", input->marca);
        }
        if ( input->modelo == NULL){
            printf("MODELO DO VEICULO: NAO PREENCHIDO\n");
        }
        else{
            printf("MODELO DO VEICULO: %s\n", input->modelo);
        }
        if (input->ano == -1){
            printf("ANO DE FABRICACAO: NAO PREENCHIDO\n");
        }
        else{
            printf("ANO DE FABRICACAO: %d\n", input->ano);
        }
        if ( input->cidade == NULL){
            printf("NOME DA CIDADE: NAO PREENCHIDO\n");
        }
        else{
            printf("NOME DA CIDADE: %s\n", input->cidade);
        }
        if (input->qtt == -1){
            printf("QUANTIDADE DE VEICULOS: NAO PREENCHIDO\n");
        }
        else{
            printf("QUANTIDADE DE VEICULOS: %d\n", input->qtt);
        }
        printf("\n");
        i++;

    }while(!feof(entrada));

    fclose(entrada);
}
void funcao2_tipo2(char nome_entrada[30]){
    FILE *entrada;
    entrada= fopen(nome_entrada, "rb");
    // CABECAO *cabecalho = (CABECAO*) malloc(sizeof(CABECAO));
    // fread(cabecalho, sizeof(CABECAO), 1, entrada);
    fseek(entrada,190, SEEK_SET);
    //char line[1024];
    //fgets(line,1024,entrada);
    int i = 0, somador=0;
    do{
        //fseek(entrada,190 + somador, SEEK_SET);
        DADAO2 *input = (DADAO2*) malloc(sizeof(DADAO2));
        //removido
        fread(&(input->removido), sizeof(char ), 1 , entrada);
        //printf("REMOVIDO %c ", input->removido);
        //tamRegistro
        fread(&(input->tamanhoRegistro), sizeof(int), 1 , entrada);
        //printf("TAMREGISTRO %d ", input->tamanhoRegistro);
        somador = input->tamanhoRegistro ;
        //prox
        if (somador > 0 ){
            fread(&(input->prox), sizeof(long long int), 1 , entrada);
            //printf("Prox %lld ", input->prox);
            somador -= 8;
        }
        //id
        if (somador > 0){
            fread(&(input->id), sizeof(int), 1 , entrada);
            //printf("ID %d ", input->id);
            somador -= 4;
        }
        //ano
        if (somador > 0) {
            fread(&(input->ano), sizeof(int), 1 , entrada);
            //printf("ANO %d ", input->ano);
            somador -= 4;
        }
        //quantidade
        if (somador > 0) {
            fread(&(input->qtt), sizeof(int), 1 , entrada);
            //printf("QTT %d ", input->qtt);
            somador -= 4;
        }
        //sigla
        if (somador > 0) {
            fread(input->sigla, 2, 1 , entrada);
            //printf("SIglaA %s ", input->sigla);
            somador -= 2;
        }

        //marca,modelo e cidade
        while (somador > 0) {
            for (int j = 0; j < 3; j++) {
                char auxc;
                int auxnumero;
                fread(&auxnumero, sizeof(int), 1, entrada);
                //            printf("%d ", auxnumero);
                somador -= 4;
                if ( somador <= 0)
                    break;
                fread(&auxc, sizeof(char), 1, entrada);
                somador -= 1;
                if ( somador <= 0)
                    break;
                //            printf("%c ", auxc);
                if (auxc == '0') {
                    input->tamCidade = auxnumero;
                    input->codC5 = auxc;
                    input->cidade = malloc(input->tamCidade * sizeof(char));
                    fread(input->cidade, input->tamCidade, 1, entrada);
                    //printf("CIDADE %s ", input->cidade);
                    somador -= input->tamCidade;
                    if ( somador <= 0)
                        break;
                }
                if (auxc == '1') {
                    input->tamMarca = auxnumero;
                    input->codC6 = auxc;
                    input->marca = malloc(input->tamMarca * sizeof(char));
                    fread(input->marca, input->tamMarca, 1, entrada);
                    //printf("MARCA %s ", input->marca);
                    somador -= input->tamMarca;
                    if ( somador <= 0)
                        break;
                }
                if (auxc == '2') {
                    input->tamModelo = auxnumero;
                    input->codC7 = auxc;
                    input->modelo = malloc(input->tamModelo * sizeof(char));
                    fread(input->modelo, input->tamModelo, 1, entrada);
                    //printf("MODELO %s ", input->modelo);
                    somador -= input->tamModelo;
                    if ( somador <= 0)
                        break;
                }
            }
        }
        if ( input->marca == NULL){
            printf("MARCA DO VEICULO: NAO PREENCHIDO\n");
        }
        else{
            printf("MARCA DO VEICULO: %s\n", input->marca);
        }
        if ( input->modelo == NULL){
            printf("MODELO DO VEICULO: NAO PREENCHIDO\n");
        }
        else{
            printf("MODELO DO VEICULO: %s\n", input->modelo);
        }
        if (input->ano == -1){
            printf("ANO DE FABRICACAO: NAO PREENCHIDO\n");
        }
        else{
            printf("ANO DE FABRICACAO: %d\n", input->ano);
        }
        if ( input->cidade == NULL){
            printf("NOME DA CIDADE: NAO PREENCHIDO\n");
        }
        else{
            printf("NOME DA CIDADE: %s\n", input->cidade);
        }
        if (input->qtt == -1){
            printf("QUANTIDADE DE VEICULOS: NAO PREENCHIDO\n");
        }
        else{
            printf("QUANTIDADE DE VEICULOS: %d\n", input->qtt);
        }
        printf("\n");
        i++;

    }while(!feof(entrada));

    fclose(entrada);
}

void funcao3_tipo1(char nome_entrada[30], int quantidade){

    char campo[30];
    char variavel[50];
    int ajuda;
    for (int i = 0; i < quantidade; ++i) {
        scanf("%s", campo);
        scan_quote_string(variavel);
        //printf("\n%s e %s\n", str1, str2);
        func3_aux_tipo1(nome_entrada, campo, variavel, quantidade, &ajuda);
    }

}

void func3_aux_tipo1(char nome_entrada[30],char campo[30], char variavel[50], int cont, int *ajuda){
    FILE *entrada;
    entrada= fopen(nome_entrada, "rb");
    // CABECAO *cabecalho = (CABECAO*) malloc(sizeof(CABECAO));
    // fread(cabecalho, sizeof(CABECAO), 1, entrada);
    fseek(entrada,182, SEEK_SET);
    //char line[1024];
    //fgets(line,1024,entrada);
    *ajuda = 2;
    printf("O campo é ;%s; a variavel é ;%s; e a ajuda é ;%d; e o cont;%d;", campo, variavel,*ajuda, cont);
    int i = 0;
    do{
        fseek(entrada,182 + 97*i, SEEK_SET);
        DADAO *input = (DADAO*) malloc(sizeof(DADAO));
        fread(&(input->removido), sizeof(char ), 1 , entrada);
        fread(&(input->prox), sizeof(int), 1 , entrada);
        fread(&(input->id), sizeof(int), 1 , entrada);
        fread(&(input->ano), sizeof(int), 1 , entrada);
        fread(&(input->qtt), sizeof(int), 1 , entrada);
        fread(input->sigla, 2, 1 , entrada);
        for(int j = 0; j<3;j++){
            char auxc;
            int auxnumero;
            fread(&auxnumero, sizeof(int), 1, entrada);
            fread(&auxc, sizeof(char ), 1 , entrada);
            if (auxc == '0'){
                input->tamCidade = auxnumero;
                input->codC5 = auxc;
                input->cidade = malloc(input->tamCidade * sizeof(char ));
                fread(input->cidade, input->tamCidade,1, entrada);
            }
            if (auxc == '1'){
                input->tamMarca = auxnumero;
                input->codC6 = auxc;
                input->marca = malloc(input->tamMarca * sizeof(char ));
                fread(input->marca, input->tamMarca,1, entrada);
            }
            if (auxc == '2'){
                input->tamModelo = auxnumero;
                input->codC7 = auxc;
                input->modelo = malloc(input->tamModelo * sizeof(char ));
                fread(input->modelo, input->tamModelo,1, entrada);
            }
        }

        if ( input->removido == '0') {
            if (strcmp(campo, "id") == 0){
                if (input->id == atoi(variavel)){
                    (*ajuda)++;
                }
            }
            if (strcmp(campo, "ano") == 0){
                if (input->ano == atoi(variavel)){
                    (*ajuda)++;
                }
            }
            if (strcmp(campo, "qtt") == 0){
                if (input->qtt == atoi(variavel)){
                    (*ajuda)++;
                }
            }
            if (strcmp(campo, "sigla") == 0){
                if (strcmp(input->sigla,variavel) == 0){
                    (*ajuda)++;
                }
            }
            if (strcmp(campo, "cidade") == 0){
                if (strcmp(input->cidade,variavel) == 0){
                    (*ajuda)++;
                    printf("O campo é ;%s; a variavel é ;%s; e a ajuda é ;%d;", campo, variavel,*ajuda);

                }
            }
            if (strcmp(campo, "marca") == 0){
                if (strcmp(input->marca,variavel) == 0){
                    (*ajuda)++;
                }
            }
            if (strcmp(campo, "modelo") == 0){
                if (strcmp(input->modelo,variavel) == 0){
                    (*ajuda)++;
                }
            }
            if (*ajuda == cont) {
                if (input->marca == NULL) {
                    printf("MARCA DO VEICULO: NAO PREENCHIDO\n");
                } else {
                    printf("MARCA DO VEICULO: %s\n", input->marca);
                }
                if (input->modelo == NULL) {
                    printf("MODELO DO VEICULO: NAO PREENCHIDO\n");
                } else {
                    printf("MODELO DO VEICULO: %s\n", input->modelo);
                }
                if (input->ano == -1) {
                    printf("ANO DE FABRICACAO: NAO PREENCHIDO\n");
                } else {
                    printf("ANO DE FABRICACAO: %d\n", input->ano);
                }
                if (input->cidade == NULL) {
                    printf("NOME DA CIDADE: NAO PREENCHIDO\n");
                } else {
                    printf("NOME DA CIDADE: %s\n", input->cidade);
                }
                if (input->qtt == -1) {
                    printf("QUANTIDADE DE VEICULOS: NAO PREENCHIDO\n");
                } else {
                    printf("QUANTIDADE DE VEICULOS: %d\n", input->qtt);
                }
                printf("\n");
            }
        }
        i++;

    }while(!feof(entrada));

    fclose(entrada);
}

void funcao3_tipo2(char nome_entrada[30], int quantidade){

}
void binarioNaTela(char*nomeArquivoBinario) { /* Você não precisa entender o código dessa função. */

    /* Use essa função para comparação no run.codes. Lembre-se de ter fechado (fclose) o arquivo anteriormente.
    *  Ela vai abrir de novo para leitura e depois fechar (você não vai perder pontos por isso se usar ela). */

    unsigned long i, cs;
    unsigned char *mb;
    size_t fl;
    FILE *fs;
    if(nomeArquivoBinario == NULL || !(fs = fopen(nomeArquivoBinario, "rb"))) {
        fprintf(stderr, "ERRO AO ESCREVER O BINARIO NA TELA (função binarioNaTela): não foi possível abrir o arquivo que me passou para leitura. Ele existe e você tá passando o nome certo? Você lembrou de fechar ele com fclose depois de usar?\n");
        return;
    }
    fseek(fs, 0, SEEK_END);
    fl = ftell(fs);
    fseek(fs, 0, SEEK_SET);
    mb = (unsigned char *) malloc(fl);
    fread(mb, 1, fl, fs);

    cs = 0;
    for(i = 0; i < fl; i++) {
        cs += (unsigned long) mb[i];
    }
    printf("%lf\n", (cs / (double) 100));
    free(mb);
    fclose(fs);
}

void scan_quote_string(char *str) {

    /*
    *	Use essa função para ler um campo string delimitado entre aspas (").
    *	Chame ela na hora que for ler tal campo. Por exemplo:
    *
    *	A entrada está da seguinte forma:
    *		nomeDoCampo "MARIA DA SILVA"
    *
    *	Para ler isso para as strings já alocadas str1 e str2 do seu programa, você faz:
    *		scanf("%s", str1); // Vai salvar nomeDoCampo em str1
    *		scan_quote_string(str2); // Vai salvar MARIA DA SILVA em str2 (sem as aspas)
    *
    */

    char R;

    while((R = getchar()) != EOF && isspace(R)); // ignorar espaços, \r, \n...

    if(R == 'N' || R == 'n') { // campo NULO
        getchar(); getchar(); getchar(); // ignorar o "ULO" de NULO.
        strcpy(str, ""); // copia string vazia
    } else if(R == '\"') {
        if(scanf("%[^\"]", str) != 1) { // ler até o fechamento das aspas
            strcpy(str, "");
        }
        getchar(); // ignorar aspas fechando
    } else if(R != EOF){ // vc tá tentando ler uma string que não tá entre aspas! Fazer leitura normal %s então, pois deve ser algum inteiro ou algo assim...
        str[0] = R;
        scanf("%s", &str[1]);
    } else { // EOF
        strcpy(str, "");
    }
}