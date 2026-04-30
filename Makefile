CXX = g++
CXXFLAGS = -Wall -std=c++17 -I include -I C:/msys64/ucrt64/include
LDFLAGS = -L C:/msys64/ucrt64/lib -lglfw3 -lopengl32 -lgdi32

# Source files
SRC = src/main.cpp \
      src/world/World.cpp \
      src/game/game.cpp \
      src/tests/testHelloWorld/helloWorld.cpp \
      vendor/glad.c

# Output
TARGET = main

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

clean:
	del $(TARGET).exe