#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proj3.h"


static list head=NULL;											/*inicializa a variavel que aponta para a cabeça da lista*/

/*Funçao que guarda uma linha, ja sem espaços, numa lista. Esta funcao cria um no e insere-o ja ordenadamente*/
void insereElim(char* lin){
	list aux=head;
	
	list lt = (list)malloc(sizeof(struct elim));							/*formar o novo no da lista*/
	lt->linha=(char*)malloc(sizeof(char)*(strlen(lin)+1));
	
	strcpy(lt->linha, lin);
	if(aux==NULL || (strcmp(aux->linha,lt->linha))>0){			/*caso para as pessas que ficam logo na 1ª posiçao: head=null ou head<lt*/
		lt->next=head;
		head=lt;
		return;
	}
		
	while(aux->next!=NULL){									/*Inserir o novo nó no meio da lista*/
		if((strcmp(aux->next->linha,lt->linha)>0)){
			lt->next=aux->next;
			aux->next=lt;
			return;
		}
		aux=aux->next;
	}
	
	lt->next=aux->next;										/*Inserir na ultima posicao.*/
	aux->next=lt;
}

/*Funcao que retira os espaços em branco das linhas*/
void trataLinhas(ptr_no lin){
	int i,j;
	char ln[20];
	
	strcpy(ln, lin->conteudo);
	
	for(i=j=0; ln[i]!='\0';i++)								/*Percorre-se o vector e se o caracter for espaço nao se incrementa o j e nao se escreve o espaço*/
		if(ln[i]!= ' ')
			ln[j++]=ln[i];
	ln[j]='\0';
	
	insereElim(ln);
}

/*Funçao que retorna o tamanho da lista.*/
int listLength(){
	list aux=head;
	int length=0;
	
	while(aux!=NULL){					/*percorrer a lista e incrementar uma variavel*/
		length++;
		aux=aux->next;
	}
	
	return length;
}

/*Funçao que vai achar a mediana e imprimi-la no stdout*/
void imprElim(){
	int x=1;
	list aux=head;
	int mediana=listLength();

	if(mediana==0){													/*Se durante o jogo nao foram eliminadas linhas é retornada a mensagem: No Eliminations*/
		printf("No eliminations\n");
		return;
	}
	
	if((mediana%2)==1)												/*Para o caso de o numero de linhas ser impar*/
		mediana=(mediana/2)+1;
	else
		mediana=mediana/2;											/*O numero de linhas é par*/
	
	while(x!=mediana){												/*Procurar a mediana*/
		aux=aux->next;
		x++;
	}
		
	printf("%s\n",aux->linha);										/*Imprimir a mediana*/
}
