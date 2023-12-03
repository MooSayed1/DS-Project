
CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRC = main.cpp
TARGET = main	

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
