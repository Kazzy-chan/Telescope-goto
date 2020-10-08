ifeq ($(OS),Windows_NT)
    CXX := g++
	CXX_FLAGS := -Wall
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Darwin)
    	CXX := clang++
		CXX_FLAGS := -Wall -Wextra -std=c++17 -g
	else
		CXX := g++
		CXX_FLAGS := -Wall
	endif
endif

BIN		:= bin
SRC		:= dev
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:=
EXECUTABLE	:= main

all: $(BIN)/$(EXECUTABLE)

run: clean all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*