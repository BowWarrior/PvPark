#include "game.h"

Game::Game(){
    isRunning = false;
}

void Game::init(){
    world = World();
    world.testMyPrint(); //this is how you call functions from another class
    world.generate();
    //player = Player(world.spawn);
    //renderer.init();
}

void Game::run(){
    isRunning = true;

    //main game loop. include things like ticks, etc
    
    while(isRunning){        
        world.update();
        //player.update();
        //renderer.render();
    }
}