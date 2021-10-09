#include <stdio.h>
typedef short TypeEntier;

float prix_billet(int age,float prix_plein_tarif){
    float res=0;
    if (age>=0 && age<=2)
        res=0.1*prix_plein_tarif;
    else if (age>2 && age<=12)
        res=0.5*prix_plein_tarif;
    else{
        res=prix_plein_tarif;}
    return res;
}

void affichage_des(int N){
    printf("Pour N=%d, les combinaisons de dés sont : ",N);
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            for(int k=1;k<=6;k++){
                if(i+j+k==N)
                    printf("%d%d%d ",i,j,k);
            }
        }

    }
}

void nombres_parfaits(int N){
    printf("Les nombres parfaits compris entre 0 et N=%d sont : ",N);
    int somme;
    for (int i=1;i<=N;i++){
        somme=0;
        for (int j=1;j<=i/2;j++)
            if(i%j==0) 
                somme+=j;
        if (somme==i)
            printf("%d ",i);
    }
}

TypeEntier factorielle(int N){
    TypeEntier res=1;
    for(int i=1;i<=N;i++)
        res*=i;
    return res;
}


int main(void) {

    //float prix=0;

    //Exercice 1
    //prix=prix_billet(5,10);
    //printf("Le prix du billet est %f € \n",prix);
    
    //Exercice 2
    //affichage_des(6);

    /*int N=0;
    printf("entrer un entier N pour lequel tester les nombres parfait:\n");
    scanf("%d",&N);
    nombres_parfaits(N);*/
    TypeEntier res=0;
    res=factorielle(8);
    printf("8 factorielle =%d",res);
    /*for(int i=1;i<=15;i++){
        res=factorielle(i);
        printf("%d! =%d\n",i,res);
    }*/

    return 0;
}