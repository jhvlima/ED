testa: clean
	gcc -c *.c
	gcc -o prog *.o
	nohup valgrind ./prog --leak-check=full -s

clean:
	rm *.o prog nohup.out