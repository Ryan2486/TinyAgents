//
// Created by ryanr on 14/03/2026.
//

#include "World.h"

#include <ranges>

#include "Model/Pawn.h"
#include "Constants.h"

void World::init() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Simulation");
    textures["map"] = LoadTexture("../assets/Tileset/Tilemap_color1.png");
    currentTileset = new Tileset(textures["map"], 6, 9);
    mapData.resize(WORLD_ROWS, std::vector<int>(WORLD_COLS, 4));

    textures["pawn_idle"] = LoadTexture("../assets/Pawn/Pawn_Idle.png");
    textures["pawn_run"] = LoadTexture("../assets/Pawn/Pawn_Run.png");
    textures["pawn_attack"] = LoadTexture("../assets/Pawn/Pawn_Interact Knife.png");

    const auto randomX = static_cast<float>(GetRandomValue(10, SCREEN_WIDTH - 10));
    const auto randomY = static_cast<float>(GetRandomValue(10, SCREEN_HEIGHT - 10));

    const auto pawn = new Pawn({randomX, randomY}, 16.0f, {
                              {IDLE, MyTexture(textures["pawn_idle"], 8, 0.1f)},
                              {RUNNING, MyTexture(textures["pawn_run"], 6, 0.1f)},
                              {ATTACKING, MyTexture(textures["pawn_attack"], 4, 0.1f)}
                          });
    entities.push_back(pawn);
}

void World::update(const float delta) const {
    for (Entity* e : entities) {
        e->update(delta);
    }
}

void World::draw() const {
    if (!currentTileset) return;
    for (int y = 0; y < mapData.size(); y++) {
        for (int x = 0; x < mapData[y].size(); x++) {

            const int tileID = mapData[y][x];

            if (tileID < 0) continue;


            const Rectangle srcRec = currentTileset->GetRect(tileID);

            const Rectangle destRec = {
                static_cast<float>(x * TILE_SIZE),
                static_cast<float>(y * TILE_SIZE),
                static_cast<float>(TILE_SIZE),
                static_cast<float>(TILE_SIZE)
            };

            DrawTexturePro(currentTileset->texture, srcRec, destRec, {0, 0}, 0.0f, WHITE);
        }
    }
    for (Entity* e : entities) {
        e->draw();
    }
}

void World::cleanUp() {
    for (auto &val: textures | std::views::values) {
        UnloadTexture(val);
    }
    for (const Entity* e : entities) {
        delete e;
    }
    entities.clear();
}
