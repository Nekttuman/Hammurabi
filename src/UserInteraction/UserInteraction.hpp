#pragma once

#include <cassert>
#include <cstdint>
#include <format>
#include <iostream>
#include <map>
#include <optional>
#include <print>

#include "GameData.hpp"

class UserInteraction {
public:
    static void showGameStats(const GameState& gs, const WorldActionsStats& ws, const std::string& userName) {
        std::println("\nВ {} году правления председателя правительства Дальневосточной Республики, {}:", gs.round,
                     userName);

        std::println(
            "\t{} товарищей скончалось от недостатка провизии, и {} примкнуло к нашей державе ради строительства "
            "светлого будущего",
            ws.diedOfHunger, ws.arrivedPeople);
        if (ws.epidemic) {
            std::println(
                "\tИз Китая пришел новый штамм вируса! Наши ученые успели разработать вакцину, но половина населения "
                "стали жертвой вируса");
        }
        std::println("\tНаселение республики составляет {} человек", gs.population);
        std::println(
            "\tНеустанным трудом колхозов было собрано {} центнеров сои, по {} центнера с гектара. Невиданная "
            "урожайность!",
            ws.foodObtained, ws.foodPerAcre);
        std::println("\tДикие манчжуры попортили {} центнеров сои, итого в закромах осталось {} центнеров",
                     ws.spoiledFood, gs.food);

        std::println("\tПлощадь имеющихся территорий сейчас: {} гектаров", gs.cityAcres);
        std::println(
            "\tДля возделывания земли придется продать по {} центнеров сои за гектар дружественным государствам",
            ws.acrePrice);
    }

    static std::string getUserName() {
        std::println("Назовите свое полное имя товарищ.");
        std::cin.clear();
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::string name;
        std::cin >> name;
        return name;
    }

    static MoveData getMoveData(const GameState& gs) {
        MoveData newMove;

        newMove.buyAcres = getInt("\n\tСколько гектаров земли вы хотите купить? ");
        newMove.sellArces = getInt("\tСколько гектаров земли вы хотите продать? ");
        newMove.food = getInt("\tСколько центнеров сои вы отдадите населению? ");
        newMove.seedArces = getInt("\tСколько гектаров земли вы хотите засеять соей? ");

        return newMove;
    }

    static void defeatMessage() {
        // TODO
        std::print("Вы проиграли!");
    }

    static void sayHello(const GameState& gs, const WorldActionsStats& ws) {
        std::println(
            "Преветствую товарищ! Президиум народно-революционной власти Дальневосточной республики избрал вас своим "
            "председателем! "
            "Позвольте доложить о состоянии дел на текущий момент в стране.\n\tНаселение ДВР: {}\n\tГектары "
            "возделываемой почвы: {}\n\tЗапасы сои в центнерах: {}\n\tЦена гектара земли: {} центнеров сои\nСлужу "
            "Дальневосточной республике!\n\nОт вас "
            "требуется "
            "составить план развития на следующий год.",
            gs.population, gs.cityAcres, gs.food, ws.acrePrice);
    }

    static void showMoveNotValidInfo() { std::println("Сои недостаточно для подобного стратегического решения!"); }

private:
    static int getInt(const std::string& prompt) {
        int value;
        while (true) {
            std::print("{}", prompt);
            if (std::cin >> value) {
                return value;
            } else {
                std::println(
                    "Товарищ председатель! следуйте должностной инструкции: введите неотрицательное целое число.");
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }

};  // namespace UserInteraction