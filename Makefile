export PATH := C:/msys64/ucrt64/bin:$(PATH)

CXX = g++
CXXFLAGS = -Wall -std=c++17 -I include -I C:/msys64/ucrt64/include
LDFLAGS = -L C:/msys64/ucrt64/lib -lglfw3 -lopengl32 -lgdi32

SRC = src/main.cpp \
      src/myFrame/myFrame.cpp \
      src/game/game.cpp \
      src/world/world.cpp \
      src/ecs/ECS.cpp \
      src/tests/testHelloWorld/helloWorld.cpp \
      src/factory/EntityFactory.cpp \
      src/systems/RenderSystem.cpp \
      vendor/glad.c

TARGET = main

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

clean:
	del $(TARGET).exe