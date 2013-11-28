###### makefile: projecto 3 - Tretris ###################
# Dário Nascimento,Bernardo Figueiredo, André Goncalves
# AED - IST 2010 

INCLUDES = proj3.h

all: proj3

#arquivos fontes que constituiem o programa:
proj3: main.o item.o pecas.o tabuleiro.o trata.o lpecas.o elim.o
	gcc -ansi -Wall -pedantic -o proj3 main.o item.o pecas.o lpecas.o tabuleiro.o trata.o elim.o
	
#regra para o arquivo "main.o"
main.o: main.c  $(INCLUDES) 
		gcc -o main.o -c main.c -ansi -Wall -pedantic
		
#regra para o arquivo "item.o"
item.o: item.c  $(INCLUDES) 
		gcc -o  item.o -c item.c -ansi -Wall -pedantic
#regra para o arquivo "pecas.o"
pecas.o: pecas.c  $(INCLUDES) 
		gcc -o pecas.o -c pecas.c -ansi -Wall -pedantic 
		
#regra para o arquivo "manipula.o"
tabuleiro.o: tabuleiro.c  $(INCLUDES) 
		gcc -o tabuleiro.o -c tabuleiro.c -ansi -Wall -pedantic 

#regra para o arquivo "trata.o"
trata.o: trata.c  $(INCLUDES) 
		gcc -o trata.o -c trata.c -ansi -Wall -pedantic 
		
#regra para o arquivo "lpecas.o"
lpecas.o: lpecas.c  $(INCLUDES) 
		gcc -o lpecas.o -c lpecas.c -ansi -Wall -pedantic 

#regra para o arquivo "elim.o"
elim.o: eliminadas.c  $(INCLUDES) 
		gcc -o elim.o -c eliminadas.c -ansi -Wall -pedantic 
		

# Limpar os arquivos intermedios gerados: arquivos objecto
clean:
	rm -rf *.o



