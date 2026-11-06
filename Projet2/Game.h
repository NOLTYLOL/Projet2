#pragma once
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "LevelParser.h"

class Game {
public:
    static Game& getInstance();
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    void run();

private:
    Game();
    ~Game();

    void draw() const;

    LevelParser parser;
    LevelData level;
};
