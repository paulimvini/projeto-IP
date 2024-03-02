#include "raylib.h"
#include "player.h"
#include "collision.h"
#include "platform.h"

void movePlayer(Player *player)
{
    // MOVIMENTOS DO JOGADOR
    // ESQUERDA
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    {
        (*player).playerPos.x -= 20;
    }
    // DIREITA
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        (*player).playerPos.x += 20;
    }
    // CASO O JOGADOR ULTRAPASSE A BORDA DIREITA
    if ((*player).playerPos.x > 600)
    {
        (*player).playerPos.x = 0; // teleporta para a esquerda
    }
    // CASO O JOGADOR ULTRAPASSE A BORDA ESQUERDA
    if ((*player).playerPos.x  < 0)
    {
        (*player).playerPos.x = 600; // teleporta para a direita
    }

    // Atualizar a posição da hitbox para corresponder à posição do jogador
    (*player).playerHitbox.x = (*player).playerPos.x;
    (*player).playerHitbox.y = (*player).playerPos.y;
}

// FUNÇÃO PARA PULO
void playerJump(Player *player, Platform *platforms)
{
    const float jumpHeight = 100.0f;

    // CHECAR SE O PLAYER TA NA PLATAFORMA
    if (playerOnPlatform(&player, platforms) && !player->isJumping)
    {
        player->playerPos.y -= jumpHeight;
        player->isJumping = true;
    }
    // SE NAO ESTA, VAI CAIR
    else
    {
        player->playerPos.y += GRAVITY;
    }
    // SE ESTA "PULANDO", SOBE
    if (player->isJumping)
    {
        player->playerPos.y -= jumpHeight;
        player->isJumping = false;
    }
}