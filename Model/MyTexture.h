//
// Created by ryanr on 14/03/2026.
//

#ifndef SIMULATION_TEXTURE_H
#define SIMULATION_TEXTURE_H
#include "raylib.h"


class MyTexture {
public:
    Texture2D src{};
    int frameCount = 1;
    float frameTime = 0.0f;
    float currentTime{};
    int currentFrame{};

    MyTexture() = default;

    MyTexture(const Texture2D &src, int frameCount, float frameTime);

    void resetState();
    void updateState(float dt);
    void draw(Vector2 position, float scale) const;
};


#endif //SIMULATION_TEXTURE_H