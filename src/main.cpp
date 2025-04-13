#include "BowlingGame.h"

int main() {
    BowlingGame game;
    game.loadScoresFromFile("tests/sample_input.txt");
    game.calculateScores();
    game.printScores();
    return 0;
}
