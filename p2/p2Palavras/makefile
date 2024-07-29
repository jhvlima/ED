all: compila

compila: clean
	gcc -c *.c
	gcc -o prog *.o
	nohup valgrind ./prog
clean:
	rm -f nohup.out