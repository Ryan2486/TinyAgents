//
// Created by ryanr on 13/03/2026.
//

#include "Pawn.h"

#include "../utils.h"
#include "../Constants.h"

Pawn::Pawn(const Vector2 startPos, const float scale, const float radius, const std::map<PawnState, MyTexture> &stateTextures) : Entity(startPos, scale, radius), stateTextures(stateTextures)  {
}

void Pawn::SetDestination(const Vector2 &target) {
    currentTarget = target;
    currentState = RUNNING;
}

void Pawn::think(const float dt) {
     if (currentState == IDLE) {
         if (waitTimer > 0.0f) {
             waitTimer -= dt;
             return;
         }
         if (GetRandomValue(0, 100) < 5) { // 5% chance to move
             const Vector2 randomTarget = {static_cast<float>(GetRandomValue(0, SCREEN_WIDTH)), static_cast<float>(GetRandomValue(0, SCREEN_HEIGHT))};
             SetDestination(randomTarget);
         }
     }
    move(dt);
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
            waitTimer = static_cast<float>(GetRandomValue(10, 30)) / 10.0f;
        }
    }
}

void Pawn::update(const float dt) {
    think(dt);
    stateTextures[currentState].updateState(dt);
}

void Pawn::draw() {
    const MyTexture &texture = stateTextures[currentState];
    texture.draw(position, scale);
}

