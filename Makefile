#declare variable
CC=g++

#flags
CFLAGS=-Wall -O0 -std=c++11

all: hello
	
hello: main.o date.o empresa.o funcionario.o
	$(CC) main.o date.o empresa.o funcionario.o -o p

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

date.o: date.cpp
	$(CC) $(CFLAGS) date.cpp

empresa.o: empresa.cpp
	$(CC) $(CFLAGS) empresa.cpp

funcionario.o: funcionario.cpp
	$(CC) $(CFLAGS) funcionario.cpp

clean: 
	rm -rf *o p