/* 3a PARTE PROJECTO - DARIO NASCIMENTO - BERNARDO FIGUEIREDO -  ANDRE GONCALVES */ 


#define COLUNAS 10
#define ESPACO ' '



/*Definicao do item */

typedef char *Item;


/*-------------- Definicao do l_pecas ---------------- */
/*lista de pecas em cada linha */

typedef struct l_pecas *ptr_pecas; /*ponteiro para as pecas */

struct l_pecas
{
	char cor;
	int formato;
	ptr_pecas next; /*ponteiro para peca seguinte */
};


/*---------------------Estrutura no_linha--------------------------*/

typedef struct no_linha *ptr_no;  /*Define ptr_no como um ponteiro para o tipo no_linha */

/*Definir a estrutura linha */

struct no_linha
{
	ptr_no acima;  /*Aponta para o nó anterior*/
	Item conteudo;  /*Uma linha é um conteudo do tipo Item pertencente à estrutura no*/
	ptr_pecas lista_pecas; /*ponteiro para a lista de pecas que cada linha vai ter */
	ptr_no abaixo;  /*Ponteiro para o próximo nó_linha */
};

/*-------------------------------Lista de linhas apagadas -----------------------*/

typedef struct elim{
	char* linha;
	struct elim* next;
}*list;


/*--------- Funcoes da lista de pecas --------------------*/
void remove_grandes(ptr_no linha);
void apaga_lista(ptr_pecas lista);
void insere_peca_lista(ptr_no linha,char cor,int formato);
void inicia_pecas_inteiras();
void imprimir_contagem();
void conta_pecas(ptr_no topo);

/*-----------------Funcoes do item ------------------------------------*/

char *NOVO();

void imprimir(char *string);

/*-----------------Funcões do tabuleiro----------------------------- */

ptr_no inserir_no(ptr_no topo); /*Adicionar um nó com elemento no conteudo*/

ptr_no apagar_no(ptr_no linha,ptr_no topo);               /*apagar o no apontado*/

void escreve_na_coluna(ptr_no linha,int coluna,char letra); /*escrever numa posicao do vector da linha */

char le_da_coluna(ptr_no linha,int coluna);                /*Ler o caracter na posicao coluna da string da linha */

ptr_no linha_cima(ptr_no linha);            /*Devolve um ponteiro para a linha acima */

ptr_no linha_baixo(ptr_no linha);          /*Devolve um ponteiro para a linha abaixp */


Item le_linha(ptr_no linha);            /*Devolve a string completa*/

void escreve_linha(ptr_no linha,Item item);  /*Escreve uma string completa */



/*--------------Funcoes do Main -----------------------------------*/
void inserir_linha();  /*Inserir uma linha em branco no topo */

void apagar_linha(ptr_no linha);  /*Apagar a linha apontada por "linha" e actualizar topo*/


/* -------------- Funcoes de tetras --------------------------- */
ptr_no coloca_fig1(char cor, int coluna);

ptr_no coloca_fig2(char cor, int coluna);

ptr_no coloca_fig3(char cor, int coluna);

ptr_no coloca_fig4(char cor, int coluna);

ptr_no coloca_fig5(char cor, int coluna);


/*--------------- Funcoes trata --------------------------- */

int pontua(ptr_no ponteiro); /*Realiza a avaliacao dos pontos do tabuleiro e devolve os pontos realizados */

/*--------------- Funcoes das linhas eliminadas -----------------------*/
void insereElim(char* str);
int listLength();
void trataLinhas(ptr_no ponteiro);
void imprElim();
