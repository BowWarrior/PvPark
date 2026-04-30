#include <iostream>
#include <string>

using namespace std;

#include "tests\testHelloWorld\helloWorld.h"
#include "world\world.h"
#include "game\game.h"


int main(){
    //printHelloWorld();
    Game game;
    game.init();
    game.run();
    //cout << printHelloWorld() << endl; //tests helloWorld's printHelloWorld function
    return 0;
}