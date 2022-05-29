#include "input.h"
#include "window.h"


int input_handler(Entity *entity) {
    SDL_Event event;

    SDL_PollEvent(&event);

    switch (event.type) {

        case SDL_QUIT :
            return -1;

        case SDL_KEYDOWN:

            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    if (entity->pos_y - 17 > 0){
                        entity->pos_y -= 17;
                    }
                    
                    break;

                case SDLK_DOWN:
                    if (entity->pos_y + 17 + entity->height < WINDOW_HEIGHT){
                        entity->pos_y += 17;
                    }
                    break;
                    

                case SDLK_RIGHT:
                    if (entity->pos_x + 8 + entity->height < WINDOW_WIDTH){
                        entity->pos_x += 8;
                    }
                    break;
                    

                case SDLK_LEFT:

                    if (entity->pos_x - 8 > 0){
                        entity->pos_x -= 8;
                    }
                    break;
                    

                default:
                    break;
            }
            break;
            
        case SDL_KEYUP:

            break;
        
        default:
            break;
        }
    return 0;
}
