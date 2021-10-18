#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/* This function scans a line of text (until \n), converts it as an integer and returns this integer */
int scanLineAsInt() {
	int buf;
	scanf("%i\n",&buf);
	return buf;
}

struct Matrix{
	int nombreDeLignes;
	int nombreDeCollones;
	int tab[5][5];
};

typedef struct Matrix matrice;

void readMatrix(matrice *matrice){
    matrice->nombreDeLignes = scanLineAsInt();
    matrice->nombreDeCollones = scanLineAsInt();
    for (int j=0;j<matrice->nombreDeLignes;j++){
        for (int k=0;k<matrice->nombreDeCollones;k++){
        matrice->tab[j][k]=scanLineAsInt();
        }
    }
}

void readMatrixArray(matrice *tabMatrice[],int n){
    for(int i=1;i<=n;i++){
        readMatrix(tabMatrice[0]+i-1);
    }
}

void printMatrix(matrice *matrice){
    printf("%i ",matrice->nombreDeLignes);
    printf("%i\n",matrice->nombreDeCollones);
    for (int j=0;j<matrice->nombreDeLignes;j++){
        for (int k=0;k<matrice->nombreDeCollones;k++){
        printf("%i ",matrice->tab[j][k]);
        }
        printf("\n");
    }
}

void printMatrixArray(matrice *tabMatrice[],int n){
    	printf("%i\n",n);
    for(int i=1;i<=n;i++){
        printMatrix(tabMatrice[0]+i-1);
    }
}

/*void transposeeMatrice(matrice *matrice, matrice *matrice2){
    matrice2->nombreDeLignes = matrice->nombreDeCollones;
    matrice2->nombreDeCollones =matrice->nombreDeLignes;
    for (int j=0;j<matrice->nombreDeColonnes;j++){
        for (int k=0;k<matrice->nombreDeLignes;k++){
        matrice2->tab[k-j+1][j]=matrice1->tab[i][j];
        }
    }
}

int rotate9ccw (matrice* tabMatrice[],int nbMatrices){
     matrice *tabMatrice2[nbMatrices];
	*tabMatrice2 = malloc(sizeof(matrice)*nbMatrices);
    for(int i=1;i<=nbMatrices;i++){
        transposeeMatrice(tabMatrice[0]+i-1,tabMatrice2[0]+i-1);
    }
    return &tabMatrice2;
}*/

int main (void){

    //Détermination du nombre de matrices dans le fichier
    int nbMatrices = scanLineAsInt();

    //Création d'un tableau de matrices
    matrice *tabMatrice[nbMatrices];
	*tabMatrice = malloc(sizeof(matrice)*nbMatrices);

    //Question 1-2-3-4 lecture et affichage du fichier matrice.txt
    readMatrixArray(tabMatrice,nbMatrices);
    printMatrixArray(tabMatrice,nbMatrices);

    /*//Question 5 (problème dans la fonction transposee)
    matrice *tabMatrice2[nbMatrices];
    &tabMatrice2=rotate9ccw(tabMatrice, nbMatrices);
    */
    free (*tabMatrice);
}