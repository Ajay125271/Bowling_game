#ifndef BOWLING_GAME_H
#define BOWLING_GAME_H

#include <string>
#include <vector>
#include <unordered_map>

class BowlingGame {
public:
    void loadScoresFromFile(const std::string& filename);
    void calculateScores();
    void printScores() const;

private:
    std::unordered_map<std::string, std::vector<int>> playerRolls;
    std::unordered_map<std::string, int> playerScores;

    int calculatePlayerScore(const std::vector<int>& rolls) const;
};

#endif
