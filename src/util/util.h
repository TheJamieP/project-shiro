#ifndef UTIL_H

#include <stdbool.h>

bool FileExists(const char *filename);
void dirPrint();
EntityList *InitEntList();
void AddEntityToList(EntityList *EntList, Entity Ent);
#endif