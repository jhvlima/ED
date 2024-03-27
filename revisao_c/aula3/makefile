all: testa

compila:
	gcc -c *.c
	gcc -o main *.o

testa: compila
	valgrind ./aula3 < input.txt --leak-check=ful

clean:
	rm *.o main