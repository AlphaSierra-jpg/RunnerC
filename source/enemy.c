#include "enemy.h"

void drawEnemy(Win *app, Entity *enemy)
{
    SDL_Rect dest = {enemy->pos_x, enemy->pos_y, enemy->width, enemy->height};
    enemy->pos_x -= enemy->speed;

    if (enemy->pos_x < 0 ){
        enemy->pos_y = (rand() % (WINDOW_HEIGHT - 0 + 1)) + 0;
        enemy->pos_x = WINDOW_WIDTH;
        enemy->speed = (rand() % (10 - 3 + 1)) + 3;
    }
 
    SDL_RenderCopy(app->renderer, enemy->texture, NULL, &dest);
}

int checkColision(Entity *player, Entity *enemy) {
    SDL_Rect playerHitBox;
    SDL_Rect enemyHitBox;

    playerHitBox.x = player->pos_x;
    playerHitBox.y = player->pos_y;
    playerHitBox.w = player->width;
    playerHitBox.h = player->height;

    enemyHitBox.x = enemy->pos_x;
    enemyHitBox.y = enemy->pos_y;
    enemyHitBox.w = enemy->width;
    enemyHitBox.h = enemy->height;

    SDL_bool collision = SDL_HasIntersection(&playerHitBox, &enemyHitBox);
    if (collision){
        return 1;
    } else {
        return 0;
    }
    
}

void defineEnemy(Entity *enemy, Win *app)
{
    enemy->pos_x = WINDOW_WIDTH;
    enemy->pos_y = (rand() % (WINDOW_HEIGHT - 0 + 1)) + 0;
    enemy->width = 22;
    enemy->height = 16;
    enemy->texture = loadTexture(app, "ressource/obs.png");
    enemy->speed = (rand() % (10 - 3 + 1)) + 3;
}
