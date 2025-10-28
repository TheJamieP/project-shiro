#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "Events.h"
#include "../Consts.h"
#include "Entity/Entity.h"

bool handleEvents(WindowData* WindowData){
    SDL_Event Event;
    while (SDL_PollEvent(&Event))
    {
        switch (Event.type)
        {
            case SDL_EVENT_KEY_DOWN:
                switch (Event.key.key){
                    case SDLK_6:
                        printf("6 pressed\n");
                        
                        RemoveEntityFromListByName(WindowData->EntList, "Test2");
                        return true;
                    break;
                }

            case SDL_EVENT_QUIT:
                return false;
            break;
        
            case SDL_EVENT_WINDOW_RESIZED:
                SDL_GetWindowSize(WindowData->Window, &WindowData->width, &WindowData->height);
                return true;
            break;
        }
        
        
    }
    return true;
}