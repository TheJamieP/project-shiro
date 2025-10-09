#ifndef CONSTS_H
#define CONSTS_H

#define INIT_WIDTH 600
#define INIT_HEIGHT 600

typedef struct {
    int x;
    int y;
} vec2;

typedef struct {
    int width;
    int height;
    SDL_Window* Window;
} WindowData;
#endif