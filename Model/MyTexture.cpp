//
// Created by ryanr on 14/03/2026.
//

#include "MyTexture.h"

void MyTexture::resetState() {
    currentTime = 0.0f;
    currentFrame = 0;
}

void MyTexture::updateState(const float dt) {
    currentTime += dt;
    if (currentTime >= frameTime) {
        currentTime = 0.0f;
        currentFrame = (currentFrame + 1) % frameCount;
    }
}

void MyTexture::draw(const Vector2 position, const float scale) const {
    const auto width = static_cast<float>(src.width) / static_cast<float>(frameCount);
    const auto height = static_cast<float>(src.height);

    const Rectangle sourceRec = { static_cast<float>(currentFrame) * width, 0.0f, width, height };

    const Rectangle destRec = { position.x, position.y, width * scale, height * scale };

    const Vector2 origin = { (width * scale) / 2, (height * scale) / 2 };
    DrawTexturePro(src, sourceRec, destRec, origin, 0.0f, WHITE);
}
