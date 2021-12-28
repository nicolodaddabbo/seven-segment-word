output: main.o
	gcc main.o -o output; ./output

main.o: main.c test.txt
	gcc -c main.c

clean:
	rm *.o output