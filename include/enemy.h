#ifndef ENEMY
#define ENEMY

#include "draw.h"

void drawEnemy(Win *app, Entity *enemy);
int checkColision(Entity *player, Entity *enemy);

#endif /* !ENEMY */