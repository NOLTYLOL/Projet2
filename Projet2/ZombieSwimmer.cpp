#include "ZombieSwimmer.h"            //NoahD-M

ZombieSwimmer::ZombieSwimmer(Vector2 startPos) : Zombie(startPos)
{
    symbol = 'S';
    canSwin = true; 
}

void ZombieSwimmer::checkWater(Terrain currentTerrain)
{
    bool inWater = (currentTerrain == WATER);
}