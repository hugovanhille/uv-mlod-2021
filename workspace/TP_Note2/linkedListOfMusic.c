#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include<string.h>

void afficheElement(Element e) {
	Music *m = (Music*) e;
	printf("%s,",m->name);
	printf("%s,",m->artist);
	printf("%s,",m->album);
	printf("%s,",m->genre);
	if(m->discNumber==0)
		printf(",");
	else
		printf("%i,",m->discNumber);
	printf("%i,",m->trackNumber);
	printf("%i",m->year);
	printf("\n");
}

void detruireElement(Element e) {
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

Music* ReadLine( char* ligne){
    
    Music* m =malloc(sizeof(Music));

    char *line, *tofree;
    tofree=line=strdup(ligne);
    m->name=strsep(&line,",");
	m->artist=strsep(&line,",");
    m->album=strsep(&line,",");
    m->genre=strsep(&line,",");
    m->discNumber = atoi( strsep(&line,","));
    m->trackNumber = atoi( strsep(&line,","));
    m->year = atoi( strsep(&line,","));
    free(tofree);
	return m;
}

  
Liste readFile(FILE *fichier){
	Liste l = NULL;
	char *ligne=malloc(sizeof(char)*255);
    fgets(ligne,255,fichier);
	char *firstLine=strdup(ligne);
	printf("%s",firstLine);
    while(fgets(ligne,255,fichier)!=NULL){
        l=ajoutFin_i(ReadLine(ligne),l);
        free(ligne);
	}
    free(firstLine);

    return l;
}

Liste triABulles(Liste l){
	if(estVide(l)){
        return NULL;
    }
    Liste prec  = l;
    Liste next = NULL;
    while(!estVide(prec)){
        next = prec->suiv;
        while(!estVide(next)){
            if( ((Music*)(next->val))->year < ((Music*)(prec->val))->year ){
                void *p;
                p = next->val;
                next->val = prec->val;
                prec->val = p;
            }
            next = next->suiv;
        }
        prec = prec->suiv;
    }
    return l;

}


