# makefile for Lab8

EXEC = Lab8
OBJS = Lab8.o term.o TermSortingList.o 
CC = /usr/bin/g++


$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ 

term.o: term.cpp term.h
	$(CC) $< -c $@

TermSortingList.o: TermSortingList.cpp TermSortingList.h term.h
	$(CC) TermSortingList.cpp -c $@

Lab8.o: Lab8.cpp term.h TermSortingList.h
	$(CC) Lab8.cpp -c $@


clean:
	rm -i *.o core









