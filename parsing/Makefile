CC = gcc
CFLAGS = -Wall -Wextra -pedantic -O -std=c11
LDLIBS = -lm
# add $(LDLIBS) for math

VALGRIND = -O0 -g

CFLAGS += $(VALGRIND)

HEADERS := $(wildcard *.h)

#OTHER_FILES := ../dataStructs/str.o ../dataStructs/array.o $(wildcard ../dataTypes/mathobj/*.o) $(wildcard ../dataTypes/mathobj/types/*.o) ../errors.o ../dataTypes/util.o

OBJ := parser.tab.o lex.yy.o parse.o

.PHONY: build clean

build: $(OBJ) #$(OTHER_FILES)
	# bison -d parser.y
	# flex lexer.l
	# gcc -o main $(OBJ) $(OTHER_FILES) $(LDLIBS)

lex.yy.c: lexer.l
	flex lexer.l

parser.tab.c: parser.y
	bison -d parser.y

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $*.c -o $@

clean:
	rm -f *.o main lex.yy.c *.tab.*