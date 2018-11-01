#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    char * DIR_PATH = ".";
    DIR * dir_stream = opendir(DIR_PATH);
    struct dirent * cur = readdir(dir_stream);

    int size = 0;
    struct stat * buffer = malloc(sizeof(struct stat));

    while (cur != NULL) {
        char filePath[256];
        strcpy(filePath, "./");
        strcat(filePath, cur->d_name);
        stat(filePath, buffer);
        //printf("%d", cur->d_type);
        //printf("size of %s: %ld\n", cur->d_name, buffer->st_size);
        size += buffer -> st_size;

        printf("%s", cur->d_name);
        if (cur -> d_type == 4) {
            printf(" (Directory)");
        }
        printf("\n");

        cur = readdir(dir_stream);
    }

    printf("Size of files in directory (%s/): %d bytes\n", DIR_PATH, size);
    closedir(dir_stream);
    return 0;
}

