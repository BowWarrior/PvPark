#include <iostream>
#include <string>
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "myFrame/myFrame.h"
#include "game\game.h"
using namespace std;



int main(){
    //printHelloWorld();
    Game game;
    cout << "hi";
    game.init();
    cout << "hello";
    game.run();
    cout << "hasefeasefa";
    //cout << printHelloWorld() << endl; //tests helloWorld's printHelloWorld function, but need to include the test file again
    return 0;
}