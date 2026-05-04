#include "game.h"
#include "../ecs/Entity.h"

Game::Game() : world(ecs){
    isRunning = false;
}

void Game::init(){
    world.testMyPrint(); //this is how you call functions from another class

    frame = MyFrame("PvPark");
    frame.init();


/*    Entity player = ecs.createEntity();
    ecs.addTransform(player, {0, 0, 0, 0, 0, 0, 1, 1, 1});
    ecs.addHealth(player, {100, 100});
*/
    //circle = factory.createCircle(0.0f, 0.0f, 0.3f, 64); //example circle with OpenGL
    //triangle = factory.createTriangle(-0.5f, -0.5f, 0.5f, -0.5f, 0.0f, 0.5f); //code to draw a triangle in OpenGL
    



    world.generate();
    //player = Player(world.spawn);
    //renderer.init();
}

void Game::run(){
    isRunning = true;

    //main game loop. include things like ticks, etc
    
    while(isRunning && !frame.shouldClose()){
        frame.pollEvents(); //gets events for the window

        //toggles fullscreen
        if(glfwGetKey(frame.getWindow(), GLFW_KEY_F11) == GLFW_PRESS){
            frame.toggleFullscreen();
            while(glfwGetKey(frame.getWindow(), GLFW_KEY_F11) == GLFW_PRESS){
                glfwPollEvents();
            }
        }


        renderSystem.render(ecs, frame.getWindow());
        world.update();
        //player.update();
        //renderer.render();
    }
    frame.destroy();
}