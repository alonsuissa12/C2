main.exe:main.o my_mat.o
	gcc main.o my_mat.o -o main.exe
main.o:main.c my_mat.h
	gcc -c main.c -o main.o
my_mat.o: my_mat.h my_mat.c
	gcc -c my_mat.c -o my_mat.o
all: main.exe main.o my_mat.o
.PHONEY: all