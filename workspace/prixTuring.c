/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring < turingWinners.txt > out.txt

 Tests
 diff out.txt turingWinners.txt

 Détection de fuites mémoires
 valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prixTuring < turingWinners.txt > out.txt
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* This function scans a line of text (until \n) and returns a char* that contains all characters on the line (up to 255) excluding \n.
It also ensures the \0 termination.
**WARNING**: The result of this function has been allocated (calloc) by the function */
char* scanLine(){
	int maxLineSize = 255;
	char c, *line = calloc(maxLineSize+1,sizeof(char));

	scanf("%250[^\n]", line);

	if ( (c = getchar()) != '\n') {
		/* we did not get all the line */
		line[250] = '[';
		line[251] = line[252] = line[253] = '.';
		line[254] = ']';
		// line[255] = '\0'; // useless because already initialized by calloc

		// let's skip all chars untli the end of line
		while (( (c = getchar()) != '\n') && c != EOF) ;
	}

	return line;
}

/* This function scans a line of text (until \n), converts it as an integer and returns this integer */
int scanLineAsInt() {
	int buf;
	scanf("%i\n",&buf);
	return buf;
}

struct Winner{
	int annee;
	char* nom;
	char* description;
};

typedef struct Winner winner;

void printOneWinner(winner *winner){
		printf("Winner Year : %i\n",winner->annee);
		printf("%s\n",winner->nom);
		printf("%s\n",winner->description);
}

void printWinners(winner *winners[]){
		for (int i=1;i<=50;i++)
			printOneWinner(winners[0]+i-1);
		free (winners);
}


void infosAnnee (winner *winners[],int annee){
	for(int i=1;i<=50;i++){
		if ((winners[0]+i-1)->annee ==annee)
			printOneWinner(winners[0]+i-1);
	}
	free (winners);
}

void readWinners(){
	winner *winners[50];
	*winners = malloc(sizeof(winner)*50);
	for(int i=1;i<=50;i++){
		(winners[0]+i-1)->annee = scanLineAsInt();
		(winners[0]+i-1)->nom = scanLine();
		(winners[0]+i-1)->description = scanLine();
	}
printWinners(winners);
}

int main(int argc, char *argv[]){
	int nbGagnants = scanLineAsInt();
	printf("nbGagnants = %i\n",nbGagnants);
	readWinners();
	//int annee=(int)argv[1];
	return EXIT_SUCCESS;
}
