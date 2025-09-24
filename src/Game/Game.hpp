#pragma once

#include <algorithm>
#include <print>

#include "GameData.hpp"
#include "UserInteraction.hpp"

using ui = UserInteraction;

class Game {
public:
    Game() : gs_{gameStateDefaults} {}

    void gameLoop();

    [[__nodiscard__]] bool tryToApplyMove();

    void worldActions() {
        harvest();
        rats();
        feeding();
        populationIncrease();
        epidemic();
    }

    void defeat();
    void getValidMove();

private:
    void harvest();
    void rats();
    void feeding();
    void populationIncrease();
    void epidemic();

    void generateAcrePrice();

private:
    GameState gs_;
    bool defeat_ = false;
    WorldActionsStats ws_;
    MoveData move_;
    std::string userName_;

private:
    //! helper
};