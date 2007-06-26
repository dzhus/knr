OBJ = getty.o wordtree.o main.o binsearch.o compare.o
OUT = id-count

id-count: words.inc ${OBJ}
	cc -Wall -ansi ${OBJ} -o ${OUT}
getty.o: getty.c
main.o: main.c
wordtree.o: wordtree.c
binsearch.o: binsearch.c
compare.o: compare.c
clean:
	rm -f ${OUT} ${OBJ} *inc
words.inc: words genwords.awk
	cat words | uniq | sort | awk -f genwords.awk > words.inc
# DO NOT DELETE
