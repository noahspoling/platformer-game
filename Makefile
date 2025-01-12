# Compiler and flags
CC = gcc
#  -I lib/extern/flecs/include 
CFLAGS = -I src -std=c99 -Wall -Wextra -O2

# Libraries
RAYLIB_LIB = lib/extern/raylib/build/raylib/libraylib.a
# FLECS_LIB = lib/extern/flecs/build/libflecs_static.a
# CJSON_LIB = lib/extern/cjson/build/libcjson.so
# Add precompiled libraries here
#  $(FLECS_LIB) $(CJSON_LIB)
LIBS = $(RAYLIB_LIB) -lm -ldl -lpthread -lGL -lX11

# Directories
SRC_DIR = src
INCLUDE_DIR = src/include
BUILD_DIR = bin

# Sources and objects
SRCS = $(shell find $(SRC_DIR) -name '*.c')
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Output
TARGET = $(BUILD_DIR)/game

# Rules
all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $@

clean:
	rm -rf $(BUILD_DIR)
