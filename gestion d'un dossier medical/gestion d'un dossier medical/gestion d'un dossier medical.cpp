

#include <iostream>
#include"Patient.h"
#include "postChirurgicale.h"
#include"dossierMedical.h"
#include"dossierChirurgical.h"
#include"date.h"
#include "Secretaire.h"
#include "Chirurgien.h"
int main()
{
  
    //test du classe postChirurfical


   /* postChirurgicale post;
    post.saisir();
    post.afficher();*/


    // test du classe secreataire

    Secretaire sec;
    sec.saisir();
    sec.afficher();
    sec.creerDossierChirurgical();
    sec.consulterToutLesDossier();
    sec.planifierRdv();
    sec.afficherTousLesRendezVous();
    sec.supprimerRdv(1);
    sec.afficherTousLesRendezVous();



    // test du classe chirurgien 


    Chirurgien ch;
    ch.saisir();
    ch.afficher();
	cout << " \t**************** Affichage du dossier depuis chirurgien ***********************" << endl;
    ch.consulterDossier(sec);
    ch.AjouterNote(sec);
    ch.consulterDossier(sec);  
    ch.saisirPatients();
    ch.modifierInfoPatient();
    ch.ajouterComplication();
    ch.afficherTousLesPatients();
    ch.supprimerComplicationDuPatient();




    return 0;

   






}

