CC          =	gcc
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-Wall -ansi -pedantic -g


#Directories where the compiler can find things
INCLUDES    = -Iinclude


# add directory names here if you want to separate files by directories
BINDIR = bin/
SRCDIR = src/
INCLUDEDIR = include/

#Put the names of your source code file in the lines below.  

SOURCE = $(SRCDIR)main.c $(SRCDIR)linkedListFunctions.c $(SRCDIR)functions.c 

#The list of object files is below.  The object file names here must match the file names of your source code 
# except with .o instead of .c.   Make changes as appropriate


OBJS    = main.o linkedListFunctions.o functions.o


#The names of the binary programs that will be produced.  
#
PROGNAME = $(BINDIR)permutePrimes


default : permute

permute: permuteCompile
	$(CC) -o $(PROGNAME)  $(OBJS)

permuteCompile: 
	$(CC) $(CFLAGS) -c  $(SOURCE) $(INCLUDES) 

clean:
	@ rm *.o
