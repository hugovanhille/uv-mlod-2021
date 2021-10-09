#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

 void echangeContenu(int *a,int *b){
    int c=*a;
    *a=*b;
    *b=c;
 }

 bool estConvexe(bool tab[],int length){
    bool valeurPrec=tab[0];
    int res=1; 
    int i=1;
    while (i != length && res!=2){
        if (tab[i]!=valeurPrec && res!=0)
            res=0;
        else if (tab[i]!=valeurPrec && res==0 )
            res=2; 
        else if (tab[i]!=valeurPrec && res==2 )
            res=3; 
        valeurPrec=tab[i];
        i++;
    }
    if (res==2 && tab[length-1]==tab[0])
        res=1;

    if (res==1)
        return true;
    else
        return false;
 }

void mult_matrice(int64_t matriceResultat[5][5],int64_t matrice1[5][5],int64_t matrice2[5][5]){
    int somme=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++)
                somme+=matrice1[i][k]*matrice2[k][j];
            matriceResultat[i][j]=somme;
            somme=0;
        }
        
    }
}

void affiche_matrice(int64_t matrice[5][5]){
        for(int i=0;i<5;i++){
            printf("|");
            for(int j=0;j<5;j++)
                printf("%ld ",matrice[i][j]);
            printf("|\n");
        }
}
    enum Mois{
        janvier,
        fevrier,
        mars,
        avril,
        mai,
        juin,
        juillet,
        aout,
        septembre,
        octobre,
        novembre,
        decembre
    };

    struct date {
        int jour;
        enum Mois mois;
        int annee;
    };

void initialiseDate (struct date *d ){
    int a ,c;
    char b;
    printf("entrer une année:\n");
    scanf("%d",&a);
    printf("entrer un mois:\n");
    scanf("%s",&b);
    printf("entrer un jour a:\n");
    scanf("%d",&c);
    (*d).annee=a;
    (*d).mois=b;
    (*d).jour=c;

}
void afficheDate(struct date *d){
    printf("Le %d %s",(*d).jour,(*d).mois);
    printf(" %d\n",(*d).annee);

}

struct date creerDateParCopie(){
    struct date d;
    initialiseDate(&d);
    return d;
}


int main(void) {

    //-----------exercice 1-----------
    /*int a;
    int b;
    printf("entrer un entier a:\n");
    scanf("%d",&a);
    printf("entrer un entier b:\n");
    scanf("%d",&b);
    printf("a=%d,b=%d\n",a,b);
    echangeContenu(&a,&b);
    printf("Après changement : a=%d,b=%d",a,b);*/

    //-----------exercice 2-----------

    /*bool T1[5]={false,true,true,false,false};
    bool T2[5]={true,true,false,false,true};
    bool T3[5]={true,true,false,true,false};
    bool res;
    res=estConvexe(T3,5);
    printf("%d",res);*/

    //-----------exercice 3-----------
    /*int64_t matrice1[5][5]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    int64_t matrice2[5][5]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
    int64_t matriceResultat[5][5];
    mult_matrice(matriceResultat,matrice1,matrice2);
    affiche_matrice(matriceResultat);
    // La fonction n'est pas intéressante car elle ne peut être réutilisé uniquement pour des matrices de taille [5][5]*/

    //-----------exercice 4-----------


    struct date d;
    //initialiseDate(&d);
    d=creerDateParCopie(); 
    afficheDate(&d);


    return 0;
}