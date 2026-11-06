#pragma once    //Noah-erlos
#include <fstream>
#include <string>
#include <vector>
#include "Map.h"

struct EnemySpawn {
    Position pos;
    char type;
};

struct LevelData {
    Map map;
    Position playerStart;
    std::vector<EnemySpawn> enemies;
};

class LevelParser {
public:
    LevelParser();

    bool levelExists(int levelNumber) const;
    bool load(int levelNumber, LevelData& level);
    const std::string& getError() const;

private:
    std::string getLevelPath(int levelNumber) const;
    bool parseLine(const std::string& line, int y, LevelData& level);
    bool parseChar(char c, Position p, LevelData& level);
    bool checkNoExtraLines(std::ifstream& file);
    bool checkCounts();
    bool fail(const std::string& message);

    int heroCount;
    int exitCount;
    std::string error;
};
