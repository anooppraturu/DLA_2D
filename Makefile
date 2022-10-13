########
CC=gcc

SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)

all: DLA

DLA: $(OBJECTS)
	$(CC) -o $@ $^

%.o: %.c %.h defs.h
	$(CC) -c $<

%.o: %.c defs.h
	$(CC) -c $<

clean:
	rm -f *.o DLA
