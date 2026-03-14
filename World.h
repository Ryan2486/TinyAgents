//
// Created by ryanr on 14/03/2026.
//

#ifndef SIMULATION_WORLD_H
#define SIMULATION_WORLD_H
#include <map>
#include <string>
#include <vector>

#include "Model/Entity.h"


class World {
public:
    std::vector<Entity*> entities;
    std::map<std::string, Texture2D> textures;

    void init();
    void draw();
    void update();
    void cleanUp();

};


#endif //SIMULATION_WORLD_H