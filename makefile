CC = gcc
CFLAGS = -g -Iinclude -Wall `sdl2-config --cflags`
CLIBS = `sdl2-config --libs`

TARGET = autometa

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

build: $(TARGET) 

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) $(CLIBS)

%.o: %.c 
	$(CC) $(CLFAGS) $< -c $@

run:
	./$(TARGET)

clean:
	rm -fr $(TARGET) *.o

debug:
	gdb --tui ./$(TARGET)




