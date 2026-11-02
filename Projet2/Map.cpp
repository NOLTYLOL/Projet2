#include "Map.h"
#include <iostream>
#include <windows.h>

Map::Map() {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            cells[y][x] = GROUND;
        }
    }
}

Map::~Map() {}

bool Map::isInside(Position p) const {
    return p.x >= 0 && p.x < MAP_WIDTH && p.y >= 0 && p.y < MAP_HEIGHT;
}

bool Map::isExit(Position p) const {
    return getCell(p) == EXIT;
}

Terrain Map::getCell(Position p) const {
    return cells[p.y][p.x];
}

void Map::setCell(Position p, Terrain terrain) {
    cells[p.y][p.x] = terrain;
}

void Map::drawCell(Position p) const {
    Terrain terrain = getCell(p);
    WORD color = static_cast<WORD>(terrainToColor(terrain));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    std::cout << terrainToChar(terrain);
}

char Map::terrainToChar(Terrain terrain) {
    if (terrain == WATER)    return '~';
    if (terrain == MOUNTAIN) return 'A';
    if (terrain == EXIT)     return 'E';
    if (terrain == WALL)     return '#';
    return static_cast<char>(-6);
}

Color Map::terrainToColor(Terrain terrain) {
    if (terrain == GROUND)   return GREEN;
    if (terrain == WATER)    return BLUE;
    if (terrain == MOUNTAIN) return GRAY;
    if (terrain == EXIT)     return CYAN;
    return WHITE;
}
