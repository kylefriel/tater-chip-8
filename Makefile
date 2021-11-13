CC=g++
CFLAGS=-I. -I/usr/include/SDL2 -c -std=c++11
LDFLAGS=-lSDL2main -lSDL2
APP=tater-chip-8
OBJDIR=obj

SRC = Chip8.cpp \
      Timer.cpp \
      SoundTimer.cpp \
      Chip8Display.cpp \
      InstructionFactory.cpp \
      instructions/InstructionBase.cpp \
      instructions/ClearScreen.cpp \
      instructions/Display.cpp \
      instructions/Jump.cpp \
      instructions/Set.cpp \
      instructions/Add.cpp \
      instructions/SetIndex.cpp \
      main.cpp		

OBJS = $(SRC:%.cpp=$(OBJDIR)/%.o)		

build: $(APP)

clean:
	rm -f $(OBJS) $(APP)

$(APP):$(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) 

$(OBJS): $(OBJDIR)/%.o: %.cpp
	@mkdir -p $(@D)	 
	$(CC) $(CFLAGS) -o $@ $<










