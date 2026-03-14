//
// Created by ryanr on 14/03/2026.
//

#include "World.h"

#include <ranges>

void World::init() {
    InitWindow(NUMBER_OF_COLS * TILE_SIZE_ON_SCREEN, NUMBER_OF_ROWS * TILE_SIZE_ON_SCREEN, "Simulation");
    Texture2D tilesetTex = LoadTexture("../assets/Tileset/Tilemap_color1.png");
    currentTileset = new Tileset(tilesetTex, 6, 9);
    mapData.resize(NUMBER_OF_ROWS, std::vector<int>(NUMBER_OF_COLS, 4));
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


            Rectangle srcRec = currentTileset->GetRect(tileID);

            Rectangle destRec = {
                static_cast<float>(x * TILE_SIZE_ON_SCREEN),
                static_cast<float>(y * TILE_SIZE_ON_SCREEN),
                static_cast<float>(TILE_SIZE_ON_SCREEN),
                static_cast<float>(TILE_SIZE_ON_SCREEN)
            };

            DrawTexturePro(currentTileset->texture, srcRec, destRec, {0, 0}, 0.0f, WHITE);
        }
    }
    for (Entity* e : entities) {
        // Supposons que vos entités ont aussi une méthode draw...
        // e->draw();
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
