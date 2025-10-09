#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "Events.h"
#include "../Consts.h"

bool handleEvents(WindowData* WindowData){
    SDL_Event Event;
    while (SDL_PollEvent(&Event))
    {
        switch (Event.type)
        {
            case SDL_EVENT_QUIT:
                return false;
            break;
        
            case SDL_EVENT_WINDOW_RESIZED:
                printf("%s\n", "resized");
                SDL_GetWindowSize(WindowData->Window, &WindowData->width, &WindowData->height);
                printf("%d,%d\n", WindowData->width, WindowData->height);
            break;
        }
        
        
    }
    return true;
}