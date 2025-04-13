#include "BowlingGame.h"
#include <fstream>
#include <iostream>
#include <sstream>

void BowlingGame::loadScoresFromFile(const std::string& filename) {
    std::ifstream infile(filename);
    std::string line;

    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        std::string playerName;
        ss >> playerName;

        int pin;
        std::vector<int> rolls;
        while (ss >> pin) {
            rolls.push_back(pin);
        }
        playerRolls[playerName] = rolls;
    }
}

int BowlingGame::calculatePlayerScore(const std::vector<int>& rolls) const {
    int score = 0;
    int frame = 0;
    int i = 0;

    while (frame < 10 && i < rolls.size()) {
        if (rolls[i] == 10) {
            score += 10 + (i + 1 < rolls.size() ? rolls[i+1] : 0) + (i + 2 < rolls.size() ? rolls[i+2] : 0);
            i += 1;
        } else if (i + 1 < rolls.size() && rolls[i] + rolls[i+1] == 10) {
            score += 10 + (i + 2 < rolls.size() ? rolls[i+2] : 0);
            i += 2;
        } else {
            score += rolls[i] + (i + 1 < rolls.size() ? rolls[i+1] : 0);
            i += 2;
        }
        frame++;
    }

    return score;
}

void BowlingGame::calculateScores() {
    for (const auto& pair : playerRolls) {
        playerScores[pair.first] = calculatePlayerScore(pair.second);
    }
}

void BowlingGame::printScores() const {
    for (const auto& pair : playerScores) {
        std::cout << pair.first << ": " << pair.second << " points" << std::endl;
    }
}
