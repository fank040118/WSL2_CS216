# makefile for Lab8

EXEC = Lab8
CC = /usr/bin/g++
FLAG = -g -Wall


term.o: term.cpp term.h
	$(CC) $< -o $@

TermSortingList.o: TermSortingList.cpp TermSortingList.h term.cpp term.cpp
	$(CC) TermSortingList.cpp term.cpp -o $@

Lab8.o: Lab8.cpp term.cpp term.h TermSortingList.cpp TermSortingList.h
	$(CC) Lab8.cpp term.cpp TermSortingList.cpp -o $@


%.o : %.cpp
	$(CC) $(FLAG) -c $^

clean :
    rm -i *.o core









