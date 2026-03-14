//
// Created by ryanr on 14/03/2026.
//

#ifndef SIMULATION_TILES_H
#define SIMULATION_TILES_H
#include <map>
#include <utility>

#include "raylib.h"


class Tileset {
public:
    Texture2D texture;
    int numberOfRowTotal;
    int numberOfColumnTotal;
    std::map<int, std::pair<int, int>> tileDefs;

    Tileset(const Texture2D &texture, int numberOfRowTotal, int numberOfColumnTotal);

    ~Tileset();

    void initDefinitions();

    /**
     * Get rectangle from tile coordinates index and size
     * @param x index of Column (index 0, 1, 2...)
     * @param y index of row (index 0, 1, 2...)
     * @param numberOfColumn number of Column (défaut 1)
     * @param numberOfRow number of line (défaut 1)
     */
    [[nodiscard]] Rectangle GetRect(int x, int y, int numberOfColumn = 1, int numberOfRow = 1) const;

    Rectangle GetRect(int id) const;
};


#endif //SIMULATION_TILES_H