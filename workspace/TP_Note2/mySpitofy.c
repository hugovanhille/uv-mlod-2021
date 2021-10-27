#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(){
	Liste l;
	l = NULL;
    FILE* f;

    f = fopen("music.csv","r");
	l=readFile(f);
	//afficheListe_i(l);

	triABulles(l);
	printf("\n----------Fichier trié----------\n");
	afficheListe_i(l);
	
	detruire_i(l);
    fclose(f);
    return EXIT_SUCCESS;
}
