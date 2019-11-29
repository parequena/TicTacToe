##
# Things that i always forget
# @ -> On the left of ":"
# ^ -> Dependencies (on the right of ":").
# < -> Who caused the action.
# % -> Anything.
##

.PHONY: all cls clean clc clear info

CC       := g++ -std=c++17
CCFLAGS  := -Wall -Wextra -pedantic-errors
LIBS     := -lsfml-graphics -lsfml-window -lsfml-system #-ljsoncpp -lstdc++fs
SRC_DIR  := src
INC_DIR  := inc
OBJ_DIR  := obj
EXE_NAME := exe 
SOURCES := $(shell find $(SRC_DIR) -type f) # Calling the shell to find all the files.
# SOURCES  := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS  := $(subst .cpp,.o,$(SOURCES))
OBJECTS  := $(subst $(SRC_DIR),$(OBJ_DIR),$(OBJECTS))
 
ifdef REL
CCFLAGS += -O3
else
CCFLAGS += -g
endif


all: $(OBJ_DIR)/ $(EXE_NAME)

$(OBJ_DIR)/:
	mkdir -p $(OBJ_DIR)

$(EXE_NAME): $(OBJECTS) main.cpp
	$(CC) $(CCFLAGS) -o $@ $^ $(LIBS) -I$(INC_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CC) -o $@ -c $^ -I$(INC_DIR) $(CCFLAGS)

cls : clean

clc : clean

clear: clean

clean:
	rm -rf $(EXE_NAME)
	rm -rf $(OBJ_DIR)

info:
	$(info $(SOURCES))
	$(info $(OBJECTS))