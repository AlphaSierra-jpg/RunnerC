#include <stdio.h>
#include "window.h"
#include "input.h"
#include "draw.h"
#include "init.h"
#include "enemy.h"


int main()
{   
    int gameOver = 0;

    Env *env = malloc(sizeof(Env));
    Win *app = malloc(sizeof(Win));
    Entity *player = malloc(sizeof(Entity));
    Entity *enemy1 = malloc(sizeof(Entity));
    Entity *enemy2 = malloc(sizeof(Entity));
    Entity *enemy3 = malloc(sizeof(Entity));


    if (initSDL(app) < 0)
    {
        return -1;
    }   

    env->isPause = 0;

    definePlayer(player, app);
    defineEnemy(enemy1, app);
    defineEnemy(enemy2, app);
    defineEnemy(enemy3, app);


    while ((input_handler(player, env) == 0 || input_handler(player) ==1) && gameOver == 0)
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
    
        while (env->isPause == 1){
            input_handler(player, env);
            SDL_Delay(20);
        }
        
        presentCanvas(app);
        SDL_Delay(16);
    };
    prepareCanvas(app);
    
    drawBackGround(app, gameOver);

    presentCanvas(app);
    SDL_Delay(3000);

    return 0;
}


