all: testa

compila:
    gcc -o *.c -Wall
    gcc -c main *.o -Wall

testa: compila
    nohup valgrind ./main   

clean: 
    rm nohup