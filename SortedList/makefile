# Heecheon Park
# Makefile - prog

# Note: This file allows "make" command to do its job to create prog executable.

OBJECTS = main.o
CC=g++
EXE=prog
CFLAGS=-Wall
LFLAGS=
$(EXE):			$(OBJECTS)
				$(CC) -o $(EXE) $(OBJECTS) $(LFLAGS)

main.o:	main.cpp sortedList.h
				$(CC) $(CFLAGS) -c main.cpp

# Clean up the directory
clean:
				rm -rf $(OBJECTS) $(EXE)*~
