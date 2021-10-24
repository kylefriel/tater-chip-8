CC=g++
CFLAGS=-I.

tater-chip-8: main.o Chip8.o Timer.o
	$(CC) -o tater-chip-8 main.o Chip8.o Timer.o