#include "raylib.h"
#include "World.h"

int main() {
    World world;
    world.init();

    while (!WindowShouldClose()) {

        world.update(GetFrameTime());
        BeginDrawing();
        ClearBackground(RAYWHITE);
        world.draw();
        EndDrawing();
    }
    world.cleanUp();
    CloseWindow();
    return 0;
}
