#include "Game.h"   //Noah-erlos
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <windows.h>
#include "Warrior.h"
#include "Mage.h"
#include "Zombie.h"
#include "HeadlessZombie.h"

Game::Game() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
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
    for (size_t i = 0; i < enemies.size(); i++) {
        delete enemies[i];
    }
    enemies.clear();
}

void Game::choosePlayerClass() {
    std::system("cls");
    std::cout << "Choisis ta classe :\n";
    std::cout << "1 - Warrior (5 PV, tue les ennemis au contact)\n";
    std::cout << "2 - Mage (1 PV, Espace = sort autour de lui)\n";
    char choix = 0;
    while (choix != '1' && choix != '2') {
        choix = static_cast<char>(_getch());
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
    for (size_t i = 0; i < level.enemies.size(); i++) {
        Position p = level.enemies[i].pos;
        char type = level.enemies[i].type;
        Vector2 startPos = { p.x, p.y };
        if (type == 'h' || (type == 'X' && i % 2 == 1)) {
            enemies.push_back(new HeadlessZombie(startPos));
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
    for (size_t i = 0; i < enemies.size(); i++) {
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

void Game::showSpellEffect() const {
    Vector2 center = player->GetPosition();
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, CYAN);
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            Vector2 p = { center.x + dx, center.y + dy };
            if ((dx != 0 || dy != 0) && level.map.isInside({ p.x, p.y })) {
                COORD coord = { static_cast<SHORT>(p.x), static_cast<SHORT>(p.y) };
                SetConsoleCursorPosition(console, coord);
                std::cout << '*';
            }
        }
    }
    Sleep(180);
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
        player->SetPosition(newPos);
    }
    return true;
}

void Game::playerTurn() {
    while (true) {
        int code = _getch();
        if (code == 0 || code == 224) {
            _getch();
            continue;
        }
        char touche = static_cast<char>(code);
        if (player->handleSpecialAction(touche, enemies)) {
            showSpellEffect();
            return;
        }
        if (tryMovePlayer(player->getDirection(touche))) {
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
    enemy->SetPosition(newPos);
    return true;
}

void Game::moveSingleEnemy(Enemy* enemy) {
    Vector2 playerPos = player->GetPosition();
    for (int essai = 0; essai < 4; essai++) {
        Vector2 dir = enemy->getDirection(playerPos);
        if (tryMoveEnemy(enemy, dir)) {
            return;
        }
        if (enemy->getSymbol() == 'Z') {
            Vector2 pos = enemy->GetPosition();
            int dy = (playerPos.y > pos.y) ? 1 : ((playerPos.y < pos.y) ? -1 : 0);
            tryMoveEnemy(enemy, { 0, dy });
            return;
        }
    }
}

void Game::enemiesTurn() {
    for (size_t i = 0; i < enemies.size(); i++) {
        if (enemies[i]->IsAlive() && player->IsAlive()) {
            moveSingleEnemy(enemies[i]);
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
