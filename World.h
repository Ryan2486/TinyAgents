//
// Created by ryanr on 14/03/2026.
//

#ifndef SIMULATION_WORLD_H
#define SIMULATION_WORLD_H
#include <map>
#include <string>
#include <vector>

#include "Model/Entity.h"
#include "Model/Tileset.h"


class World {
public:
    int NUMBER_OF_COLS = 20;
    int NUMBER_OF_ROWS = 10;

    std::vector<Entity*> entities;
    std::map<std::string, Texture2D> textures;

    Tileset* currentTileset = nullptr;
    std::vector<std::vector<int>> mapData;
    const int TILE_SIZE_ON_SCREEN = 64;

    void init();
    void draw() const;
    void update(float delta) const;
    void cleanUp();

};


#endif //SIMULATION_WORLD_H