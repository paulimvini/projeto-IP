#include "raylib.h"
#include "platform.h"

void generatePlatforms(Platform *platforms)
{
    int maxPlatformHeight = 1000;

    for (int i = 0; i < PLATFORMS_NUMBER; i++)
    {
        Rectangle tempRandomPlatform = { GetRandomValue(0, 600), maxPlatformHeight -= 50, 50, 10};
        platforms[i].platformHitbox = tempRandomPlatform;
    }
}
