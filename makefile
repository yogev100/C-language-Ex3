CC=gcc
CFLAG=-Wall
TXTH=txtfind.h

all: Ex3

Ex3: txtfind.o isort.o  
	$(CC) $(CFLAG) txtfind.o -o txtfind
	$(CC) $(CFLAG) isort.o -o isort

txtfind.o: txtfind.c $(TXTH)
	$(CC) $(CFLAG) -c txtfind.c -o $@

isort.o: isort.c $(TXTH)
	$(CC) $(CFLAG) -c isort.c -o $@

clean: 
	rm *.o txtfind isort

.PHONY: all clean