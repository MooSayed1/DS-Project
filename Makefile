CC := g++
CFLAGS := -std=c++11 -Wall -Wextra -Werror

SRC := main.cpp

TARGET := example

LIBS := -lraylib

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f $(TARGET)
