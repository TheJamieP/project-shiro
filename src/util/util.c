#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "Consts.h"

bool FileExists(const char *filename){

    FILE *fp = fopen(filename, "r");
    
    if (fp != NULL) {
        fclose(fp);
        return true;
    }

    return false;
}

void dirPrint(){
    char *buffer;
    size_t size = 1024;

    buffer = (char *) malloc(size);
    if (buffer == NULL){
        perror("malloc failed");   
    }

    if (getcwd(buffer, size) != NULL){
        printf("Current DIR: %s\n", buffer);
    } else {
        perror("GetCWD error");
    }

    free(buffer);
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