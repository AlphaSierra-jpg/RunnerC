#include "draw.h"

void prepareCanvas(Win *app)
{
    SDL_RenderClear(app->renderer);    
}

void drawBackGround(Win *app, int gameOver)
{   
    char* location;
    IMG_Init(IMG_INIT_PNG);
    if (gameOver == 1) {
        location = "ressource/gameOver.png";
    } else {
        location = "ressource/map.png";
    }
    SDL_Surface * image = IMG_Load(location);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(app->renderer, image);
    SDL_RenderCopy(app->renderer, texture, NULL, NULL);
}

void presentCanvas(Win *app)
{
    SDL_RenderPresent(app->renderer);
}

SDL_Texture *loadTexture(Win *app, char *img_path)
{
    SDL_Texture *texture;

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading: %s", img_path);
    texture = IMG_LoadTexture(app->renderer, img_path);
    if (texture == NULL)
    {
        printf("FAILED to load texture %s\n", IMG_GetError());
    }
    return texture;
}

void drawEntity(Win *app, Entity *entity)
{
    SDL_Rect dest = {entity->pos_x, entity->pos_y, entity->width, entity->height};

    SDL_RenderCopy(app->renderer, entity->texture, NULL, &dest);
}

void definePlayer(Entity *player, Win *app)
{
    player->pos_x = 100;
    player->pos_y = 100;
    player->width = 22;
    player->height = 16;
    player->texture = loadTexture(app, "ressource/player.png");
    player->speed = 0;
}