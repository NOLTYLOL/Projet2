#pragma once   //Noah-erlos
#include <vector>
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

    void choosePlayerClass();
    bool loadLevel(int num);
    void spawnEnemies();
    void clearEnemies();
    Enemy* findEnemyAt(Vector2 pos) const;
    void drawCellOrEntity(int x, int y) const;
    void draw() const;
    bool tryMovePlayer(Vector2 dir);
    void playerTurn();
    bool tryMoveEnemy(Enemy* enemy, Vector2 dir);
    void enemiesTurn();

    LevelParser parser;
    LevelData level;
    Player* player = nullptr;
    std::vector<Enemy*> enemies;
    int currentLevel = 1;
    bool isMage = false;
};
