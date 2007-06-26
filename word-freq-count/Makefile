OBJ = main.o getty.o word_list.o
OUT = var-count

var-count: $(OBJ)
	cc -Wall -std=c99 -DDEBUG $(OBJ) -o $(OUT)
main.o: main.c
getty.o: getty.c getty.h
word_list.o: word_list.c word_list.h
clean:
	rm -f $(OBJ) $(OUT)