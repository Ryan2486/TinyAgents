//
// Created by ryanr on 13/03/2026.
//

#include "utils.h"

#include <cmath>

float utils::GetDistance(const Vector2 &a, const Vector2 &b) {
    const float dx = b.x - a.x;
    const float dy = b.y - a.y;
    return std::sqrt(dx * dx + dy * dy);
}