#pragma once

const int MAP_WIDTH = 22;
const int MAP_HEIGHT = 12;

enum Color {
    WHITE = 7,
    GRAY = 8,
    BLUE = 9,
    GREEN = 10,
    CYAN = 11,
    RED = 12,
    YELLOW = 14
};

enum Terrain {
    GROUND,
    WATER,
    MOUNTAIN,
    EXIT,
    WALL
};

struct Position {
    int x;
    int y;
};

class Map {
public:
    Map();
    ~Map();

    bool isInside(Position p) const;
    bool isExit(Position p) const;
    Terrain getCell(Position p) const;
    void setCell(Position p, Terrain terrain);
    void drawCell(Position p) const;

private:
    static char terrainToChar(Terrain terrain);
    static Color terrainToColor(Terrain terrain);

    Terrain cells[MAP_HEIGHT][MAP_WIDTH];
};
