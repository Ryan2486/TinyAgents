//
// Created by ryanr on 14/03/2026.
//

#include "Tileset.h"

Tileset::Tileset(const Texture2D &texture, const int numberOfRowTotal, const int numberOfColumnTotal) : texture(texture), numberOfRowTotal(numberOfRowTotal), numberOfColumnTotal(numberOfColumnTotal) {
    initDefinitions();
}

Tileset::~Tileset() {
    UnloadTexture(texture);
}

void Tileset::initDefinitions() {
    tileDefs[0] = {0, 0}; // Haut Gauche
    tileDefs[1] = {1, 0}; // Haut Centre
    tileDefs[2] = {2, 0}; // Haut Droite

    tileDefs[3] = {0, 1}; // Milieu Gauche
    tileDefs[4] = {1, 1}; // PLEIN CENTRE (L'herbe standard)
    tileDefs[5] = {2, 1}; // Milieu Droite

    tileDefs[6] = {0, 2}; // Bas Gauche
    tileDefs[7] = {1, 2}; // Bas Centre
    tileDefs[8] = {2, 2}; // Bas Droite
}

Rectangle Tileset::GetRect(const int x, const int y, const int numberOfColumn, const int numberOfRow) const {
    const auto tileWidth = texture.width / numberOfColumnTotal;
    const auto tileHeight = texture.height / numberOfRowTotal;

    return Rectangle {
        static_cast<float>(x * tileWidth),
        static_cast<float>(y * tileHeight),
        static_cast<float>(numberOfColumn * tileWidth),
        static_cast<float>(numberOfRow * tileHeight)
    };
}

Rectangle Tileset::GetRect(const int id) const {
    if (tileDefs.contains(id)) {
        auto [row, col] = tileDefs.at(id);
        return GetRect(row, col);
    }

    return GetRect(0, 0);
}
