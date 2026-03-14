#ifndef ENTITY_H
#define ENTITY_H

#include "raylib.h"

class Entity {
public:
    Vector2 position{};
    int numFrames;
    int currentFrame;
    float frameTimer;
    float frameSpeed;
    float scale = 1.0f;

    Entity(int columns, Vector2 startPos, float startScale = 1.0f);

    void updateTexture(float dt);
    void draw(const Texture2D& texture) const;
};

#endif