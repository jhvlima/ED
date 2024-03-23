all: testa

compila:
	gcc -o aula2 aula2.c

testa: compila
	valgrind ./aula2 < input.txt --leak-check=ful