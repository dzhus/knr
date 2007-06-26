OBJ = getch.o stack.o getop.o main.o

calc : $(OBJ)
	cc -o calc $(OBJ)
stack.o : calc.h
main.o : calc.h
getch.o :
getop.o : calc.h
clean :
	rm calc $(OBJ)