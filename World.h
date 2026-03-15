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

    std::vector<Entity*> entities;
    std::map<std::string, Texture2D> textures;

    float spawnTimer = 0.0f;
    float spawnInterval = 2.0f;

    Tileset* currentTileset = nullptr;
    std::vector<std::vector<int>> mapData;

    void init();
    void draw() const;
    void update(float delta);
    void cleanUp();
};


#endif //SIMULATION_WORLD_H