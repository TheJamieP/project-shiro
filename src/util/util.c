#include <stdbool.h>
#include <stdio.h>

bool FileExists(const char *filename){

    FILE *fp = fopen(filename, "r");
    
    if (fp != NULL) {
        fclose(fp);
        return true;
    }

    return false;
}