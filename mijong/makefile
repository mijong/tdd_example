CC = gcc
CFLAGS = -W -Wall -O2
LDFLAGS = -lm

all : main getFileLog
		$(CC) $(CFLAGS) -o main main.o getFileLog.o $(LDFLAGS)
main : main.c
		$(CC) $(CFLAGS) -c main.c 

getFileLog : getFileLog.c
		$(CC) $(CFLAGS) -c getFileLog.c

clean : 
		@rm -rf *.o main *~
