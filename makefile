CC=g++
CFLAGS=-Wall -lGL -lGLU -lGLEW -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi 

all: main

main: main.o
	$(CC) main.o -o main $(CFLAGS)

main.o: main.cpp
	$(CC) -c main.cpp
clean:
	rm -rf *o main