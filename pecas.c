/*pecas.c : funcoes responsaveis pela colocacao de cada peca */

#include "proj3.h"
#include <stdlib.h>
extern ptr_no top; /*Variavel global */


/*Funcoes para as peças*/


/* ---------------------------- FIG 1 --------------------------*/

int vazia_fig1(ptr_no linha,int coluna)  /*devolve 1 se a linha TEM espaco para colocar o tetra*/
{
	int i, vazia = 1;
	
	for(i = 0; i < 4; i++,coluna++)    /*verifica se as posicoes estão todas livres*/
		if(le_da_coluna(linha,coluna) != ESPACO)
				vazia = 0;          
	return vazia;
}


ptr_no coloca_fig1(char cor, int coluna) 
{	
	int i;	
	ptr_no ponteiro = top;
		
	if(ponteiro == NULL || vazia_fig1(ponteiro,coluna) == 0)  /*Lista vazia? o topo está logo ocupado? */
	{
		inserir_linha();
		ponteiro = top;     /*vai escrever na nova linha */
	}   
	else	
		while(linha_baixo(ponteiro) != NULL && vazia_fig1(linha_baixo(ponteiro),coluna))  /*Enquanto não estamos na base e a linha seguinte não está ocupada*/
			ponteiro = linha_baixo(ponteiro); /*faz o ponteiro descer 1 linha */

	/*Neste momento ou temos espaco em branco para escrever ou chegamos à base, vamos escrever */
	
	insere_peca_lista(ponteiro,cor,1); /*adicionar a peca a lista de pecas desta linha */
	
	for(i = 0;i < 4; i++,coluna++)
		escreve_na_coluna(ponteiro,coluna,cor);
		
	return ponteiro; /*Modificou a linha ponteiro */
}
		
		
		
/*----------------------- FIGURA 2 ------------------- */

int vazia_fig2(ptr_no linha,int coluna)  /*devolve 1 se a linha TEM espaco para colocar o tetra*/
{
	int i, vazia = 1;
	
	for(i = 0; i < 2; i++,coluna++)    /*verifica se as posicoes estão todas livres*/
		if(le_da_coluna(linha,coluna) != ESPACO)
				vazia = 0;            
	return vazia;
}

ptr_no coloca_fig2(char cor, int coluna) 
{	
	int i,coluna_l2;	
	ptr_no final, ponteiro = top;
		
	if(ponteiro == NULL || vazia_fig2(ponteiro,coluna) == 0)   /*Lista vazia? ou  o topo está logo ocupado? */
		{
			inserir_linha();
			inserir_linha();
			ponteiro = top;     
		}
	else if(linha_baixo(ponteiro) == NULL || vazia_fig2(linha_baixo(ponteiro),coluna) == 0)  /*A 2ª coluna está ocupada ou nao existe */
		{
			inserir_linha();
			ponteiro = top;
		}
		else	
			{
				while(linha_baixo(ponteiro) != NULL && vazia_fig2(linha_baixo(ponteiro),coluna))  /*Enquanto não estamos na base e podemos colocar na linha seguinte*/
					ponteiro = linha_baixo(ponteiro); /*faz o ponteiro descer 1 linha */
				
				ponteiro = linha_cima(ponteiro);  /*Selecciona a linha do quadrado superior esquerdo */
			}
		
	/*Neste momento ou temos espaco em branco para escrever ou chegamos à base, vamos escrever comecando no canto superior esquerdo */
	
	final = ponteiro;  /*guarda o ponteiro para a linha do canto superior esquerdo */
	
	coluna_l2 = coluna; /*Fazer uma cópia da coluna para evitar decrementa-la para escrever a 2a linha */
	
	for(i = 0;i < 2; i++,coluna++)  /*Escreve a 1a linha */
		escreve_na_coluna(ponteiro,coluna,cor);
		
	ponteiro = linha_baixo(ponteiro);
	
	for(i = 0;i < 2; i++,coluna_l2++) /*Escreve a 2a linha */
		escreve_na_coluna(ponteiro,coluna_l2,cor);
	
	insere_peca_lista(final,cor,2); /*adicionar a peca a lista de pecas desta linha */
	return final;
		
}





/*------------------------------------------------------- FIGURA 3 -----------------------------------------------------*/

int vazia_fig3_superior(ptr_no linha,int coluna)  /*devolve 1 se a linha TEM espaco para colocar o tetra*/
{
	int i, vazia = 1;
		
	for(i = 0; i < 2; i++,coluna++)    /*verifica se as posicoes estão todas livres*/
			if(le_da_coluna(linha,coluna) != ESPACO)
				vazia = 0;            
	return vazia;
}


int vazia_fig3_base(ptr_no linha,int coluna)  /*devolve 1 se a linha TEM espaco para colocar o tetra*/
{
	int i, vazia = 1;
	
	coluna++;
	
	for(i = 0; i < 2; i++,coluna++)    /*verifica se as posicoes estão todas livres*/
		if(le_da_coluna(linha,coluna) != ESPACO)
				vazia = 0;
	
	return vazia;
	
}





ptr_no coloca_fig3(char cor, int coluna) 
{	
	int i,coluna_l2;
	ptr_no final,ponteiro = top;
	
	if(ponteiro == NULL || vazia_fig3_base(ponteiro,coluna) == 0)   /*Lista vazia? ou o topo está logo ocupado? */
		{
			inserir_linha();
			inserir_linha();
			ponteiro = top;     
		}
	else if(linha_baixo(ponteiro) == NULL || vazia_fig3_base(linha_baixo(ponteiro),coluna) == 0 || vazia_fig3_superior(ponteiro,coluna) == 0)  /* Não há espaco para colocar nas 2 primeiras linhas? */
		{
			inserir_linha();
			ponteiro = top;
		}
		else
			while(linha_baixo(ponteiro) != NULL && linha_baixo(linha_baixo(ponteiro)) != NULL && vazia_fig3_base(linha_baixo(linha_baixo(ponteiro)),coluna) && vazia_fig3_superior(linha_baixo(ponteiro),coluna))  /*Enquanto não estamos na base e podemos colocar na linha seguinte*/
				ponteiro = linha_baixo(ponteiro); /*faz o ponteiro descer 1 linha */
			
		
	/*Neste momento ou temos espaco em branco para escrever ou chegamos à base, vamos escrever comecando no canto superior esquerdo */
	
	final = ponteiro;  /*guarda o ponteiro para a linha do canto superior esquerdo */
	
	coluna_l2 = coluna+1; /*Seleccionar a coluna para a 2a linha */
	
	for(i = 0;i < 2; i++,coluna++)  /*Escreve a 1a linha */
		escreve_na_coluna(ponteiro,coluna,cor);
		
	ponteiro = linha_baixo(ponteiro);
	
	for(i = 0;i < 2; i++,coluna_l2++) /*Escreve a 2a linha */
		escreve_na_coluna(ponteiro,coluna_l2,cor);
		
	insere_peca_lista(final,cor,3); /*adicionar a peca a lista de pecas desta linha */
	return final;
		
}



/* ------------------ FIGURA 4 ----------------- */
int vazia_fig4_superior(ptr_no linha,int coluna)  /*devolve 1 se a linha TEM espaco para colocar o tetra*/
{
	int i, vazia = 1;
		
	for(i = 0; i < 3; i++,coluna++)    /*verifica se as posicoes estão todas livres*/
		if(le_da_coluna(linha,coluna) != ESPACO)
				vazia = 0;            
	return vazia;
}


int vazia_fig4_base(ptr_no linha,int coluna)  /*devolve 1 se a linha TEM espaco para colocar a base do tetra*/
{
	int vazia = 1;
	
	if(le_da_coluna(linha,++coluna) != ESPACO)
			vazia = 0;           
	return vazia;
}





ptr_no coloca_fig4(char cor, int coluna) 
{	
	int i,coluna_l2;
	ptr_no final, ponteiro = top;
	
	if(ponteiro == NULL || vazia_fig4_base(ponteiro,coluna) == 0)   /*Lista vazia? ou o topo está logo ocupado? */
		{
			inserir_linha();
			inserir_linha();
			ponteiro = top;     
		}
	else if(linha_baixo(ponteiro) == NULL || vazia_fig4_base(linha_baixo(ponteiro),coluna) == 0 || vazia_fig4_superior(ponteiro,coluna) == 0)  /* Não há espaco para colocar nas 2 primeiras linhas? */
		{
			inserir_linha();
			ponteiro = top;
		}
		else	
			while(linha_baixo(ponteiro) != NULL && linha_baixo(linha_baixo(ponteiro)) != NULL && vazia_fig4_base(linha_baixo(linha_baixo(ponteiro)),coluna) && vazia_fig4_superior(linha_baixo(ponteiro),coluna))  /*Enquanto não estamos na base e a linha seguinte não está ocupada*/
				ponteiro = linha_baixo(ponteiro); /*faz o ponteiro descer 1 linha */
		
	/*Neste momento ou temos espaco em branco para escrever ou chegamos à base, vamos escrever comecando no canto superior esquerdo */
	
	final = ponteiro;  /*guarda o ponteiro para a linha do canto superior esquerdo */
	
	coluna_l2 = coluna+1; /*Seleccionar a coluna para a 2a linha */
	
	for(i = 0;i < 3; i++,coluna++)  /*Escreve a 1a linha */
		escreve_na_coluna(ponteiro,coluna,cor);
		
	ponteiro = linha_baixo(ponteiro);
	
	escreve_na_coluna(ponteiro,coluna_l2,cor);/*Escreve a 2a linha */
	
	insere_peca_lista(final,cor,4); /*adicionar a peca a lista de pecas desta linha */
	
	return final;
}




/* --------------------- FIGURA 5 ------------------------- */
int vazia_fig5_superior(ptr_no linha,int coluna)  /*devolve 1 se a linha TEM espaco para colocar o tetra*/
{
	int i, vazia = 1;
		
	for(i = 0; i < 3; i++,coluna++)    /*verifica se as posicoes estão todas livres*/
		if(le_da_coluna(linha,coluna) != ESPACO)
				vazia = 0;            
	return vazia;
}


int vazia_fig5_base(ptr_no linha,int coluna)  /*devolve 1 se a linha TEM espaco para colocar a base do tetra*/
{
	int vazia = 1;
	
	if(le_da_coluna(linha,coluna) != ESPACO)
			vazia = 0;           
	return vazia;
}





ptr_no coloca_fig5(char cor, int coluna) 
{	
	int i,coluna_l2;
	ptr_no final,ponteiro = top;
	
	if(ponteiro == NULL || vazia_fig5_base(ponteiro,coluna) == 0)   /*Lista vazia? ou o topo está logo ocupado? */
		{
			inserir_linha();
			inserir_linha();
			ponteiro = top;     
		}
	else if(linha_baixo(ponteiro) == NULL || vazia_fig5_base(linha_baixo(ponteiro),coluna) == 0 || vazia_fig5_superior(ponteiro,coluna) == 0)  /* Não há espaco para colocar nas 2 primeiras linhas? */
		{
			inserir_linha();
			ponteiro = top;
		}
		else	
			while(linha_baixo(ponteiro) != NULL && linha_baixo(linha_baixo(ponteiro)) != NULL && vazia_fig5_base(linha_baixo(linha_baixo(ponteiro)),coluna) && vazia_fig5_superior(linha_baixo(ponteiro),coluna))  /*Enquanto não estamos na base e a linha seguinte não está ocupada*/
				ponteiro = linha_baixo(ponteiro); /*faz o ponteiro descer 1 linha */
		
	/*Neste momento ou temos espaco em branco para escrever ou chegamos à base, vamos escrever comecando no canto superior esquerdo */
	
	final = ponteiro;  /*guarda o ponteiro para a linha do canto superior esquerdo */
	
	coluna_l2 = coluna; /*Seleccionar a coluna para a 2a linha */
	
	for(i = 0;i < 3; i++,coluna++)  /*Escreve a 1a linha */
		escreve_na_coluna(ponteiro,coluna,cor);
		
	ponteiro = linha_baixo(ponteiro);
	
	escreve_na_coluna(ponteiro,coluna_l2,cor);/*Escreve a 2a linha */
	
	insere_peca_lista(final,cor,5); /*adicionar a peca a lista de pecas desta linha */
	
	return final;
}



