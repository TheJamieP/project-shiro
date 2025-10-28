#include <SDL3/SDL.h>
#include "./Consts.h"
#include <stdio.h>
#include "util/util.h"
#include <string.h>

Entity CreateEntity(int x, int y, int scaleX, int scaleY, char* PathToEntityBMP, SDL_Renderer* Renderer, char* EntityName){
    dirPrint();
    SDL_Surface* Surface = SDL_LoadBMP(PathToEntityBMP);
    if(!Surface){
        fprintf(stderr, "Failed to create surface for entity or file not found: %s\n", SDL_GetError());
        return (Entity){};
    }
    SDL_Texture* Texture = SDL_CreateTextureFromSurface(Renderer, Surface);
    SDL_DestroySurface(Surface);

    return (Entity){Texture, (SDL_FRect){x,y, scaleX * Texture->w, scaleY * Texture->h}, scaleX, scaleY, EntityName};
}

void RemoveEntityFromListByName(EntityList *EntList, char* EntName){
    if (!EntList) {
        printf("EntList is NULL\n");
        return;
    }
    if (!EntList->List) {
        printf("EntList->List is NULL\n");
        return;
    }

    printf("List length = %d\n", EntList->length);
    printf("%d\n", (EntList->List + 2)->Name != NULL);
    for (int i = 0; i < EntList->length; i++){
        printf("%d\n", i);
        if (strcmp((EntList->List + i)->Name, EntName) != 0) continue;
        printf("MATCHED NAME AT INDEX: %d\n", i);
        // shift left-over entities down
        for (int j = i + 1; j < EntList->length; j++){
            *(EntList->List + (j-1)) = *(EntList->List + j);
        }        
        EntList->length --;

        return;
    }
}

void AddEntityToList(EntityList *EntList, Entity Ent){

    Entity* Buffer = realloc(EntList->List,(EntList->length + 1) * sizeof(Ent));
    if (Buffer == NULL){
        perror("Buffer not allocated");
    }
    Buffer[EntList->length] = Ent;

    EntList->List = Buffer;
    EntList->length++;
}

EntityList *InitEntList(){
    EntityList *EntList = malloc(sizeof(EntityList));
    EntList->length = 0;
    EntList->List = malloc(EntList->length * sizeof(Entity));
    return EntList;
}