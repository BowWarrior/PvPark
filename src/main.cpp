#include <iostream>
#include <string>

using namespace std;

#include "tests\testHelloWorld\helloWorld.h"
#include "world\world.h"


int main(){
    //printHelloWorld();
    World world = generateWorld();

    cout << printHelloWorld() << endl; //tests helloWorld's printHelloWorld function
    cout << world.renderDistance << endl;
    cout << world.spawn << endl;
    world.testMyPrint();
    return 0;
}