#include "raylib.h"
#include "World.h"

int main() {
    InitWindow(800, 600, "Simulation");
    World world;
    world.init();

    while (!WindowShouldClose()) {
        world.update();

        BeginDrawing();
        world.draw();
        EndDrawing();
    }
    world.cleanUp();
    CloseWindow();
    return 0;
}
