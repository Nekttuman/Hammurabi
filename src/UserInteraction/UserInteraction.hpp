#pragma once

#include <cassert>
#include <format>
#include <iostream>
#include <map>
#include <print>

#include "GameData.hpp"

class UserInteraction {
public:
    template <class T>
    static T getAnswer(const std::string& question) {
        if constexpr (std::is_same_v<T, uint16_t>) {
            return getUnsignedInt(question);
        }

        std::println("not supported type passed {}", typeid(T).name());
        assert(false);
        return T{};
    }

    static void showGameStats(const GameState& gs) {
        std::println(
            "Шел {} год правления фараона {}.\n\tНаселение города составляет {} человек \n\tВ запасах имеется "
            "{} бушелей пшеницы.\n\tЦена акра земли в этом году {} дебенов.\n\tГород владеет {} акрами земли.",
            gs.round, "UserName", gs.population, gs.food, gs.acrePrice, gs.cityAcres);
    }

    template <class... T>
    static void showActionInfo(WorldActionType type, const T&... args) {
        std::print("{}\n", std::vformat(actionToMsg.at(type), std::make_format_args(args...)));
    }

    static MoveData getMoveData() {
        MoveData newMove;

        newMove.buyAcres = getAnswer<uint16_t>("Сколько акров земли вы хотите купить? ");
        newMove.sellArces = getAnswer<uint16_t>("Сколько акров земли вы хотите продать? ");
        newMove.food = getAnswer<uint16_t>("Сколько бушелей пшеницы вы отдадите населению? ");
        newMove.seedArces = getAnswer<uint16_t>("Сколько акров земли вы хотите засеять пшеницей? ");

        return newMove;
    }

private:
    static uint16_t getUnsignedInt(const std::string& prompt) {
        int value;
        while (true) {
            std::print("{}", prompt);
            if (std::cin >> value && value >= 0) {
                return value;
            } else {
                std::println("Ошибка: введите неотрицательное целое число.");
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }

    inline const static std::map<WorldActionType, std::string> actionToMsg = {
        {WorldActionType::Harvest,
         "Урожай в этом году составил {} бушелей пшеницы, урожайность нынче {} бушелей с акра"},
        {WorldActionType::Rats, "Крысы пожрали {} бушелей пшеницы, итого в закромах осталось {} бушелей"},
    };

};  // namespace UserInteraction