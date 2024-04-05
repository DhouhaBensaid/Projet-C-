

#include <iostream>
#include"Patient.h"
#include "postChirurgicale.h"
#include"dossierMedical.h"
#include"dossierChirurgical.h"
#include"date.h"
int main()
{
    //test du classe patient
    Patient p;
    p.saisir();
    p.afficher();
    p.supprimerComplication(2);
    p.afficher();
    //test:
    postChirurgicale post;
    post.saisir();
    post.afficher();
    post.ajouterComplication();
    date DA;
    DA.saisirDate();
    dossierChirurgical d;
    d.saisir();
    d.afficher();
    d.modifierDate(DA);
    return 0;

   






}

