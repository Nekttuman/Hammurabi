#pragma once

#include <print>

#include "GameData.hpp"
#include "UserInteraction.hpp"

using ui = UserInteraction;

class Game {
public:
    Game() : gameState_{0, 100, 1000, 0, 2800} {}

    void gameLoop() {
        while (gameState_.round < RoundsCount_) {
            ui::showGameStats(gameState_);

            auto moveData = ui::getMoveData();
            applyMove(moveData);
            worldActions();
            showGameState();

            ++gameState_.round;
        }
    }

    void applyMove(const MoveData& moveData) {}

    void worldActions() {
        harvest();
        rats();
    }

    void showGameState() {}

    bool isDefeat() {
        // TODO
        return false;
    }

private:
    void harvest();
    void rats();

private:
    GameState gameState_;
    const int RoundsCount_ = 10;

private:
    //! helper
};