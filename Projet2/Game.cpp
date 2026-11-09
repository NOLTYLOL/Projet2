#include "Game.h"   //Noah-erlos   //NoahD-M   //Gilio
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <windows.h>
#include "Warrior.h"
#include "Mage.h"
#include "Zombie.h"
#include "HeadlessZombie.h"
#include "ZombieSwimmer.h"

Game::Game() {
    std::srand(std::time(nullptr));
}

Game::~Game() {
    clearEnemies();
    delete player;
}

Game& Game::getInstance() {
    static Game instance;
    return instance;
}

void Game::clearEnemies() {
    for (int i = 0; i < enemies.size(); i++) {
        delete enemies[i];
    }
    enemies.clear();
}

void Game::choosePlayerClass() {
    std::system("cls");
    std::cout << "Choisis ta classe :\n";
    std::cout << "1 - Warrior (5 PV, tue les ennemis au contact)\n";
    std::cout << "2 - Mage (1 PV, E = sort autour de lui)\n";
    char choix = 0;
    while (choix != '1' && choix != '2') {
        choix = _getch();
    }
    delete player;
    isMage = (choix == '2');
    if (isMage) {
        player = new Mage();
    } else {
        player = new Warrior();
    }
}

void Game::spawnEnemies() {
    clearEnemies();
    for (int i = 0; i < level.enemies.size(); i++) {
        Position p = level.enemies[i].pos;
        char type = level.enemies[i].type;
        Vector2 startPos = { p.x, p.y };
        if (type == 'h') {
            enemies.push_back(new HeadlessZombie(startPos));
        } else if (type == 'S') {
            enemies.push_back(new ZombieSwimmer(startPos));
        } else {
            enemies.push_back(new Zombie(startPos));
        }
    }
}

bool Game::loadLevel(int num) {
    if (!parser.load(num, level)) {
        std::cout << parser.getError() << std::endl;
        return false;
    }
    player->SetPosition({ level.playerStart.x, level.playerStart.y });
    spawnEnemies();
    return true;
}

Enemy* Game::findEnemyAt(Vector2 pos) const {
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies[i]->IsAlive() && enemies[i]->GetPosition() == pos) {
            return enemies[i];
        }
    }
    return nullptr;
}

void Game::drawCellOrEntity(int x, int y) const {
    Vector2 pos = { x, y };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (player->GetPosition() == pos) {
        SetConsoleTextAttribute(console, YELLOW);
        std::cout << 'H';
        return;
    }
    Enemy* enemy = findEnemyAt(pos);
    if (enemy != nullptr) {
        SetConsoleTextAttribute(console, RED);
        std::cout << enemy->getSymbol();
        return;
    }
    level.map.drawCell({ x, y });
}

void Game::draw() const {
    std::system("cls");
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            drawCellOrEntity(x, y);
        }
        std::cout << '\n';
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    std::cout << "Niveau: " << currentLevel << " | PV: " << player->getLife()
              << " | ZQSD: Bouger";
    if (isMage) {
        std::cout << " | E: Sort";
    }
    std::cout << '\n';
}

bool Game::tryMovePlayer(Vector2 dir) {
    if (dir.x == 0 && dir.y == 0) {
        return false;
    }
    Vector2 newPos = player->GetPosition() + dir;
    if (!level.map.isWalkable({ newPos.x, newPos.y }, player->canSwin)) {
        return false;
    }
    Enemy* enemy = findEnemyAt(newPos);
    if (enemy != nullptr) {
        player->onCollision(*enemy);
    }
    if (player->IsAlive() && findEnemyAt(newPos) == nullptr) {
        player->movement(dir);
    }
    return true;
}

void Game::playerTurn() {
    while (true) {
        char touche = _getch();
        if (player->handleSpecialAction(touche, enemies)) {
            return;
        }
        Vector2 dir = player->getDirection(touche);
        if (tryMovePlayer(dir)) {
            return;
        }
    }
}

bool Game::tryMoveEnemy(Enemy* enemy, Vector2 dir) {
    if (dir.x == 0 && dir.y == 0) {
        return false;
    }
    Vector2 newPos = enemy->GetPosition() + dir;
    if (!level.map.isWalkable({ newPos.x, newPos.y }, enemy->canSwin)) {
        return false;
    }
    if (findEnemyAt(newPos) != nullptr) {
        return false;
    }
    if (newPos == player->GetPosition()) {
        player->onCollision(*enemy);
        return true;
    }
    enemy->movement(dir);
    return true;
}

void Game::enemiesTurn() {
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies[i]->IsAlive() && player->IsAlive()) {
            Vector2 dir = enemies[i]->getDirection(player->GetPosition());
            tryMoveEnemy(enemies[i], dir);
        }
    }
}

void Game::run() {
    choosePlayerClass();
    if (!loadLevel(currentLevel)) {
        return;
    }
    while (player->IsAlive()) {
        draw();
        playerTurn();
        if (!player->IsAlive()) {
            break;
        }
        Vector2 p = player->GetPosition();
        if (level.map.isExit({ p.x, p.y })) {
            currentLevel++;
            if (!parser.levelExists(currentLevel)) {
                draw();
                std::cout << "==== VICTOIRE ! ====\n";
                return;
            }
            loadLevel(currentLevel);
        } else {
            enemiesTurn();
        }
    }
    draw();
    player->Playerdeath();
}
