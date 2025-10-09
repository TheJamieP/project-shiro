#include <SDL3/SDL.h>
#include "./Consts.h"
#include <stdio.h>

Entity CreateEntity(int x, int y, char* PathToEntityBMP, SDL_Renderer* Renderer){
    SDL_Surface* Surface = SDL_LoadBMP(PathToEntityBMP);
    if(!Surface){
        fprintf(stderr, "Failed to create surface for entity: %s\n", SDL_GetError());
        return (Entity){};
    }
    SDL_Texture* Texture = SDL_CreateTextureFromSurface(Renderer, Surface);
    SDL_DestroySurface(Surface);

    return (Entity){x,y,Texture};
}