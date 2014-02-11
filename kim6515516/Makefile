CC = gcc
CFLAGS = -W -Wall -O2
LDFLAGS = -lm

all : main saveToResult		
		$(CC) $(CFLAGS) -o main main.o saveToResult.o $(LDFLAGS)
main : main.c
		$(CC) $(CFLAGS) -c main.c

saveToResult : saveToResult.c
		$(CC) $(CFLAGS) -c saveToResult.c

clean  :
		@rm -rf *.o main
