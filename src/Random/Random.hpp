#pragma once

#include <optional>
#include <random>


class Random {
public:
    Random(std::optional<unsigned int> seed = std::nullopt) {
        if (seed.has_value()) {
            gen.seed(seed.value());
        }
    }

    static int generateInRange(int min, int max) {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(gen);
    }

private:
    inline static std::mt19937 gen{};
    static std::uniform_int_distribution<int> dis;


};
