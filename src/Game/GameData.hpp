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
    int food;
};

struct WorldActionsStats {
    int arrivedPeople;
    int diedOfHunger;

    int acrePrice;
    int foodPerAcre;
    int foodObtained;

    int spoiledFood;

    bool epidemic;
};

const GameState gameStateDefaults = {0, 100, 1000, 2800};
const int RoundsCount_ = 10;

enum class WorldActionType { Harvest, Rats, Feeding, PopulationIncrease, Epidemic };