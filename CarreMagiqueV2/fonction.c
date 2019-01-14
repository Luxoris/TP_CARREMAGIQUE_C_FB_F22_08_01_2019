#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//###########################################
//PROCEDURE init
//*****************************************************************************************************//
//
// DESCRIPTION Initialise la grille � la VALEUR_PAR_DEFAUT et le JETON � sa position de d�part.
//
// ENTREE la grille de type tgrille, le jeton de type jeton et l'index de type int
//
// SORTIE la grille et le jeton modifi�
//
// NOTE
//
//*****************************************************************************************************//

void init(tGrille tnmatGrille, tJeton *pstJeton, const int nIndex){
    short snI,snJ;
    //intialisation de la grille � la valeur par defaut
    for(snI=0;snI<TAILLE;snI++){
       for(snJ=0;snJ<TAILLE;snJ++){
            tnmatGrille[snI][snJ]= VALEUR_PAR_DEFAUT;
        }
    }
    //initialisation du pion � la position de d�part
	pstJeton->nX=TAILLE / 2 -1; //permet de fonctionner si l'on modifie la TAILLE du carr�
	pstJeton->nY=TAILLE / 2;

}

//###########################################
//PROCEDURE RechercheVide
//*****************************************************************************************************//
//
// DESCRIPTION V�rifie si aux coordonn�es du jeton, dans la grille, la valeur est �gale � la VALEUR_PAR_DEFAUT
//
// ENTREE la grille de type tgrille, le jeton de type jeton
//
// SORTIE le bool�en correspondant au r�sultat du test
//
// NOTE
//
//*****************************************************************************************************//

tBool RechercheVide(const tGrille tnmatGrille,const tJeton stJeton){
    if(tnmatGrille[stJeton.nX][stJeton.nY]==VALEUR_PAR_DEFAUT){
        return true;
    }else{
        return false;
    }
}

//###########################################
//PROCEDURE AvancerGauche
//*****************************************************************************************************//
//
// DESCRIPTION Modifie les coordonn�e du jeton afin de traduire un d�placement vers le haut et la gauche sur la grille (nX-1 et nY-1)
//
// ENTREE la r�f�rence du jeton de type jeton
//
// SORTIE le jeton modifi� en m�moire
//
// NOTE
//
//*****************************************************************************************************//
void AvancerGauche(tJeton *pstJeton){
    pstJeton->nX -=1;
    pstJeton->nY -=1;
}

//###########################################
//PROCEDURE AvancerDroite
//*****************************************************************************************************//
//
// DESCRIPTION V�rifie si les coordonn�s du jeton sont en dehors de la grille,
//  si c'est le c�s modifie les coordonn�s afin de le faire retourner dans la grille.
//  Permet de rendre la grille "sph�rique"
// ENTREE la r�f�rence du jeton de type jeton
//
// SORTIE le jeton modifi� (ou nom) en m�moire
//
// NOTE
//
//*****************************************************************************************************//
void Corriger(tJeton *pstJeton){
    if (pstJeton->nX<0){
        pstJeton->nX=(TAILLE-1);
    }else if(pstJeton->nX>(TAILLE-1)){
        pstJeton->nX=0;
    }
    if (pstJeton->nY<0){
        pstJeton->nY=(TAILLE-1);
    }else if(pstJeton->nY>(TAILLE-1)){
        pstJeton->nY=0;
    }
}

//###########################################
//PROCEDURE AvancerDroite
//*****************************************************************************************************//
//
// DESCRIPTION Modifie les coordonn�e du jeton afin de traduire un d�placement vers le haut et la droite sur la grille (nX-1 et nY+1)
//
// ENTREE la r�f�rence du jeton de type jeton
//
// SORTIE le jeton modifi� en m�moire
//
// NOTE
//
//*****************************************************************************************************//
void AvancerDroite(tJeton *pstJeton){
    pstJeton->nX -=1;
    pstJeton->nY +=1;
}

//###########################################
//PROCEDURE Avancer
//*****************************************************************************************************//
//
// DESCRIPTION Appel les procedures "Corriger", "AvancerGauche", et "AvancerDroite" en fonction du sens demand�e par le bool�en.
//
// ENTREE la r�f�rence du jeton de type jeton et la valeur du bool�en.
//
// SORTIE le jeton modifi� en m�moire
//
// NOTE
//
//*****************************************************************************************************//

void Avancer(tJeton *pstJeton,const tBool bAvancerDroite){
    if (bAvancerDroite){
        AvancerDroite(pstJeton);
    }else{
        AvancerGauche(pstJeton);
    }
    Corriger(pstJeton);
}

//###########################################
//PROCEDURE placer
//*****************************************************************************************************//
//
// DESCRIPTION Affecte � la cellule de la grille correspondant � l'emplacement du jeton la valeur de l'index.
//
// ENTREE le jeton, la grille, la valeur de l'index
//
// SORTIE la cellule de la grille modifi� en m�moire
//
// NOTE
//
//*****************************************************************************************************//
void placer(tGrille tnmatGrille, const tJeton stJeton, const int nIndex){
    tnmatGrille[stJeton.nX][stJeton.nY]=nIndex;
}


//###########################################
//PROCEDURE afficher
//*****************************************************************************************************//
//
// DESCRIPTION Parcours la grille en entier et affiche ses valeurs.
//
// ENTREE la grille
//
// SORTIE la grille affich�e
//
// NOTE
//
//*****************************************************************************************************//
void afficher(const tGrille tnmatGrille){
    short snI=0,snJ=0;
    for(snI=0;snI<TAILLE;snI++){
        putchar(' ');
        for(snJ=0;snJ<TAILLE;snJ++){
            if (tnmatGrille[snI][snJ]<10){ //dans le c�s ou le nombre est inf�rieur � 10 ajoute un espace
                putchar(' ');
            }
            printf("%d ",tnmatGrille[snI][snJ]);
        }
        putchar('\n');
    }
}
