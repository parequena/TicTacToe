	##
# Things that i always forget
# @ -> On the left of ":"
# ^ -> Dependencies (on the right of ":").
# < -> Who caused the action.
# % -> Anything.
##

.PHONY: all cls clean clc clear info

COMMON_WARNINGS := -pedantic -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wmisleading-indentation -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough
GCC_WARNINGS := $(COMMON_WARNINGS) -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wuseless-cast
CLANG_WARNINGS := $(COMMON_WARNINGS) -Weverything -Wno-c++98-compat -Wno-padded

CC           := g++

ifeq ($(CC), clang++)
CCFLAGS := $(CLANG_WARNINGS)
else
CCFLAGS := $(GCC_WARNINGS)
endif

CCFLAGS := $(CCFLAGS) -std=c++20 -Werror

LIBS         := -lsfml-graphics -lsfml-window -lsfml-system
SRC_DIR      := src
INC_DIR      := include
BUID_DIR     := build
OBJ_DIR      := $(BUID_DIR)/obj
EXE_NAME     := $(BUID_DIR)/exe 
SOURCES      := $(shell find $(SRC_DIR) -type f) # Calling the shell to find all the files.
OBJECTS      := $(subst .cpp,.o,$(SOURCES))
OBJECTS      := $(subst $(SRC_DIR),$(OBJ_DIR),$(OBJECTS))
 
ifdef REL
CCFLAGS += -O3
else
CCFLAGS += -g # -fsanitize=address,leak
endif


all: $(OBJ_DIR)/ $(EXE_NAME)

$(OBJ_DIR)/:
	mkdir -p $(OBJ_DIR)

$(EXE_NAME): $(OBJECTS)
	$(CC) $(CCFLAGS) -o $@ $^ $(LIBS) -I$(INC_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CC) -o $@ -c $^ -I$(INC_DIR) $(CCFLAGS)

cls : clean

clc : clean

clear: clean

clean:
	rm -rf $(BUID_DIR)

info:
	$(info $(SOURCES))
	$(info $(OBJECTS))
