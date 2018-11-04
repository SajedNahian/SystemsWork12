#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    char dir_path[500];

    if(argc < 2){
        printf("no command line argument found\n");

        // keep prompting unil user enters a directory name
        while(strlen(dir_path) == 0 || dir_path[0] == '\n'){
            printf("enter a directory name: \n");
            fgets(dir_path, sizeof(dir_path), stdin);
        }
    } else {
        strcpy(dir_path, argv[1]);
    }

    // printf("%s\n", dir_path);
    printf("\n");

    // remove newline from fgets
    if(dir_path[strlen(dir_path) - 1] == '\n'){
        dir_path[strlen(dir_path) - 1] = '\0';
    }

    printf("looking at %s/:\n", dir_path);  

    DIR * dir_stream = opendir(dir_path);

    if(!dir_stream) {
        printf("%s\n", strerror(errno));
        return -1; 
    }

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

    printf("Size of files in directory (%s/): %d bytes\n", dir_path, size);
    closedir(dir_stream);
    return 0;
}

