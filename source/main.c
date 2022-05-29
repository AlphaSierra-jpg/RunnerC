#include <stdio.h>
#include "window.h"
#include "input.h"
#include "draw.h"
#include "init.h"
#include "enemy.h"


int main()
{   
    int gameOver = 0;

    Win *app = malloc(sizeof(Win));
    Entity *player = malloc(sizeof(Entity));
    Entity *enemy1 = malloc(sizeof(Entity));
    Entity *enemy2 = malloc(sizeof(Entity));
    Entity *enemy3 = malloc(sizeof(Entity));


    if (initSDL(app) < 0)
    {
        return -1;
    }

    player->pos_x = 100;
    player->pos_y = 100;
    player->width = 22;
    player->height = 16;
    player->texture = loadTexture(app, "ressource/player.png");
    player->speed = 0;

    enemy1->pos_x = WINDOW_WIDTH;
    enemy1->pos_y = (rand() % (WINDOW_HEIGHT - 0 + 1)) + 0;
    enemy1->width = 22;
    enemy1->height = 16;
    enemy1->texture = loadTexture(app, "ressource/obs.png");
    enemy1->speed = 3;

    enemy2->pos_x = WINDOW_WIDTH;
    enemy2->pos_y = (rand() % (WINDOW_HEIGHT - 0 + 1)) + 0;
    enemy2->width = 22;
    enemy2->height = 16;
    enemy2->texture = loadTexture(app, "ressource/obs.png");
    enemy2->speed = 4;

    enemy3->pos_x = WINDOW_WIDTH;
    enemy3->pos_y = (rand() % (WINDOW_HEIGHT - 0 + 1)) + 0;
    enemy3->width = 22;
    enemy3->height = 16;
    enemy3->texture = loadTexture(app, "ressource/obs.png");
    enemy3->speed = 5;

    while (input_handler(player) == 0 && gameOver == 0)
    {   
    
        prepareCanvas(app);
        drawBackGround(app, gameOver);
        drawEntity(app, player);

        drawEnemy(app, enemy1);
        drawEnemy(app, enemy2);
        drawEnemy(app, enemy3);
        drawEnemy(app, enemy1);
        drawEnemy(app, enemy2);
        drawEnemy(app, enemy3);

        if (checkColision(player, enemy1) == 1 || checkColision(player, enemy2) == 1 || checkColision(player, enemy3) == 1) {
            gameOver = 1;
        }
        
        presentCanvas(app);
        SDL_Delay(16);
    };

    drawBackGround(app, gameOver);

    presentCanvas(app);
    SDL_Delay(3000);
    return 0;
}


