
#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// ============
// Definitions of external functions
// ============
//DANS POINT H
//typedef liste musicListe
//struct ici
//Dans une liste mettre adresse d'une 
//cast


int main(){
	Liste l;

	l = NULL;
     FILE* f;
    f = fopen("music.csv","r");
	//printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");
	l=readFile(f);
	afficheListe_i(l);
	//detruire_r(l);
    fclose(f);
    return EXIT_SUCCESS;
}