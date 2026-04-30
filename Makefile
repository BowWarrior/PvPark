CXX = g++
CXXFLAGS = -Wall -std=c++17

TARGET = main
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	del $(TARGET).exe