//
// Created by ryanr on 13/03/2026.
//

#include "Pawn.h"

#include "../utils.h"

void Pawn::SetDestination(const Vector2 &target) {
    currentTarget = target;
    currentState = RUNNING;
}

void Pawn::think() {
    // for now just set a random destination when idle
    if (currentState == IDLE) {
        const auto randomX = static_cast<float>(GetRandomValue(100, 700));
        const auto randomY = static_cast<float>(GetRandomValue(100, 500));
        SetDestination({randomX, randomY});
    }
};

void Pawn::move(const float dt) {
    if (currentState == RUNNING) {
        Vector2 direction = {currentTarget.x - position.x, currentTarget.y - position.y};
        if (float distance = utils::GetDistance(position, currentTarget); distance > 1.0f) {
            direction.x /= distance;
            direction.y /= distance;
            position.x += direction.x * speed * dt;
            position.y += direction.y * speed * dt;
        } else {
            currentState = IDLE;
        }
    }
}

void Pawn::update(const float dt) {
    updateTexture(dt);
    think();
    move(dt);
}

