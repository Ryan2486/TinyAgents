//
// Created by ryanr on 15/03/2026.
//

#include "Sheep.h"
#include "../Constants.h"
#include "../utils.h"


Sheep::Sheep(const Vector2 startPos,const float radius,const std::map<SheepState, MyTexture>& stateTextures) : Entity(startPos, radius) {
    this->stateTextures = stateTextures;
}

void Sheep::thinking(const float dt) {
    if (currentState == SheepState::IDLE || currentState == SheepState::GRAZING) {
        if (waitTimer > 0.0f) {
            waitTimer -= dt;
            return;
        }
        if (const int proba = GetRandomValue(0, 100); proba < 5) {
            const Vector2 randomTarget = {static_cast<float>(GetRandomValue(0, SCREEN_WIDTH)), static_cast<float>(GetRandomValue(0, SCREEN_HEIGHT))};
            currentTarget = randomTarget;
            currentState = SheepState::MOVING;
            acting(dt);
        } else if (proba < 20) {
            waitTimer = static_cast<float>(GetRandomValue(20, 50)) / 10.0f;
            currentState = SheepState::GRAZING;
        } else {
            waitTimer = static_cast<float>(GetRandomValue(10, 30)) / 10.0f;
        }
    }
}

void Sheep::acting(const float dt) {
    if (currentState == SheepState::MOVING) {
        if (const float distance = utils::GetDistance(position, currentTarget); distance > 1.0f) {
            Vector2 direction = {currentTarget.x - position.x, currentTarget.y - position.y};
            direction.x /= distance;
            direction.y /= distance;
            position.x += direction.x * speed * dt;
            position.y += direction.y * speed * dt;
        } else {
            currentState = SheepState::IDLE;
            waitTimer = 0.5f;
        }
    }
}

void Sheep::update(const float dt) {
    thinking(dt);
    if (stateTextures.contains(currentState)) {
        stateTextures[currentState].updateState(dt);
    }
}

void Sheep::draw() {
    if (stateTextures.contains(currentState)) {
        stateTextures[currentState].draw(position, scale);
    }
}
