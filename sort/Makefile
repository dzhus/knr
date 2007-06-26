OBJ = main.o alloc.o
sort : $(OBJ)
	cc -ansi -Wall -o sort $(OBJ)
main.o : main.c alloc.h
alloc.o : alloc.c
clean :
	rm -f $(OBJ) sort
test :	sort
	cat test | ./sort
	cat test2 | ./sort - n