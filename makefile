# Makefile for Project Shiro

# Compiler and flags
CC = gcc
CFLAGS = -fdiagnostics-color=always -g -Wall -D_REENTRANT
INCLUDES = -I/usr/local/include/SDL3 -I/home/jamie/development/project-shiro -Isrc
LIBS = -lSDL3

# Directories
BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src

# Source and object files
SOURCES := $(shell find $(SRC_DIR) -name '*.c')

# Replace src/ with obj/ and change .c to .o for object files
OBJECTS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES))

TARGET = $(BIN_DIR)/Shiro

# Default target
all: $(TARGET)

# Link the binary
$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LIBS)

# Compile .c to .o, placing object files in obj/ with directory structure preserved
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Run the binary
run: all
	clear
	LD_LIBRARY_PATH=/usr/local/lib ./bin/Shiro
