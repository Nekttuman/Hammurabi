#include "Game.hpp"


#include "GameData.hpp"
#include "Random.hpp"

#include <cmath> 

void Game::harvest() {
    int foodPerAcre = Random::generateInRange(1, 6);

    auto harvest = gameState_.cityAcres * foodPerAcre;
    gameState_.food += harvest;
    ui::showActionInfo(WorldActionType::Harvest,  harvest, gameState_.food);
}


void Game::rats() {
    int percentage = Random::generateInRange(0, 7);

    auto spoiled = static_cast<int>(std::ceil((percentage/100.) * gameState_.food));
    gameState_.food += gameState_.food - spoiled;
    ui::showActionInfo(WorldActionType::Rats, spoiled, gameState_.food);
}
