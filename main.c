#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include "user.h"

#define MAX_TITLE 100
#define MAX_BODY 1000
#define MAX_DATE 30
#define NOTES_DIR "/Users/jayaharshm/notes"

typedef struct {
    int id;
    char title[MAX_TITLE];
    char body[MAX_BODY];
    char date[MAX_DATE];
} Note;

void print_all_dir() {
    DIR *dir = opendir(NOTES_DIR);
    struct dirent *entry;
    
    while((entry = readdir(dir)) != NULL){
        char *name = entry->d_name;
        if(name[0] == '.') {
            continue;
        }
        printf("%s\n", name);
    }
    closedir(dir);
}

int main() {
    // welcome message
    printf("<<<Hello Welcome to Jote the Personal Note taking terminal App>>>\n");
    print_all_dir();

    return 0;
}

