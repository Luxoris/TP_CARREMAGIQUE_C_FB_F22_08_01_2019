#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include "tJeton.h"
#include "tBool.h"
#include "tGrille.h"
#include "define.h"
//PROTOTYPES
extern void init(tGrille tnmatGrille, tJeton *pstJeton, const int nIndex);
extern tBool RechercheVide(const tGrille tnmatGrille,const tJeton stJeton);
extern void AvancerGauche(tJeton *pstJeton);
extern void Corriger(tJeton *pstJeton);
extern void AvancerDroite(tJeton *pstJeton);
extern void Avancer(tJeton *pstJeton,const tBool bAvancerDroite);
extern void placer(tGrille tnmatGrille, const tJeton stJeton, const int nIndex);
extern void afficher(const tGrille tnmatGrille);



#endif // MAIN_H_INCLUDED
