CC = gcc
CFLAGS = -g -Wall -Iinclude `sdl2-config --cflags`
CLIBS = `sdl2-config --libs` -lSDL2_ttf

SRC = $(wildcard src/*.c)
HEAD = $(wildcard include/*.h)
OBJ = $(SRC:src/%.c=build/%.o)
DEPS = $(OBJ:.o=.d)
HEADS = $(HEAD:.h=.d)

TARGET = AUTOMATA

build: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) $(CLIBS)

build/%.o: src/%.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

run:
	i3-msg workspace 5
	./$(TARGET)

clean:
	rm -fr build/* $(TARGET)

debug:
	gdb --tui ./$(TARGET)

-include $(DEPS)
-include $(HEADS)








