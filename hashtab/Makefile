OUT = hashtab
OBJ = main.o getty.o compare.o

hashtab: ${OBJ}
	cc -Wall -ansi ${OBJ} -o ${OUT}
main.o: main.c
getty.o: getty.c
compare.o: compare.c
clean:
	rm -f ${OUT} ${OBJ}