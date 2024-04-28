NOME = JoaoHenrique
OBJETOS = tBannhoTosa.o tGato.o tLista.o tCachorro.o

all: testa

compila: clean
# compila *.c para *.o
	gcc -c *.c
# compila *.o para executavel
	gcc -o $(NOME) *.o

testa: compila
	nohup valgrind -s ./$(NOME) > resultados.txt

clean:
	rm -f *.o $(NOME)