output: main.o
	gcc main.o -o output; ./output

main.o: main.c test.txt words.txt
	gcc -c main.c

clean:
	rm *.o output