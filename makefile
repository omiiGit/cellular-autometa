CC = gcc
CFLAGS = -g -Wall -Iinclude `sdl2-config --cflags`
CLIBS = `sdl2-config --libs`

SRC = $(wildcard src/*.c)
HEAD = $(wildcard include/*.h)
OBJ = $(SRC:src/%.c=build/%.o)
TARGET = AUTOMATA

build: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) $(CLIBS)

build/%.o: src/%.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

run:
	./$(TARGET)

clean:
	rm -fr build/* $(TARGET)

debug:
	gdb --tui ./$(TARGET)








