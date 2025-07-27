CC = gcc
CFLAGS = -g -Iinclude -Wall `sdl2-config --cflags`
CLIBS = `sdl2-config --libs`

TARGET = autometa
PUSH = ./git.sh push
#PULL = ./git.sh pull

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

build: $(TARGET) 

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) $(CLIBS)

%.o: %.c macro.h cell.h 
	$(CC) $(CFLAGS) $< -c $@

run:
	./$(TARGET)

clean:
	rm -fr $(TARGET) *.o

debug:
	gdb --tui ./$(TARGET)

make push:
	$(PUSH)

#make pull:
	#$(PULL)




