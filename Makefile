CC := g++
CFLAGS := -std=c++11 -Wall -Wextra 

SRC := main.cpp CakeDisplay.cpp Subll.cpp CakeFactory.cpp 

TARGET := main

LIBS := -lraylib

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f $(TARGET)
