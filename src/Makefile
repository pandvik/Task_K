
CC=g++
CFLAGS=-c -Wall
SOURCES=Cell.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=task_k

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	#$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
