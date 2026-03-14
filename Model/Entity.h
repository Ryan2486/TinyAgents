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

    explicit Entity(const Vector2 startPos, const float scale, const float radius) : position(startPos), scale(scale), radius(radius) {}
    virtual ~Entity() = default;
    virtual void update(float dt) = 0;
    virtual void draw() = 0;
};


#endif //SIMULATION_ENTITY_H