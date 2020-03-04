CC=gcc
CFLAGS=-c -Wall -Werror
LDFLAGS=
SOURCES=list_node.c soluciones.c testing_framework.c main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=test

all: $(EXECUTABLE)

$(EXECUTABLE): compile
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

compile:
	$(CC) $(CFLAGS) $(SOURCES)

clean:
	rm -rf *.o $(EXECUTABLE)

check: $(EXECUTABLE)
	./$(EXECUTABLE)