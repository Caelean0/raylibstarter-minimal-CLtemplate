#include <cstdlib>

#include "raylib.h"

#include "config.h"

#include "Aufgabe5-CustomDynamicArray/testmains.h"
#include "Aufgabe8-LevelKlasse/AsteroidsHandler.h"
#include "Aufgabe3-Wuerfel/DiceGame.h"
#include "Aufgabe4-Pflanzen/PlantHandler.h"
#include "Aufgabe6-Auto/CarHandler.h"

int main() {
//    return DynamicArrayMain();

//    console::car::CarHandler myCarHandler;
//    return myCarHandler.handleUser();

//    console::plant::PlantHandler myPlantHandler;
//    return myPlantHandler.handleUser();


    // Raylib initialization
    // Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
    InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
    SetTargetFPS(60);

#ifdef GAME_START_FULLSCREEN
    ToggleFullscreen();
#endif

    // Your own initialization code here
    // ...
    // ...
    game::asteroids::AsteroidsHandler myAsteroidsGame;
    game::dice::DiceGame myDiceGame;


    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Updates that are made by frame are coded here
        // ...
        // ...
//        myAsteroidsGame.update();

        myDiceGame.update();

        BeginDrawing();
            // You can draw on the screen between BeginDrawing() and EndDrawing()
            // ...
            // ...
            ClearBackground(BLUE);
//            myAsteroidsGame.draw();

            myDiceGame.draw();


        EndDrawing();
    } // Main game loop end

    // De-initialization here
    // ...
    // ...

    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}
