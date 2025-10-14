#include <SDL3/SDL.h>
#include "./Consts.h"
#include <stdio.h>
#include "util/util.h"

Entity CreateEntity(int x, int y, int scaleX, int scaleY, char* PathToEntityBMP, SDL_Renderer* Renderer){
    dirPrint();
    SDL_Surface* Surface = SDL_LoadBMP(PathToEntityBMP);
    if(!Surface){
        fprintf(stderr, "Failed to create surface for entity or file not found: %s\n", SDL_GetError());
        return (Entity){};
    }
    SDL_Texture* Texture = SDL_CreateTextureFromSurface(Renderer, Surface);
    SDL_DestroySurface(Surface);

    return (Entity){Texture, (SDL_FRect){x,y, scaleX * Texture->w, scaleY * Texture->h}, scaleX, scaleY};
}