# makefile for Lab9

EXEC = Lab9
OBJS = Lab9.o term.o sortingList.o autoComplete.o
CC = /usr/bin/g++

$(EXEC): $(OBJS)
    $(CC) $(OBJS) -o $@

term.o: term.cpp term.h
    $(CC) -c $<

sortingList.o: sortingList.cpp sortingList.h term.h
	$(CC) -c $<
	
autoComplete.o: autoComplete.cpp autoComplete.h sortingList.h term.h
	$(CC) -c $<

Lab9.o: Lab9.cpp term.h sortingList.h autoComplete.h
    $(CC) -c $<

clean:
	rm -i *.o core












