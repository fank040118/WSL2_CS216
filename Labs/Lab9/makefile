# makefile for Lab9

EXEC = Lab9
OBJS = Lab9.o term.o SortingList.o autocomplete.o
CC = /usr/bin/g++

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@

term.o: term.cpp term.h
	$(CC) -c $<

SortingList.o: SortingList.cpp SortingList.h
	$(CC) -c $<
	
autocomplete.o: autocomplete.cpp autocomplete.h SortingList.h term.h
	$(CC) -c $<

Lab9.o: Lab9.cpp term.h SortingList.h autocomplete.h
	$(CC) -c $<

clean:
	rm -i *.o core












