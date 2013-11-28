/*trata.c -Funcoes processar o tabuleiro (fazer a avaliacao das pontuacoes) */
#include <stdlib.h>
#include "proj3.h"

int conta_cores(ptr_no linha)  /*Conta o numero de cores de uma linha, devolve 0 se espacos em branco, 1 se 1 só cor e 2 se 2 ou mais cores */
{
	int posicao,duas_cores = 1;  
	char pri_cor,cor_lida;  /*primeira cor e cor lida */
	
	/*Mal existe um espaco, devolve 0 */
	/*Memoriza a 1ª cor lida */
	/*Compara sempre com essa cor */
	/*   - SE IGUAL, ve a próxima cor
	 * 	 - SE DIFERENTE, acende a flag de que há 2 cores e acaba de ver se ha espacos */
	
	posicao = 1;
	
	if(le_da_coluna(linha,posicao) == ESPACO) /*A 1a linha comeca logo pelo vazio*/
		return 0;
	else
		pri_cor = le_da_coluna(linha,posicao); /*A 1a posicao vai ser a 1a cor lida */
		
		for(posicao = 2; posicao <= COLUNAS; posicao++)
		{
			cor_lida = le_da_coluna(linha,posicao);
			if(cor_lida == ESPACO)
				return 0;
			else if(cor_lida != pri_cor)
				duas_cores = 2;
		}
		
	return duas_cores;
}


/*--------------------- funcao pontua --------------------- */


int pontua(ptr_no ponteiro) /*Recebe o tabuleiro, elimina as devidas linhas e devolve quantos pontos fez */ 
{
	int cores, i, pontos = 0;
	
	ptr_no baixo,aux; /*para não perder a referencia à linha seguinte */
	
	
	i = 0; /*Contador de linhas processadas, deve processar 2 linhas */
	

	while(ponteiro != NULL && i < 2) /*Enquanto nao estivermos no final vamos verificar as 2 linhas modificadas na colocacao da peca */
	{
		cores = conta_cores(ponteiro);
		
		switch(cores)
		{
			case 0: baixo = linha_baixo(ponteiro); break; /*Há espacos em branco */
			
			case 1 : 		/*Linha monocor */
				pontos += 3;

				if(linha_cima(ponteiro) != NULL){  /*Apagar a adjacente superior */
					trataLinhas(linha_cima(ponteiro));
					apagar_linha(linha_cima(ponteiro));
				}
				baixo = linha_baixo(ponteiro); /*Nao perder referencia */
				
				while(baixo != NULL && conta_cores(baixo) == 1) /*Enquanto a linha debaixo existir e for monocor */
				{
					pontos += 3; /*Por cada linha monocor eliminada ganhamos 3 pontos */
					aux = baixo; /*ponteiro para a linha a apagar */
					baixo = linha_baixo(baixo); /*mantem a referencia para a linha seguinte*/
					trataLinhas(aux);
					apagar_linha(aux); /*Apaga a linha monocor */
				}
							
				if(baixo != NULL)   /*Se adjacente inferior existir, vamos apagá-la*/
					{
						if(conta_cores(baixo) == 2) /*É uma linha multicor */
							pontos++; /*então há pontos a atribuir */

						baixo = linha_baixo(baixo);  /*baixo desce mais para nao perdermos referencia */
						trataLinhas(linha_baixo(ponteiro));
						apagar_linha(linha_baixo(ponteiro));
					}				
				trataLinhas(ponteiro);
				apagar_linha(ponteiro);
				break; 
				
				
			case 2 : /*Multicor */
				pontos++;
				baixo = linha_baixo(ponteiro); /*Guardar o ponteiro abaixo*/
				trataLinhas(ponteiro);
				apagar_linha(ponteiro); /*Apaga uma linha */
				
				break; 
			}
		
		ponteiro = baixo; /*avanca o ponteiro*/
		i++; /*Acabamos de processar +1 linha */
	}
	
	return pontos; /*Devolve os pontos ganhos na avaliacao desta jogada */
}
				





