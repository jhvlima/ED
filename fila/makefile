all: compila

compila: clean
	gcc -c posto.c amostra.c testador1.c tFila.c
	gcc -o prog1 posto.o amostra.o testador1.o tFila.o
	gcc -c posto.c amostra.c testador2.c tFila.c
	gcc -o prog2 posto.o amostra.o testador2.o tFila.o
	gcc -c posto.c amostra.c testador3.c tFila.c
	gcc -o prog3 posto.o amostra.o testador3.o tFila.o
	nohup valgrind ./prog1
	nohup valgrind ./prog2
	nohup valgrind ./prog3
clean:
	rm -f *.o nohup.out