CC=g++
CFLAGS=-I. -I/usr/include/SDL2 -c -std=c++17 -g
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
      instructions/SetReg.cpp \
      instructions/Add.cpp \
      instructions/SetIndex.cpp \
      instructions/Subroutine.cpp \
      instructions/SubroutineReturn.cpp \
      instructions/SkipIfXEqual.cpp \
      instructions/SkipIfXNotEqual.cpp \
      instructions/SkipIfXYEqual.cpp \
      instructions/SkipIfXYNotEqual.cpp \
      instructions/Set.cpp \
      instructions/BinaryOr.cpp \
      instructions/BinaryAnd.cpp \
      instructions/LogicalXor.cpp \
      instructions/AddWithCarry.cpp \
      instructions/Subtract.cpp \
      instructions/SubtractYfromX.cpp \
      instructions/SubtractXfromY.cpp \
      instructions/ShiftLeft.cpp \
      instructions/ShiftRight.cpp \
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










