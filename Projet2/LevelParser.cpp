#include "LevelParser.h"

namespace {
    const std::string MAPS_FOLDER = "maps/";

    bool charToTerrain(char c, Terrain& terrain) {
        if (c == '.')      terrain = GROUND;
        else if (c == '~') terrain = WATER;
        else if (c == 'A') terrain = MOUNTAIN;
        else if (c == '#') terrain = WALL;
        else if (c == 'E') terrain = EXIT;
        else               return false;
        return true;
    }

    bool isEnemyChar(char c) {
        return c == 'X' || c == 'Z' || c == 'h' || c == 'S';
    }
}

LevelParser::LevelParser() : heroCount(0), exitCount(0) {}

bool LevelParser::levelExists(int levelNumber) const {
    std::ifstream file(getLevelPath(levelNumber));
    return file.is_open();
}

bool LevelParser::load(int levelNumber, LevelData& level) {
    std::ifstream file(getLevelPath(levelNumber));
    if (!file.is_open()) {
        return fail("Impossible d'ouvrir " + getLevelPath(levelNumber));
    }
    heroCount = 0;
    exitCount = 0;
    error = "";
    level.enemies.clear();

    std::string line;
    for (int y = 0; y < MAP_HEIGHT; y++) {
        if (!std::getline(file, line)) {
            return fail("Il manque des lignes : le fichier en a " + std::to_string(y)
                + " au lieu de " + std::to_string(MAP_HEIGHT) + ".");
        }
        if (!parseLine(line, y, level)) {
            return false;
        }
    }
    return checkNoExtraLines(file) && checkCounts();
}

const std::string& LevelParser::getError() const {
    return error;
}

std::string LevelParser::getLevelPath(int levelNumber) const {
    return MAPS_FOLDER + "level" + std::to_string(levelNumber) + ".txt";
}

bool LevelParser::parseLine(const std::string& line, int y, LevelData& level) {
    int length = static_cast<int>(line.size());
    if (length != MAP_WIDTH) {
        return fail("Ligne " + std::to_string(y + 1) + " : " + std::to_string(length)
            + " caracteres au lieu de " + std::to_string(MAP_WIDTH) + ".");
    }
    for (int x = 0; x < MAP_WIDTH; x++) {
        if (!parseChar(line[x], { x, y }, level)) {
            return false;
        }
    }
    return true;
}

bool LevelParser::parseChar(char c, Position p, LevelData& level) {
    Terrain terrain;
    if (charToTerrain(c, terrain)) {
        level.map.setCell(p, terrain);
        if (terrain == EXIT) {
            exitCount++;
        }
        return true;
    }
    level.map.setCell(p, GROUND);
    if (c == 'H') {
        level.playerStart = p;
        heroCount++;
        return true;
    }
    if (isEnemyChar(c)) {
        level.enemies.push_back({ p, c });
        return true;
    }
    return fail("Ligne " + std::to_string(p.y + 1)
        + ", colonne " + std::to_string(p.x + 1)
        + " : caractere invalide '" + std::string(1, c) + "'.");
}

bool LevelParser::checkNoExtraLines(std::ifstream& file) {
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            return fail("Le fichier a plus de " + std::to_string(MAP_HEIGHT)
                + " lignes.");
        }
    }
    return true;
}

bool LevelParser::checkCounts() {
    if (heroCount != 1) {
        return fail("Il faut exactement un H (trouve : "
            + std::to_string(heroCount) + ").");
    }
    if (exitCount != 1) {
        return fail("Il faut exactement un E (trouve : "
            + std::to_string(exitCount) + ").");
    }
    return true;
}

bool LevelParser::fail(const std::string& message) {
    error = message;
    return false;
}
