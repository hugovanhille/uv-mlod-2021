#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"


struct Music{
    char* name;
    char* artist;
    char* album;
    char* genre;
    int discNumber;
    int trackNumber;
    int year;
};
typedef struct Music Music;


Music* ReadLine( FILE* fichier, char *ligne);

Liste readFile(FILE *fichier);
