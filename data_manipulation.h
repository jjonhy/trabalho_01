
#ifndef DATA_MANIPULATION_H
#define DATA_MANIPULATION_H

//definindo como é o registro de cabeçalho 1
typedef struct cabecalho
{
	//campos de tamanho fixo
	char status;
	int topo;
	char descricao[40];
	char desC1[22], desC2[19], desC3[24], desC4[8];
	char codC5, desC5[16], codC6, desC6[18], codC7, desC7[19];
	int proxRRN, nroRegRem;
}cab1;

//definindo como é o registro de cabeçalho 2

typedef struct cabeca
{
	//campos de tamanho fixo
	char status;
	long long int topo;
	char descricao[40];
	char desC1[22], desC2[19], desC3[24], desC4[8];
	char codC5, desC5[16], codC6, desC6[18], codC7, desC7[19];
	long long int proxByteOffset;
	int nroRegRem;
}cab2;


//registro do arquivo tipo 1
typedef struct arquivo1
{
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
	
}reg1;

//registro do arquivo tipo 2
typedef struct arquivo2
{
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
		
	
	
}reg2;

//inicializando os cabecalhos, 1 e 2
cab1 *set_cabecalho1();
cab2 *set_cabecalho2();

//realiza a função nro1
void function1(char *file_type, char* in_file, char* out_file);


#endif
