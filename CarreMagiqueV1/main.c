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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 7    //doit être un entier impair positif et inférieur à
#define VALEUR_PAR_DEFAUT 0 //entier qui doit être inférieur à VALEUR_DEPART ou supérieur à (VALEUR_DEPART + TAILLE*TAILLE)
#define VALEUR_DEPART 1


//DEFINITION TYPES STRUCTURES
typedef struct tJeton{
    int nX;
    int nY;
}tJeton;

//DEFINITION DU TYPE GRILLE
typedef int tGrille[TAILLE][TAILLE];

//DEFINTION DU TYPE BOOLEEN
typedef enum tBool{false,true}tBool;

//PROTOTYPES
void init(tGrille tnmatGrille, tJeton *pstJeton, const int nIndex);
tBool RechercheVide(const tGrille tnmatGrille,const tJeton stJeton);
void AvancerGauche(tJeton *pstJeton);
void Corriger(tJeton *pstJeton);
void AvancerDroite(tJeton *pstJeton);
void Avancer(tJeton *pstJeton,const tBool bAvancerDroite);
void placer(tGrille tnmatGrille, const tJeton stJeton, const int nIndex);
void afficher(const tGrille tnmatGrille);


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

//###########################################
//PROCEDURE init
//*****************************************************************************************************//
//
// DESCRIPTION Initialise la grille à la VALEUR_PAR_DEFAUT et le JETON à sa position de départ.
//
// ENTREE la grille de type tgrille, le jeton de type jeton et l'index de type int
//
// SORTIE la grille et le jeton modifié
//
// NOTE
//
//*****************************************************************************************************//

void init(tGrille tnmatGrille, tJeton *pstJeton, const int nIndex){
    short snI,snJ;
    //intialisation de la grille à la valeur par defaut
    for(snI=0;snI<TAILLE;snI++){
       for(snJ=0;snJ<TAILLE;snJ++){
            tnmatGrille[snI][snJ]= VALEUR_PAR_DEFAUT;
        }
    }
    //initialisation du pion à la position de départ
	pstJeton->nX=TAILLE / 2 -1; //permet de fonctionner si l'on modifie la TAILLE du carré
	pstJeton->nY=TAILLE / 2;

}

//###########################################
//PROCEDURE RechercheVide
//*****************************************************************************************************//
//
// DESCRIPTION Vérifie si aux coordonnées du jeton, dans la grille, la valeur est égale à la VALEUR_PAR_DEFAUT
//
// ENTREE la grille de type tgrille, le jeton de type jeton
//
// SORTIE le booléen correspondant au résultat du test
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
// DESCRIPTION Modifie les coordonnée du jeton afin de traduire un déplacement vers le haut et la gauche sur la grille (nX-1 et nY-1)
//
// ENTREE la référence du jeton de type jeton
//
// SORTIE le jeton modifié en mémoire
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
// DESCRIPTION Vérifie si les coordonnés du jeton sont en dehors de la grille,
//  si c'est le càs modifie les coordonnés afin de le faire retourner dans la grille.
//  Permet de rendre la grille "sphérique"
// ENTREE la référence du jeton de type jeton
//
// SORTIE le jeton modifié (ou nom) en mémoire
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
// DESCRIPTION Modifie les coordonnée du jeton afin de traduire un déplacement vers le haut et la droite sur la grille (nX-1 et nY+1)
//
// ENTREE la référence du jeton de type jeton
//
// SORTIE le jeton modifié en mémoire
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
// DESCRIPTION Appel les procedures "Corriger", "AvancerGauche", et "AvancerDroite" en fonction du sens demandée par le booléen.
//
// ENTREE la référence du jeton de type jeton et la valeur du booléen.
//
// SORTIE le jeton modifié en mémoire
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
// DESCRIPTION Affecte à la cellule de la grille correspondant à l'emplacement du jeton la valeur de l'index.
//
// ENTREE le jeton, la grille, la valeur de l'index
//
// SORTIE la cellule de la grille modifié en mémoire
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
// SORTIE la grille affichée
//
// NOTE
//
//*****************************************************************************************************//
void afficher(const tGrille tnmatGrille){
    short snI=0,snJ=0;
    for(snI=0;snI<TAILLE;snI++){
        putchar(' ');
        for(snJ=0;snJ<TAILLE;snJ++){
            if (tnmatGrille[snI][snJ]<10){ //dans le càs ou le nombre est inférieur à 10 ajoute un espace
                putchar(' ');
            }
            printf("%d ",tnmatGrille[snI][snJ]);
        }
        putchar('\n');
    }
}

