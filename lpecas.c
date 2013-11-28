#include "proj3.h"
#include <stdlib.h>
#include <stdio.h>


extern int pecas_inteiras[5][6];
extern int numero_pecas_inteiras;

void insere_peca_lista(ptr_no linha,char cor,int formato) /*recebe uma linha e coloca na sua lista +1 peca */
{
	ptr_pecas nova_peca;
			
	nova_peca = (ptr_pecas) malloc(sizeof(struct l_pecas)); /*criar uma nova peca */
		
	nova_peca->cor = cor; /*Inserir a nova peca à cabeca da lista */
	nova_peca->formato = formato;
	nova_peca->next = linha->lista_pecas;
	linha->lista_pecas = nova_peca;
	
}



void remove_grandes(ptr_no linha) /*Apagar da lista todas as pecas que ocupem 2 linhas */
{
	ptr_pecas aux,peca;
	
	if(linha == NULL) /*se a linha que vamos analisar nao existe, sai*/
		return;
	
	peca = linha->lista_pecas; /*carregar lista de pecas da linha */
	
	if(peca == NULL) /*lista vazia?*/
		return;
	
	while(peca != NULL && peca->formato != 1) /*Enquanto a peca a cabeca da lista for para eliminar*/
		{
		/*	printf("apagar GRANDE formato %d, cor %c\n",peca->formato,peca->cor); */
			aux = peca;
			peca = peca->next;
			free(aux);
		}
	
	linha->lista_pecas = peca; /*Ja nao mexemos mais na cabeca da lista, vamos actualiza-la */
	
	while(peca != NULL) /*percorrer a lista */
		{
			aux = peca->next;
			if(aux != NULL && aux->formato != 1)
				{
				/*	printf("apagar GRANDE formato %d, cor %c\n",aux->formato,aux->cor);	*/
					peca->next = aux->next;
					free(aux);
				}
			peca = peca->next;
			
		}
}


/*LISTA DE PECAS */
void apaga_lista(ptr_pecas lista) /*libertar toda a lista*/
{
	
	ptr_pecas aux; /*Ponteiro auxiliar para nao perder referencia */
	
	if(lista == NULL)
		return;
		
	aux = lista->next;
	
	while(aux != NULL)
		{
		/*	printf("apagar o formato %d, cor %c\n",lista->formato,lista->cor); */
			free(lista);
			lista = aux;
			aux = lista->next;
		}
}





/*--------- TRATA PECAS NO FINAL --------------*/
/* - Contar o numero de pecas completas
 * - Contar por cada formato e cor */

/* Tabela de 5x6, 5 figuras, cada uma com 6 cores
 * 	B G O R V Y
 * 1 
 * 2
 * 3
 * 4
 * 5

*/


void inicia_pecas_inteiras()
{
	int i,j;
	for(i = 0, j = 0; i < 5; i++)
		while(j < 6)
			{
				pecas_inteiras[i][j] = 0;
				j++;
			}
}

	



/*Recebe a linha, percorre a lista e conta/organiza as pecas inteiras */

void conta_pecas(ptr_no topo)
{
	ptr_pecas lista;
	int formato,cor_num;
	char cor;
	
	while(topo != NULL) /*Percorrer todo o tabuleiro*/
	{
		lista = topo->lista_pecas; /*abrir a lista de pecas */
	
		while(lista != NULL) /*Percorrer a lista toda */
		{
			formato = lista->formato -1 ; /*ler formato da peca e converter para 0 a 4*/
			cor = lista->cor; /*ler a cor da peca e converter na coluna correcta*/
		
			/* printf("contar o formato: %d    cor %c\n\n",formato,cor); */
			switch(cor){						
				case 'B': cor_num = 0;break;			/*codificar a cor*/
				case 'G': cor_num = 1;break;
				case 'O': cor_num = 2;break;
				case 'R': cor_num = 3;break;
				case 'V': cor_num = 4;break;
				case 'Y': cor_num = 5;break;
				default : printf("Erro conta_pecas: cor invalida");exit(0);
				}		
			pecas_inteiras[formato][cor_num] += 1;		
			numero_pecas_inteiras++; /*mais uma peca inteira*/
			lista = lista->next; /*avanca na lista*/
		}
	
	topo = linha_baixo(topo);
	}
}

void imprimir_contagem() /*le o pecas_inteiras e interpreta */
{
	int formato,cor_num,contadas;
	char cor;
	
	for(formato = cor_num = 0; formato< 6; formato++)
	{
		for(cor_num = 0; cor_num < 6; cor_num++)
		{
			contadas = 	pecas_inteiras[formato][cor_num]; /*ler o numero de vezes que a peca existe */
	
			if(contadas == 0) /*se nao existe nenhuma inteira, vamos ver outra peca */
				continue;
			
			switch(cor_num){  				/*descodificar a cor*/
				case 0: cor = 'B';break;
				case 1: cor = 'G';break;
				case 2: cor = 'O';break;
				case 3: cor = 'R';break;
				case 4: cor = 'V';break;
				case 5: cor = 'Y';break;
				default : printf("Erro imprimir_contagem: erro interno");exit(0);
				}
			while(contadas-- != 0) /*imprimir tantas vezes quantas as que a peca existe*/
				printf("%d %c\n",formato+1,cor);	
			}
	}
}

