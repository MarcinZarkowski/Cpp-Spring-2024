# This is an example Makefile for a Hare and Tortoise Competition project.
# This program uses Hare, Tortoise, Road, and Competition modules.
# Typing 'make' or 'make run' will create the executable file.
#

# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# for C++ define  CC = g++
CC = g++ -std=c++11
#CFLAGS  = -g -Wall

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
all: run

# To create the executable file run we need the object files
# CompetitionTest.o, Competition.o, Hare.o, Tortoise.o, and Road.o:
run:  CompetitionTest.o Competition.o Hare.o Tortoise.o Road.o 
	$(CC) -o run CompetitionTest.o Competition.o Hare.o Tortoise.o Road.o

# To create the object file CompetitionTest.o, we need the source
# files CompetitionTest.cpp, Competition.h 
CompetitionTest.o:  CompetitionTest.cpp
	$(CC) -c CompetitionTest.cpp

# To create the object file Competition.o, we need the source
# files Competition.cpp and Competition.h 
#
Competition.o:  Competition.cpp
	$(CC) -c Competition.cpp

# To create the object file Hare.o, we need the source files
# Hare.cpp. By default, $(CC) -c Hare.cpp generate Hare.o
#
Hare.o:  Hare.cpp
	$(CC) -c Hare.cpp

# To create the object file Tortoise.o, we need the source files
# Tortoise.cpp. 
# By default, $(CC) -c Tortoise.cpp generates Tortoise.o
Tortoise.o:  Tortoise.cpp
	$(CC) -c Tortoise.cpp

# To create the object file Road.o, we need the source files
# Road.cpp.
# By default, $(CC) -c Road.cpp generates Road.o
Road.o:  Road.cpp
	$(CC) -c Road.cpp

# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) run *.o *~

