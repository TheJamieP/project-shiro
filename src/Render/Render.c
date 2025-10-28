#include <SDL3/SDL.h>
#include <stdbool.h>
#include <Consts.h>

void renderEntList(EntityList *Entities, SDL_Renderer *Renderer){
    for (int i = 0; i < Entities->length; i++){
        Entity Ent = Entities->List[i];
        SDL_RenderTexture(Renderer, Ent.Texture, NULL, &Ent.Rect);
    }
};