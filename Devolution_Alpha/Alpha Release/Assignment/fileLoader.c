//
//  fileLoader.c
//  Assignment
//
//  Created by Marcus Anderson on 5/2/19.
//  Copyright © 2019 CodeBound. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "fileLoader.h"
#include "mylib.h"

char* concat(const char *s1, const char *s2){
    char *result = emalloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    if(result == NULL){
        perror("Error! Can't malloc\n");
        exit(1);
    }else {
        // in real code you would check for errors in malloc here
        strcpy(result, s1);
        strcat(result, s2);
        return result;
    }
}

//Get the current directory
char* current_directory(char *cwd){
    if (getcwd(cwd, sizeof(char) * 200) != NULL) {
        //printf("Current working dir: %s\n", cwd);
        return cwd;
    } else {
        perror("getcwd() error");
        return NULL;
    }
}

//Open file
FILE* openfile(char *cwd, char *filename){
    FILE *fptr;
    
    cwd = concat(cwd, filename);
    
    fptr = fopen(cwd,"r");
    //printf("%s\n", cwd);
    if(fptr == NULL){
        //perror("Error! Opening file\n");
        perror("To Be Continued\n");
        return NULL;
    }
    return fptr;
}

//Close the file
void closefile(FILE *fptr){
    fclose(fptr);
}
