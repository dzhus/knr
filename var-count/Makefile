OBJ = getty.o vartree.o main.o binsearch.o compare.o
OUT = var-count

var-count: ignore_words.inc ${OBJ}
	cc -Wall -ansi ${OBJ} -o ${OUT}
main.o: main.c
getty.o: getty.c getty.h
vartree.o: vartree.c vartree.h
binsearch.o: binsearch.c binsearch.h
compare.o: compare.c compare.h
clean:
	rm -f ${OUT} ${OBJ} *inc
ignore_words.inc: genwords.awk ignore_words
	cat ignore_words | uniq | sort | awk -f genwords.awk > ignore_words.inc