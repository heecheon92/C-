# Heecheon Park
# CSIS 352
# Makefile - prog

# Note: This file allows "make" command to do its job to create prog1 executable.

OBJECTS = main.o fraction.o
CC=g++
EXE=prog
CFLAGS=-Wall
LFLAGS=
$(EXE):				$(OBJECTS)
					$(CC) -o $(EXE) $(OBJECTS) $(LFLAGS)

main.o:			main.cpp fraction.h
					$(CC) $(CFLAGS) -c main.cpp

fraction.o:			fraction.cpp fraction.h
					$(CC) $(CFLAGS) -c fraction.cpp
# Clean up the directory
clean:
					rm -rf $(OBJECTS) $(EXE)*
