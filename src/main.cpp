
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include "myFrame/myFrame.h"
#include "game\game.h"
using namespace std;



int main(){
    //printHelloWorld();
    Game game;
    game.init();
    game.run();
    //cout << printHelloWorld() << endl; //tests helloWorld's printHelloWorld function, but need to include the test file again
    return 0;
}