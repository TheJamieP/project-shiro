#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "./Consts.h"
#include "Events/Events.h"

int main()
{
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window* Window = SDL_CreateWindow("Shiro", INIT_WIDTH, INIT_HEIGHT, SDL_WINDOW_RESIZABLE); 

  if (!Window) {
      fprintf(stderr, "Failed to create window: %s\n", SDL_GetError());
      return -1;
  }
  
  SDL_Renderer* Renderer = SDL_CreateRenderer(Window, "gpu");
  if (!Renderer) {
      fprintf(stderr, "Failed to create renderer: %s\n", SDL_GetError());
      SDL_DestroyWindow(Window);
      return -1;
  }

  int Width = INIT_WIDTH;
  int Height = INIT_HEIGHT;
  WindowData WindowData = {Width, Height, Window};
  // SDL_Surface *Screen = SDL_GetWindowSurface(Window);
  


  while (handleEvents(&WindowData)) {
    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
    SDL_RenderClear(Renderer);
    SDL_RenderPresent(Renderer);
    SDL_Delay(10);
  }

  SDL_DestroyRenderer(Renderer);
  SDL_DestroyWindow(Window);
  return -1;
}
