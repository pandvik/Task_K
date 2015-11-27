
CC=g++
CFLAGS=-c -Wall -std=c++11
SOURCES=Cell.cpp StringCell.cpp EmptyCell.cpp ExpressionCell.cpp NumberCell.cpp Table.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=task_k

all: $(SOURCES) $(EXECUTABLE)
 
$(EXECUTABLE): $(OBJECTS) 
	#$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
