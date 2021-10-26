#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include<string.h>

void afficheElement(Element e) {
	Music *m = (Music*) e;
	printf("%s ",m->name);
	printf("%s ",m->artist);
	printf("%s ",m->album);
	printf("%s ",m->genre);
	printf("%i ",m->discNumber);
	printf("%i ",m->trackNumber);
	printf("%i ",m->year);
	printf("\n");
}

void detruireElement(Element e) {
	Music *m = (Music*) e;
    free(m->name);
    free(m->artist);
    free(m->album);
    free(m->genre);
    free(e);
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	Music *m1 = (Music*) e1;
    Music *m2 = (Music*) e2;
	bool res=(strcmp(m1->name,m2->name)==0);
	if(res!=0)
		res=(strcmp(m1->artist,m2->artist)==0);
	if(res!=0)
		res=(strcmp(m1->album,m2->album)==0);
	if(res!=0)
		res=(strcmp(m1->genre,m2->genre)==0);
	if(res!=0)
		res=(m1->discNumber==m2->discNumber);
	if(res!=0)
		res=(m1->trackNumber==m2->trackNumber);
	if(res!=0)
		res=(m1->year==m2->year);
	return res;
}

Music* ReadLine(FILE* fichier, char* ligne){
    
    Music* m =malloc(sizeof(Music));

    char *line=strdup(ligne);
    
    m->name=strsep(&line,",");
	m->artist=strsep(&line,",");
    m->album=strsep(&line,",");
    m->genre=strsep(&line,",");
    m->discNumber = atoi( strsep(&line,","));
    m->trackNumber = atoi( strsep(&line,","));
    m->year = atoi( strsep(&line,","));

	return m;
}

  
Liste readFile(FILE *fichier){
	Liste l = NULL;
	char *ligne=malloc(sizeof(char)*255);
    fgets(ligne,255,fichier);
    int i=0;
    
	while(fgets(ligne,255,fichier)!=NULL){
        l=ajoutFin_i(ReadLine(fichier,ligne),l);
		fgets(ligne,255,fichier);
        i++;
	}
    return l;
}