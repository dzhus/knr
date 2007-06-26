OBJ = main.o alloc.o
tail : $(OBJ)
	cc -ansi -Wall -o tail $(OBJ)
main.o : main.c alloc.h
alloc.o : alloc.c
clean :
	rm -f $(OBJ) tail