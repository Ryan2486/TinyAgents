#include "Entity.h"

Entity::Entity(const int columns, const Vector2 startPos, const float startScale) {
    numFrames = columns;
    position = startPos;
    scale = startScale;
    currentFrame = 0;
    frameTimer = 0.0f;
    frameSpeed = 0.15f;
}

void Entity::updateTexture(const float dt) {
    frameTimer += dt;
    if (frameTimer >= frameSpeed) {
        frameTimer = 0.0f;
        currentFrame = (currentFrame + 1) % numFrames;
    }
}

void Entity::draw(const Texture2D& texture) const {
    const auto width = static_cast<float>(texture.width) / static_cast<float>(numFrames);
    const auto height = static_cast<float>(texture.height);

    const Rectangle sourceRec = { static_cast<float>(currentFrame) * width, 0.0f, width, height };

    const Rectangle destRec = { position.x, position.y, width * scale, height * scale };

    const Vector2 origin = { (width * scale) / 2, (height * scale) / 2 };
    DrawTexturePro(texture, sourceRec, destRec, origin, 0.0f, WHITE);
}
