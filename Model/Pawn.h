#ifndef SIMULATION_PAWN_H
#define SIMULATION_PAWN_H
#include "Entity.h"

enum PawnState {
    IDLE,
    RUNNING,
    ATTACKING
};


class Pawn : public Entity {
public:
    float speed = 100.0f;
    Vector2 currentTarget{};
    PawnState currentState = IDLE;

    Pawn(const int columns, const Vector2 startPos, const float startScale = 1.0f) : Entity(columns, startPos, startScale) {}

    void SetDestination(const Vector2& target);
    void think();
    void move(float dt);
    void update(float dt);
};


#endif