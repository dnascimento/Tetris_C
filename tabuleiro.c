#include <stdio.h>
#include <stdlib.h>
#include "proj3.h"


/*O tabuleiro é uma lista biligada de "no_linha" compostos        [acima]
 * 																 [conteudo]
 * 																  [abaixo]*/

/*As if realizadas aos ponteiros recebidos tem custos computacionais 
 * mas tem em vista tornar o programa mais estavel ao detectar erros de ponteiros, abortando o programa */


ptr_no criar_no() /*Alocacao do bi-no composto*/
{
	ptr_no novo; /*cria um ponteiro para o novo nó */
	
	novo = (ptr_no) malloc (sizeof(struct no_linha));
	
	novo->conteudo = NOVO();  /*define uma linha vazia */
	novo->lista_pecas = NULL; /*Lista vazia de pecas colocadas */
	novo->abaixo = NULL; /*Apontar para baixo para NULL */
	novo->acima = NULL; /*Apontar para cima para NULL */
	
	return novo;
}


ptr_no inserir_no(ptr_no topo) /*Recebe um ponteiro o topo, insere o elemento a frente do no  e devolve o ponteiro para o novo topo*/
{
	ptr_no novo;
	
	novo = criar_no(); /*Cria um novo nó com a estrutura definida*/
	
	if(topo == NULL) /*lista vazia*/
		novo->abaixo = topo; /*cria a 1ª linha */
	
	else /*inserir à cabeça da linha */
		{
			topo->acima = novo;
			novo->abaixo = topo;
		}
		
	topo = novo;  /*Actualizar o topo */
	
	return topo; /*devolve um ponteiro para o novo topo */
}


ptr_no apagar_no(ptr_no linha,ptr_no topo)  /*retorna o ponteiro do topo da lista caso tenha alterado ou NULL caso contrário */
{
	ptr_no novo_topo = NULL;
	
	if(linha == NULL)
	{
		printf("ERRO INTERNO: A Lista está vazia!");
		exit(0);
	}
	
	if(linha->acima == NULL) /*Estamos no topo*/
		{
			novo_topo = linha->abaixo; /*Actualizar o topo*/
			if(linha->abaixo != NULL)
				linha->abaixo->acima = NULL; /*colocar o ponteiro para cima do no de baixo para NULL*/
		}
		
	else if(linha->abaixo == NULL) /*Estamos na base*/
		{
			linha->acima->abaixo = NULL; /*Nova base */
			novo_topo = topo;
		}
		
		else /*Linhas do meio*/	
		{
			linha->acima->abaixo = linha->abaixo; /*Ligar a celula de cima à futura debaixo */
			linha->abaixo->acima = linha->acima; /*Ligar a celula de baixo à que lhe ficará acima */
			novo_topo = topo;  /* o topo mantem-se */
		}
	
	/*Temos todos os ponteiros seguros*/
	
	free(linha->conteudo); /*Apagar o conteudo da linha */
	free (linha); /*Libertar o conteudo de linha*/
		
	return novo_topo; /*Topo se actualizou, NULL caso não tenha alterado o topo*/
	
}
 

	
/*--------- Manipular a lista como um tabuleiro dinamico -------- */


/*Deslocamento na lista como se fosse uma tabela */


ptr_no linha_baixo(ptr_no linha)
{
	if(linha == NULL)
	{
		printf("ERRO INTERNO_tabuleiro: Linha_baixo de um NULL");
		exit(0);
	}
	return linha->abaixo;
}

ptr_no linha_cima(ptr_no linha)
{
	if(linha == NULL)
	{
		printf("ERRO INTERNO_tabuleiro: Linha_cima de um NULL");
		exit(0);
	}
	return linha->acima;
}



/*Leitura e escrita de uma lista de items */
void escreve_linha(ptr_no linha,Item item)
{
	if(linha == NULL)
	{
		printf("ERRO INTERNO_tabuleiro: escrever linha num NULL");
		exit(0);
	}
	linha->conteudo = item;
}

Item le_linha(ptr_no linha)
{
	if(linha == NULL)
	{
		printf("ERRO INTERNO_tabuleiro: Ler linha de um NULL");
		exit(0);
	}
	return linha->conteudo;
}


/*Leitura/Escrita de uma lista de strings */

/*Escrever uma letra na coluna da linha apontada */
void escreve_na_coluna(ptr_no linha,int coluna,char letra)
{
	if(linha == NULL)
	{
		printf("ERRO INTERNO_tabuleiro: escrever na coluna de um NULL");
		exit(0);
	}
	linha->conteudo[coluna-1] = letra;
}

/*Ler o valor a letra da coluna da linha apontada*/
char le_da_coluna(ptr_no linha,int coluna)
{
	if(linha == NULL)
	{
		printf("ERRO INTERNO_tabuleiro: Ler da coluna de um NULL");
		exit(0);
	}
	return linha->conteudo[coluna-1];
}























