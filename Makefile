CC=g++
CFLAGS=-I.

tater-chip-8: main.o Chip8.o Timer.o SoundTimer.o Display.o
	$(CC) -o tater-chip-8 main.o Chip8.o Timer.o SoundTimer.o Display.o

clean:
	rm *.o 
	rm tater-chip-8