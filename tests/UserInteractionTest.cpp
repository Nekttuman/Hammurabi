
#include "UserInteraction.hpp"

int userInteractionTest() {
    // UserInteraction::getAnswer<uint16_t>("Positive int input: ");
    UserInteraction::showGameStats(GameState{}, WorldActionsStats{}, "bob");

    return 0;
}
