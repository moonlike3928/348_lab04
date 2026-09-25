all: task1.c task2.c
	gcc -Wall -Wextra task1.c -o task1.o
	gcc -Wall -Wextra task2.c -o task2.o

clean:
	rm -f *.o