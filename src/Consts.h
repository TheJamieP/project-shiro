#ifndef CONSTS_H
#define CONSTS_H

#define INIT_WIDTH 600
#define INIT_HEIGHT 600

#include "SDL3/SDL.h"

typedef struct {
    int x;
    int y;
} vec2;

typedef struct {
    int width;
    int height;
    SDL_Window* Window;
} WindowData;

typedef struct {
    SDL_Texture* Texture;
    SDL_FRect Rect;
    int scaleX;
    int scaleY;
} Entity;

typedef struct {
    size_t Size;
    int length;
    Entity *List;
}  EntityList;
#endif