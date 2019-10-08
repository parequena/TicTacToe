##
# Things that i always forget
# @ -> On the left of ":"
# ^ -> Dependencies (on the right of ":").
# < -> Who caused the action
# % -> Anything.
##

CC       := g++ -std=c++17 # -O3
DEBUG    := -g
OPTIONS  := -Wall -Wextra -pedantic-errors
LIBS     := -lsfml-graphics -lsfml-window -lsfml-system #-ljsoncpp -lstdc++fs
SRC_DIR  := src
INC_DIR  := inc
OBJ_DIR  := obj
EXE_NAME := exe 
SOURCES  := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS  := $(subst .cpp,.o,$(SOURCES))
OBJECTS  := $(subst $(SRC_DIR),$(OBJ_DIR),$(OBJECTS))

all: $(OBJ_DIR)/ $(EXE_NAME)

$(OBJ_DIR)/:
	mkdir -p $(OBJ_DIR)

$(EXE_NAME): $(OBJECTS) main.cpp
	$(CC) $(DEBUG) $(OPTIONS) -o $@ $^ $(LIBS) -I$(INC_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CC) -o $@ -c $^ -I$(INC_DIR) $(DEBUG)

cls : clean

clc : clean

clear: clean

clean:
	rm -rf $(EXE_NAME)
	rm -rf $(OBJ_DIR)

info:
	$(info $(SOURCES))
	$(info $(OBJECTS))