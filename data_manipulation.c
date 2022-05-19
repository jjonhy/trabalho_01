#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "data_manipulation.h"

char *xstrtok(line, delims)
char *line, *delims;
{
static char *saveline = NULL;
char *p;
int n;

if(line != NULL)
   saveline = line;

/*
*see if we have reached the end of the line
*/
if(saveline == NULL || *saveline == '\0')
   return(NULL);
/*
*return the number of characters that aren't delims
*/
n = strcspn(saveline, delims);
p = saveline; /*save start of this token*/

saveline += n; /*bump past the delim*/

if(*saveline != '\0') /*trash the delim if necessary*/
   *saveline++ = '\0';

return(p);
}


//separa o conteudo em campos
char* getfield(char* line, int num)
{
   char* tok;
    for (tok = xstrtok(line, ",");num--;tok = xstrtok(NULL, ",\n"))
    {
        if (num == 0)
            return tok;
    }
    return NULL;
}


//inicializa o registro de cabeçalho1
cab1 *set_cabecalho1()
{
	//criando e alocando espaço para o registro
	cab1 *cab_return;
	cab_return = (cab1*)malloc(sizeof(cab1));
	
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
	cab_return->proxRRN = 0;
	cab_return->nroRegRem = 0;
	
	
	return cab_return;
}

//inicializa o registro de cabeçalho1
cab2 *set_cabecalho2()
{
	//criando e alocando espaço para o registro
	cab2 *cab_return;
	cab_return = (cab2*)malloc(sizeof(cab2));
	
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


//verifica se existe o arquivo de nome indicado
bool file_exists (char *file_name)
{
	struct stat buffer;   
return (stat(file_name, &buffer) == 0);
}

//função ainda n foi terminada, n tirei os \0 ao fim da string para poder testar se está copiando com printf
void function1(char *file_type, char* in_file, char* out_file)
{
	if(strcmp(file_type,"tipo1")==0)
	{
		if(!file_exists(in_file))
			return;
			
		FILE* write_arc = fopen(out_file, "w+b");
		FILE* read_arc = fopen(in_file,"r");
		
		if(!write_arc || !read_arc)
		{
			return;
		}
		else
		{
			//inicia as variaveis e o cabeçalho
			cab1 *cabecalho = set_cabecalho1();
			char line[1024];
			
			//removendo a primeira linha
			fgets(line,1024,read_arc);
			
			//lendo o arquivo até o fim
			while(fgets(line,1024,read_arc))
			{
				reg1 *input = (reg1*)malloc(sizeof(reg1*));
				
				
				const char* temp2;
				//id
				char* temp = strdup(line);
				input->id = atoi(getfield(temp,1));
				printf("%d ", input->id);
			
				//ano
				temp = strdup(line);
				input->ano = atoi(getfield(temp,2));
				if(input->ano==0)
				input->ano = -1;
				printf("%d ", input->ano);
			
				//cidade
				//ta dando erro as vzs
				temp = strdup(line);
			   	char* temp_field = strdup(getfield(temp,3));
			   	input->tamCidade = strlen(temp_field);
			   	if(input->tamCidade==0)
			   	{
					input->tamCidade = -1;
					input->cidade = NULL;		   		
				}
				else
				{
					input->cidade = malloc((input->tamCidade+1)*sizeof(char*));
					strcpy(input->cidade,temp_field);
				}
					
				if(input->cidade
				)
					printf("(%s:%d) ",input->cidade,input->tamCidade);					
				
				

				//a partir daqui não foi finalizado
				temp = strdup(line);			
				printf("%s ", getfield(temp,4));

				temp = strdup(line);
				printf("%s ", getfield(temp,5));
				
				temp = strdup(line);
				printf("%s ", getfield(temp,6));
				
				temp = strdup(line);
				printf("%s\n", getfield(temp,7));
				}	
			
			
			
			fclose(write_arc);
			fclose(read_arc);
		}
	}
		
	
}
