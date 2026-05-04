#include <iostream>
#include "game.h"

Game::Game(){
    isRunning = false;
}

void Game::init(){
    world = World();
    world.testMyPrint(); //this is how you call functions from another class
    


    frame = MyFrame("PvPark");
    frame.init();

    world.generate();
    //player = Player(world.spawn);
    //renderer.init();
}

void Game::run(){
    isRunning = true;

    //main game loop. include things like ticks, etc
    
    while(isRunning && !frame.shouldClose()){        
        frame.pollEvents();
        world.update();
        //player.update();
        //renderer.render();
    }
    frame.destroy();
}