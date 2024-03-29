all: testa

compila:
	gcc -c *.c
	gcc -o main *.o

testa: compila
	valgrind ./main --leak-check=ful

clean:
	rm *.o main