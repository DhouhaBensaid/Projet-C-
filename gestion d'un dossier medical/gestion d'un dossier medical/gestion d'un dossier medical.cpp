#include <iostream>
#include"Patient.h"
#include "postChirurgicale.h"
#include"dossierMedical.h"
#include"dossierChirurgical.h"
#include"date.h"
#include "Secretaire.h"
#include "Chirurgien.h"
#include"SalleAttente.h"
#include"service.h"
#include<fstream>
#pragma once
int main()
{
  
    //test du classe postChirurfical


   /* postChirurgicale post;
    post.saisir();
    post.afficher();*/


    // test du classe secreataire

    /*Secretaire sec;
    sec.saisir();
    sec.afficher();
    sec.creerDossierChirurgical();
    sec.consulterToutLesDossier();
    sec.planifierRdv();
    sec.afficherTousLesRendezVous();
    sec.supprimerRdv(1);
    sec.afficherTousLesRendezVous();*/



    // test du classe chirurgien 


    //Chirurgien ch;
    //fstream f;
   /* ch.saisir();
    ch.afficher();
	cout << " \t**************** Affichage du dossier depuis chirurgien ***********************" << endl;
    ch.consulterDossier(sec);
    ch.AjouterNote(sec);
    ch.consulterDossier(sec);  */
    //ch.creer(f);
    //ch.saisirPatients(f);
    //ch.modifierInfoPatient();
   // ch.ajouterComplication();

    //ch.afficherTousLesPatients();
    //ch.supprimerPatient(f);
    //ch.supprimerComplicationDuPatient();

/*
    ch.afficherTousLesPatients();
    ch.supprimerPatient(f);
    ch.afficherAPartirDuFicher(f);
    ch.supprimerComplicationDuPatient();*/
    

    //test du template

   /*dossierChirurgical<string> d("marwa", "hadhraoui", 16, 4, 2024, 'F', "dentaire", "typeIntervention", 21, 6, 2001, "2");
    cout << d;
    dossierChirurgical<int> d1;
    cin >> d1;*/
    //test class service
    /*service s;
    s.saisir();
    s.afficher(s);*/
  





    return 0;

   






}

