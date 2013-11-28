/*Funcoes sobre a estrutura item */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proj3.h"



Item NOVO()  /*Alocar uma nova string*/
{
	int i;
	
	Item nova = (Item) (malloc((sizeof(char)*(COLUNAS+1)))); /*Alocar nova string*/
	if (nova == NULL)  /*Deteccao de erros no alocamento */
		{
			printf("ERRO INTERNO: Alocacao memoria string");
			exit(0);
		}
	
	/*Inicializacao da string */	
	for(i = 0; i < COLUNAS; i++)
		nova[i] = ESPACO;
	
	nova[i] = '\0';  /*Colocar o caracter terminal*/
	
	return nova;
}


void imprimir(char *string) /*Imprimir a estrutura item */
{
	printf("%s",string);
}





