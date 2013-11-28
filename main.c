/* 3a PARTE PROJECTO - DARIO NASCIMENTO - BERNARDO FIGUEIREDO -  ANDRE GONCALVES */ 


#include <stdio.h>
#include <stdlib.h>
#include "proj3.h"

ptr_no top = NULL; /*Variavel global para a estutura tabuleiro */

int pontuacao = 0;  /*Variavel global para a pontuacao */

int pecas_inteiras[5][6]; /*Matriz para contar as pecas inteiras*/

int numero_pecas_inteiras = 0; /*total de pecas inteiras*/

int lmax(ptr_no topo) /*Determina o numero de linhas ocupada */
{
	int i;
	
	for(i = 0; topo != NULL; topo = linha_baixo(topo))
		i++;
	
	return i;
}



/*Funcoes de manipulacao do tabuleiro top */

void inserir_linha()  /*Inserir linha vazia no topo */
{
	top = inserir_no(top); /*Insere um no vazio */
}

void apagar_linha(ptr_no linha) /*Apagar qualquer linha*/
{
	remove_grandes(linha->acima); /* Apagar as pecas da linha de cima que ocupem a que vamos apagar*/
	apaga_lista(linha->lista_pecas); /* apagar a lista de pecas da linha a apagar*/
	top = apagar_no(linha,top); /*Apaga a linha*/	
}


/*Funcoes de output*/


void imprimir_tabuleiro(ptr_no topo,int Lmax,int pontuacao)
{
	printf("%d\n",Lmax);
	printf("%d\n\n",pontuacao);
	
	while(topo != NULL)
		{
			printf("|");
			imprimir(le_linha(topo)); /*imprimir a estrutura de cada linha */
			printf("| %d\n",Lmax--);
				
			topo = linha_baixo(topo); /*avancar ponteiro*/
		}
	printf(" ----------\n");
}



ptr_no ler() /*Le os caracteres do standard input e devolve o ponteiro onde a peca ficou colocada*/
{		
	int tipo,coordenada;
	char cor;
	ptr_no final; /*guardar a posicao final do tetramino */

	  /*Leitura formatada de uma peca */
		fscanf(stdin,"%d %d %c \n",&tipo, &coordenada, &cor);
		switch(tipo)
		{
			case 1: final = coloca_fig1(cor, coordenada);break;
			case 2: final = coloca_fig2(cor, coordenada);break;
			case 3: final = coloca_fig3(cor, coordenada);break;
			case 4: final = coloca_fig4(cor, coordenada);break;
			case 5: final = coloca_fig5(cor, coordenada);break;
			default :printf("ERRO INTERNO,switch leitura");exit(0);
		}
	return final;
}



int main()
{
	int i, Lmax,total_pecas;
	ptr_no ultima_linha; /*Vai receber a linha acima da jogada realizada */
	
	
	inicia_pecas_inteiras(); /*Iniciar a matriz de contagem*/
		
	scanf("%d\n",&total_pecas); /*Ler total de pecas */
	
	
	for(i = 0; i < total_pecas; i++) /*Ciclo leitura, colocacao, avaliacao */
	{
		ultima_linha = ler();  /*le uma peca e coloca-a, devolve a linha em que foi colocada */
		pontuacao += pontua(ultima_linha); /*Actualiza a pontuacao do jogo */
	}
	
	
	Lmax = lmax(top);  /*Calcula o lmax do tabuleiro apontado por top */
	
	
	imprimir_tabuleiro(top,Lmax,pontuacao); /*Imprimir o tabuleiro top no standard output*/
	
	printf("\n"); /*linha apos o tabuleiro */
	
	
	conta_pecas(top); /*Conta o numero de pecas inteiras no tabuleiro*/
	
	
	printf("%d\n",numero_pecas_inteiras); /*Imprimir o numero total de pecas inteiras*/
	
	imprimir_contagem(); /*Imprimir a contagem de pecas inteiras no final*/
	
	printf("\n"); /*linha apos as pecas inteiras */
	
	imprElim();
	
	return 0;
}



