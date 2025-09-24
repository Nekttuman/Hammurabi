

#include "Game.hpp"

#include <cmath>

#include "GameData.hpp"
#include "Random.hpp"

void Game::harvest() {
    ws_.foodPerAcre = Random::generateInRange(1, 6);
    auto canBeProduced = move_.seedArces * ws_.foodPerAcre;
    auto canBeObtained = gs_.population * 10;

    ws_.foodObtained = std::min(canBeObtained, canBeProduced);
    gs_.food += ws_.foodObtained;
}

void Game::rats() {
    int percentage = Random::generateInRange(0, 7);

    ws_.spoiledFood = static_cast<int>(std::ceil((percentage / 100.) * gs_.food));
    gs_.food -= ws_.spoiledFood;
}

void Game::feeding() {
    ws_.diedOfHunger = gs_.population - move_.food / 20;
    if (ws_.diedOfHunger > gs_.population * 0.45) {
        defeat();
        return;
    }

    if (ws_.diedOfHunger > 0) {
        gs_.population -= ws_.diedOfHunger;
    } else {
        ws_.diedOfHunger = 0;
    }
}

void Game::populationIncrease() {
    ws_.arrivedPeople = ws_.diedOfHunger / 2. + (5 - ws_.foodPerAcre) * gs_.food / 600. + 1;

    if (ws_.arrivedPeople < 0) ws_.arrivedPeople = 0;
    if (ws_.arrivedPeople > 50) ws_.arrivedPeople = 50;

    gs_.population += ws_.arrivedPeople;
}

void Game::epidemic() {
    if (Random::generateInRange(1, 100) > 15) {
        ws_.epidemic = false;
        return;
    }

    ws_.epidemic = true;

    gs_.population -= gs_.population / 2.;
}

void Game::defeat() {
    defeat_ = true;
    ui::defeatMessage();
}

void Game::getValidMove() {
    while (true) {
        move_ = ui::getMoveData(gs_);

        if (tryToApplyMove()) return;
        ui::showMoveNotValidInfo();
    }
}

bool Game::tryToApplyMove() {
    GameState newState = gs_;

    newState.food -= move_.buyAcres * ws_.foodPerAcre;
    newState.cityAcres += move_.buyAcres;
    newState.cityAcres -= move_.sellArces;
    newState.food += move_.sellArces * ws_.foodPerAcre;
    newState.food -= move_.food;
    newState.food -= move_.seedArces * 0.5;

    if (newState.food < 0 || newState.cityAcres < 0 || move_.seedArces > newState.cityAcres) return false;

    gs_ = std::move(newState);
    return true;
}

void Game::generateAcrePrice() { ws_.acrePrice = Random::generateInRange(17, 26); }

void Game::gameLoop() {
    while (gs_.round < RoundsCount_) {
        generateAcrePrice();
        if (gs_.round == 0) {
            userName_ = ui::getUserName();
            ui::sayHello(gs_, ws_);
        } else {
            ui::showGameStats(gs_, ws_, userName_);
        }

        getValidMove();
        worldActions();
        if (defeat_) return;

        ++gs_.round;
    }
}
