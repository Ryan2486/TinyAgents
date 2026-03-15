//
// Created by ryanr on 13/03/2026.
//

#include "Pawn.h"

#include "../utils.h"
#include "../Constants.h"

Pawn::Pawn(const Vector2 startPos, const float radius, const std::map<PawnState, MyTexture> &stateTextures) : Entity(startPos, radius), stateTextures(stateTextures)  {
}

void Pawn::SetDestination(const Vector2 &target) {
    currentTarget = target;
    currentState = PawnState::RUNNING;
}

void Pawn::thinking(const float dt) {
     if (currentState == PawnState::IDLE) {
         if (waitTimer > 0.0f) {
             waitTimer -= dt;
             return;
         }
         if (GetRandomValue(0, 100) < 5) { // 5% chance to move
             const Vector2 randomTarget = {static_cast<float>(GetRandomValue(0, SCREEN_WIDTH)), static_cast<float>(GetRandomValue(0, SCREEN_HEIGHT))};
             SetDestination(randomTarget);
         }
     }
    acting(dt);
};

void Pawn::acting(const float dt) {
    if (currentState == PawnState::RUNNING) {
         if(const float distance = utils::GetDistance(position, currentTarget); distance > 1.0f) {
             Vector2 direction = {currentTarget.x - position.x, currentTarget.y - position.y};
             flipped = direction.x < 0;
             direction.x /= distance;
             direction.y /= distance;
             position.x += direction.x * speed * dt;
             position.y += direction.y * speed * dt;
        } else {
            currentState = PawnState::IDLE;
            waitTimer = static_cast<float>(GetRandomValue(10, 30)) / 10.0f;
        }
    }
}

void Pawn::update(const float dt) {
    thinking(dt);
    stateTextures[currentState].updateState(dt);
}

void Pawn::draw() {
     stateTextures[currentState].draw(position, scale,flipped);
}

