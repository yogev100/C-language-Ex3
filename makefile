gcc = CC

all: Ex3

Ex3: txtfind.o isort.o  
	$(CC) -Wall txtfind.o -o txtfind
	$(CC) -Wall isort.o -o isort

txtfind.o: txtfind.c txtfind.h
	$(CC) -Wall -c txtfind.c -o $@

isort.o: isort.c txtfind.h
	$(CC) -Wall -c isort.c -o $@

clean: 
	rm *.o txtfind isort

.PHONY: all clean