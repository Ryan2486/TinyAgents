#ifndef SIMULATION_PAWN_H
#define SIMULATION_PAWN_H
#include <map>

#include "Entity.h"
#include "raylib.h"

enum PawnState {
    IDLE,
    RUNNING,
    ATTACKING
};


class Pawn: public Entity {
public:
    float speed = 100.0f;
    Vector2 currentTarget{0,0};
    PawnState currentState = IDLE;
    std::map<PawnState,Texture2D> stateTextures;


    void SetDestination(const Vector2 &target);
    void think();
    void move(float dt);
    void update(float dt);
    void draw();
};


#endif