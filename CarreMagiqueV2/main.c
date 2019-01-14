//PROGRAMME carreMagique
//BUT Programme qui construit et affiche un carré magique de TAILLE 7
//Principe :
//	Tableau à deux dimensions de taille impaire (5*5 ou 7*7), on l'utilise pour caractérisé l'emplacement de noeuds numériques.
//	 - Le premier entier 1, se trouve au nord du milieu de la table, elle devient la positon courante.
//	 - On place les chiffres de façon croissante en allant au Nord-Est de la position courante, une seule fois.
//	 - Si la place est déjà prise, on se déplace au NORD-OUEST jusqu'à trouver cette place libre.
//	 - Le tableau est considéré comme sphérique. C'est à dire que si l'on arrive à la dernière colonne,
//		on revient à la première colonne, de même pour les lignes.
//	 SS-PROGRAMMES
//	 - init
//	 - Avancer
//	 	- AvancerGauche
//	 	- Corriger
//	 	- AvancerDroite
//	 - Recherche vide
//	 - placer
//	 - afficher
//ENTREE
//SORTIE Les valeurs du carré magique

#include "fonction.c"
#define VALEUR_DEPART 1

//###########################################
//PROGRAMME PRINCIPAL
//*****************************************************************************************************//
//
// DESCRIPTION Appel les fonctions d'initialisation de la grille, d'avancement et de vérification, puis d'affichage.
//      Utilisae une boucle do while pour gérer l'appel des fonctions et l'incrémentation de l'index des valeurs de la grille.
//
// ENTREE /-
//
// SORTIE /-
//
// NOTE Le booléeen bCaseVide sert à savoir si la case est vide et détermine aussi le sens du déplacement lors du prochain passage dans la boucle.
//  Si la caseestVide, on avance à Droite, sinon on avance à Gauche.
//
//*****************************************************************************************************//



int main()
{
    tGrille tnmatGrille;
    int nIndex=VALEUR_DEPART;
    tJeton stJeton;
    tBool bCaseVide=true;

    init(tnmatGrille,&stJeton,nIndex);
    placer(tnmatGrille,stJeton,nIndex);
    nIndex+=1;

    do{
        Avancer(&stJeton,bCaseVide);
        bCaseVide=RechercheVide(tnmatGrille,stJeton);
        if(bCaseVide){
            placer(tnmatGrille,stJeton,nIndex);
            nIndex+=1;
        }

    }while(nIndex<(TAILLE*TAILLE+VALEUR_DEPART));

    afficher(tnmatGrille);

    return 0;
}

