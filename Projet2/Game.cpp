#include "Game.h"   //Noah-erlos
#include <iostream>
#include <windows.h>

Game::Game() {}
Game::~Game() {}

Game& Game::getInstance() {
    static Game instance;
    return instance;
}

void Game::run() {
    if (!parser.load(1, level)) {
        std::cout << parser.getError() << std::endl;
        return;
    }

    draw();
}

void Game::draw() const {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            level.map.drawCell({ x, y });
        }
        std::cout << '\n';
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
}
