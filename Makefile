CC = gcc

CFLAGS = -Wall

breanfuck:main.o
	${CC} -o brainfuck main.o ${CFLAGS}

main.o:main.c
	${CC} -c main.c ${CFLAGS}

clean:
	rm -rf main.o
