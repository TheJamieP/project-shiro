#ifndef ENTITY_H

#include <SDL3/SDL.h>
#include <stdbool.h>
#include <Consts.h>

Entity CreateEntity(int x, int y, int scaleX, int scaleY, char* PathToEntityBMP, SDL_Renderer* Renderer);
#endif