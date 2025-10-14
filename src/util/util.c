#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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