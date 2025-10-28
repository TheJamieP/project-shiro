#ifndef ENTITY_H

#include <SDL3/SDL.h>
#include <stdbool.h>
#include <Consts.h>
#include <string.h>

Entity CreateEntity(int x, int y, int scaleX, int scaleY, char* PathToEntityBMP, SDL_Renderer* Renderer, char* EntityName);
EntityList *InitEntList();
void AddEntityToList(EntityList *EntList, Entity Ent);

void RemoveEntityFromListByName(EntityList *EntList, char* EntName);

#endif