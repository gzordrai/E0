CC = g++
CFLAGS = -Wall -g

main: main.o E0.o
	$(CC) $(CFLAGS) -o main main.o E0.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

E0.o: E0.cpp E0.h
	$(CC) $(CFLAGS) -c E0.cpp