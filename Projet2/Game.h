#pragma once
#include "Map.h"
#include "Player.h"
#include "Enemy.h"

class Game {
public:
    static Game& getInstance();
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

private:
    Game();
    ~Game();
};
