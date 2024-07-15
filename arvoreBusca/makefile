all: testa

compila:
	gcc -c *.c
	gcc -o main *.o

testa: compila
	nohup valgrind ./main --leak-check=ful -s

clean:
	rm *.o main nohup.out