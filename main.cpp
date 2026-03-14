#include "raylib.h"
#include "Model/Entity.h"
#include <vector>
#include <iostream>

#include "Model/Pawn.h"

int main() {
    InitWindow(800, 600, "Simulation");

    const Texture2D treeSprite = LoadTexture("../assets/Trees/Tree1.png");
    const Texture2D pawnSprite = LoadTexture("../assets/Pawn/Pawn_Run.png");


    std::vector<Entity> forest;
    std::vector<Pawn> pawns;
    for(int i = 0; i < 10; i++) {
        const auto ramdomScale = static_cast<float>(GetRandomValue(5, 7)) / 10.0f;
        const auto randomX = static_cast<float>(GetRandomValue(100, 700));
        const auto randomY = static_cast<float>(GetRandomValue(100, 500));

        Entity arbre(8, {randomX, randomY}, ramdomScale);
        forest.push_back(arbre);

        Pawn pawn(6, {randomX, randomY}, 0.5f);
        pawns.push_back(pawn);
    }


    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        for (auto& pawn : pawns) pawn.update(dt);
        for(auto& arbre : forest) arbre.updateTexture(dt);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (auto& pawn : pawns) pawn.draw(pawnSprite);
        for(auto& arbre : forest) arbre.draw(treeSprite);
        EndDrawing();
    }
}
