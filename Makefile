
CC := g++
CFLAGS := -std=c++11 -Wall -Wextra 

SRC := main.cpp Subll.cpp CakeFactory.cpp LoadingScreen.cpp CakeDisplay.cpp
OBJ := $(SRC:.cpp=.o)  # Object files

TARGET := main

LIBS := -lraylib

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)

