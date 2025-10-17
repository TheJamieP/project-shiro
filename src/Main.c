#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "./Consts.h"
#include "Events/Events.h"
#include "./Entity/Entity.h"
#include "./util/util.h"

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
  
  EntityList *EntList = InitEntList();
  Entity Test = CreateEntity(200, 220, 1, 1, "./assets/Entities/Test1.bmp", Renderer);
  
  AddEntityToList(EntList,Test);
  AddEntityToList(EntList, CreateEntity(0, 0, 1, 1, "./assets/Entities/Test2.bmp", Renderer));
  AddEntityToList(EntList, CreateEntity(200, 0, 1, 1, "./assets/Entities/Test3.bmp", Renderer));
  AddEntityToList(EntList, CreateEntity(400, 0, 1, 1, "./assets/Entities/Test4.bmp", Renderer));

  while (handleEvents(&WindowData)) {
    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
    // SDL_RenderTexture(Renderer, Test.Texture, NULL, &Test.Rect);

    SDL_RenderPresent(Renderer);
    SDL_Delay(10);
  }

  SDL_DestroyRenderer(Renderer);
  free(EntList);
  SDL_DestroyWindow(Window);
  return -1;
}
