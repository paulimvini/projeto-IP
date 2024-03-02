#include "collision.h"

bool playerOnPlatform(Player **player, Platform *platforms)
{
    for (int i = 0; i < PLATFORMS_NUMBER; i++)
    {
        if (CheckCollisionRecs((*(*player)).playerHitbox, platforms[i].platformHitbox))
        {
            // SE TIVER RETORNAR VERDADEIRO
            return true;
        }
    }
    return false;
}
