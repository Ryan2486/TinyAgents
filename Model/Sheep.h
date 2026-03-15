//
// Created by ryanr on 15/03/2026.
//

#ifndef SIMULATION_MUTTON_H
#define SIMULATION_MUTTON_H
#include <map>

#include "Entity.h"
#include "MyTexture.h"

enum SheepState {
    IDLE,
    GRAZING,
    MOVING,
};


class Sheep : public Entity{
public:
    float speed = 100.0f;
    Vector2 currentTarget{0,0};
    SheepState currentState = IDLE;
    std::map<SheepState,MyTexture> stateTextures;
    float waitTimer = 0.0f;

    Sheep(Vector2 startPos, float radius, const std::map<SheepState,MyTexture>& stateTextures);

    void thinking(float dt);
    void acting(float dt);
    void update(float dt) override;
    void draw() override;
};


#endif //SIMULATION_MUTTON_H