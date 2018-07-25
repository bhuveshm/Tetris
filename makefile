CC=g++
C_FLAGS=-c -DLINUX -I. -LSDL/lib
LD_FLAGS=-lSDL -lSDL_gfx
SOURCES=main.cc game.cc gboard.cc graphics.cc pieces.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=tetris

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cc.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f $(OBJECTS) $(EXECUTABLE)
