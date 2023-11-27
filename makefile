CC=g++
OUTPUT = primroot
CFLAGS= -c -Wall 
SOURCES = main.cpp

EXECS = $(SOURCES:%.cpp=%) 

all: $(EXECS)

clean:
	rm $(EXECS)
