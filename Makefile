CC=g++
CFLAGS=-I. -c
APP=tater-chip-8
OBJDIR=obj

SRC = 	Chip8.cpp \
		Timer.cpp \
		SoundTimer.cpp \
		Display.cpp \
		InstructionFactory.cpp \
		instructions/InstructionBase.cpp \
		instructions/ClearScreen.cpp \
		main.cpp \

OBJS =	$(SRC:%.cpp=$(OBJDIR)/%.o)		

build: $(APP)

clean:
	rm -f $(OBJS) $(APP)

$(APP):$(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJS): $(OBJDIR)/%.o: %.cpp
	@mkdir -p $(@D)	 
	$(CC) $(CFLAGS) -o $@ $<









