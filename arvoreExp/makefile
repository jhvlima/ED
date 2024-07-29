all: compila

compila: clean
	gcc -c *.c -Wall -Wextra -Werror
	gcc -o prog *.o -Wall -Wextra -Werror
	nohup valgrind  --leak-check=full ./prog 
clean:
	rm -f nohup.out