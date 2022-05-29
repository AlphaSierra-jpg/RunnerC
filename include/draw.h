#ifndef DRAW
#define DRAW

#include "window.h"
#include <SDL2/SDL_image.h>

typedef struct
{
    int pos_x;
    int pos_y;
    int width;
    int height;
    SDL_Texture *texture;
    int speed;
} Entity;

void prepareCanvas(Win *app);
void presentCanvas(Win *app);
void drawBackGround(Win *app, int gameOver);
SDL_Texture *loadTexture(Win *app, char *img_path);
void drawEntity(Win *app, Entity *entity);


#endif /* !DRAW */