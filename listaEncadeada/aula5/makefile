all: testa

compila:
	cd objects/ && gcc -c ../source/*.c
	gcc -o main objects/*.o

testa: compila
	nohup valgrind ./main < input.txt > output.txt --leak-check=ful

clean:
	rm objects/*.o main output.txt