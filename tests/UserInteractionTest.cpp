
#include "UserInteraction.hpp"

int userInteractionTest() {
    // UserInteraction::getAnswer<uint16_t>("Positive int input: ");
    UserInteraction::showGameStats(
        GameState{.round = 1, .population = 12, .cityAcres = 12, .acrePrice = 12, .food = 12});

    return 0;
}
