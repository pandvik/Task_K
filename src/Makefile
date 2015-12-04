
CC=g++ -g 
CFLAGS=-c -Wall --std=c++11
LDFLAGS=
SOURCES=main.cpp Table.cpp Cell.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=task_k

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

Table.o: Table.cpp Table.h
	$(CC) $(CFLAGS) $< -o $@

Cell.o: Cell.cpp Cell.h
	$(CC) $(CFLAGS) $< -o $@

main.o: main.cpp 
	$(CC) $(CFLAGS) $< -o $@

test: all
	make -C ../tests/ PROGRAM=../src/$(EXECUTABLE)

clear:
	rm -f *.o 









