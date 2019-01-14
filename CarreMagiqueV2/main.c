//PROGRAMME carreMagique
//BUT Programme qui construit et affiche un carr� magique de TAILLE 7
//Principe :
//	Tableau � deux dimensions de taille impaire (5*5 ou 7*7), on l'utilise pour caract�ris� l'emplacement de noeuds num�riques.
//	 - Le premier entier 1, se trouve au nord du milieu de la table, elle devient la positon courante.
//	 - On place les chiffres de fa�on croissante en allant au Nord-Est de la position courante, une seule fois.
//	 - Si la place est d�j� prise, on se d�place au NORD-OUEST jusqu'� trouver cette place libre.
//	 - Le tableau est consid�r� comme sph�rique. C'est � dire que si l'on arrive � la derni�re colonne,
//		on revient � la premi�re colonne, de m�me pour les lignes.
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
//SORTIE Les valeurs du carr� magique

#include "fonction.c"
#define VALEUR_DEPART 1

//###########################################
//PROGRAMME PRINCIPAL
//*****************************************************************************************************//
//
// DESCRIPTION Appel les fonctions d'initialisation de la grille, d'avancement et de v�rification, puis d'affichage.
//      Utilisae une boucle do while pour g�rer l'appel des fonctions et l'incr�mentation de l'index des valeurs de la grille.
//
// ENTREE /-
//
// SORTIE /-
//
// NOTE Le bool�een bCaseVide sert � savoir si la case est vide et d�termine aussi le sens du d�placement lors du prochain passage dans la boucle.
//  Si la caseestVide, on avance � Droite, sinon on avance � Gauche.
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

