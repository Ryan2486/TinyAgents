//
// Created by ryanr on 14/03/2026.
//

#ifndef SIMULATION_ENTITY_H
#define SIMULATION_ENTITY_H
#include "raylib.h"

class Entity {
public:
    Vector2 position;
    float scale;
    float radius;

    explicit Entity(Vector2 startPos, float scale, float radius);
};


#endif //SIMULATION_ENTITY_H