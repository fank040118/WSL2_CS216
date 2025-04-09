# makefile for Lab8

EXEC = Lab8
OBJS = Lab8.o term.o TermSortingList.o 
CC = /usr/bin/g++
FLAG = -g -Wall


$(EXEC): $(OBJS)
	$(CC) $(OBJS) -c $@ 

term.o: term.cpp term.h
	$(CC) $< -c $@

TermSortingList.o: TermSortingList.cpp TermSortingList.h term.cpp term.cpp
	$(CC) TermSortingList.cpp term.cpp -c $@

Lab8.o: Lab8.cpp term.cpp term.h TermSortingList.cpp TermSortingList.h
	$(CC) Lab8.cpp term.cpp TermSortingList.cpp -c $@


clean:
	rm -i *.o core









