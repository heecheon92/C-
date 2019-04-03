# Heecheon Park
# CSIS 352
# Makefile - prog4

# Note: This file allows "make" command to do its job to create prog3 executable.

OBJECTS = main.o
CC=g++
EXE=prog4
CFLAGS=-Wall
LFLAGS=
$(EXE):			$(OBJECTS)
				$(CC) -o $(EXE) $(OBJECTS) $(LFLAGS)

main.o:	main.cpp sortedList.h
				$(CC) $(CFLAGS) -c main.cpp

# Clean up the directory
clean:
				rm -rf $(OBJECTS) $(EXE)*~
