#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
	Liste l=malloc(sizeof(Cellule));
	l->val=v;
	//l->suiv=NULL;
	return l;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	Liste new=malloc(sizeof(Cellule));
	new->val=v;
	new->suiv=l;
	return new;
}



// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	while(!estVide(l)){
		afficheElement(l->val);
		l=l->suiv;
	}
	printf("\n");
}
// version recursive
void afficheListe_r(Liste l) {
	if(!estVide(l)){
		afficheElement(l->val);
		afficheListe_r(l->suiv);
	}
	else 
		printf("\n");
}


// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Liste lSuivant=l;
	while(!estVide(lSuivant)){
		l=lSuivant;
		lSuivant=l->suiv;
		detruireElement(l->val);
		free(l);
	}
}

// version récursive
void detruire_r(Liste l) {
	if(!estVide(l)){
		detruire_r(l->suiv);
		detruireElement(l->val);
		free(l);
	}
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	Liste new=l;
	if(estVide(l))
		return creer(v);
	while(!estVide(new->suiv))
		new=new->suiv;
	new->suiv=creer(v);
	return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if(estVide(l->suiv)){
		Liste new=creer(v);	
		l->suiv=new;
	}
	else
		ajoutFin_r(v, l->suiv);
	return l;
}


// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	while(!estVide(l) && !equalsElement(l->val,v))
		l=l->suiv;
	
	if (estVide(l)){
		return NULL;
		printf("null");
	}
	else{
		Liste new=malloc(sizeof(Cellule));
		new->val=l->val;
		return new;
	}
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if(estVide(l))
		return NULL;
	if(l->val==v)
		return l;
	return cherche_r(v,l->suiv);

}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	Liste maillon1=l;
	Liste maillonPrec=NULL;
	bool trouve=false;
	while(!estVide(l) && !trouve){
		if(equalsElement(v,l->val)){
			if(maillonPrec==NULL)
				maillon1=l->suiv;
			else
				maillonPrec->suiv=l->suiv;
			detruireElement(l->val);
			free(l);
			trouve=true;
		}
		maillonPrec=l;
		l=l->suiv;
	}
	return maillon1;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	if(!estVide(l)){
		if(equalsElement(v,l->val)){
			Liste p=l->suiv;
			l->suiv=NULL;
			detruire_r(l);
			return p;
		}
		l->suiv=retirePremier_r(v,l->suiv);
		return l;
	}

	return l;
}


void afficheEnvers_r(Liste l) {
	if(!estVide(l)){
		afficheEnvers_r(l->suiv);
		afficheElement(l->val);
	}

}