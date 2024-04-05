all: testa

compila:
	cd objects/ && gcc -c ../source/*.c
	gcc -o main objects/*.o

testa: compila
	valgrind ./main < input.txt > output.txt --leak-check=ful

clean:
	rm *.o main