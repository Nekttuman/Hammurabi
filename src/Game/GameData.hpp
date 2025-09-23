#pragma once

#include <cstdint>

struct MoveData {
    uint16_t buyAcres;
    uint16_t sellArces;
    uint16_t food;
    uint16_t seedArces;
};

struct GameState {
    int round;
    int population;
    int cityAcres;
    int acrePrice;
    int food;
};

enum class WorldActionType { Harvest, Rats };