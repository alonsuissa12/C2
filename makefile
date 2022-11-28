CC = gcc
FLAGS = -Wall -g
connections:main.o libmy_mat.a
	$(CC) $(FLAGS) main.o libmy_mat.a -o connections
main.o:main.c my_mat.h
	$(CC) $(FLAGS) -c main.c -o main.o
my_mat.o: my_mat.h my_mat.c
	$(CC) $(FLAGS) -c my_mat.c -o my_mat.o
libmy_mat.a:my_mat.o
	ar -rcs libmy_mat.a my_mat.o
all: connections main.o libmy_mat.a
clean:
	rm -f *.o
	rm connections
.PHONEY: all clean

# -WALL !!!!!