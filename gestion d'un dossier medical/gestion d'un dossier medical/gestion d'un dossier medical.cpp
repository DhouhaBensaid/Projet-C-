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
  
   

    Secretaire sec;
    sec.saisir();
    sec.afficher();
    sec.creerDossierChirurgical();
   
    // test du classe chirurgien 


    Chirurgien ch;
  
	cout << " \t**************** Affichage du dossier depuis chirurgien ***********************" << endl;
    // fy blaset case 2 
    ch.consulterDossier(sec);
    ch.AjouterNote(sec);
    //fy blaset case 3 
    ch.consulterDossier(sec);  
 
  

    //____________test class service____________
    service se;
    se.saisir();
    se.afficher(se);
    
    //_________Test classe Salle d'attente ____________
    SalleAttente s;

    // -----list test functions----
    s.ajouterRdv();
    //test du methode statique 
    //--------------------------------------------------------------
    int totalRdv = RendezVous::getTotalRdv();
    cout << "Nombre total de rendez-vous : " << totalRdv << endl;
    //---------------------------------------------------------------
	s.afficherToutRdv(); 
   // s.supprimerDoublonsRdv();
    s.afficherToutRdv();
    int nb = s.nombreRdv();
    cout << "Nombre de rendez-Vous est : " << nb << endl;
    s.insererRdv();
    s.afficherToutRdv();
    s.supprimerToutRdv();
    int nb2 = s.nombreRdv();
    cout << "Nombre de rendez-Vous est : " << nb2 << endl;
    RendezVous rdv(11, 11, 1111, 10); 
    list<RendezVous>::iterator it =s.rechercherRdv(rdv);
    cout << *it;

    /* ---- - MAP test functions----*/
    Patient p1, p2, p3;
    p1.saisir();
	p2.saisir();
    p3.saisir();
    //hne a3mel patient aatyh Nom Hadhraoui bech tnajem tekhdem byh f les fonctions baaed li yekhdhou NOM comme parm ;)
    pair<int, Patient> pair1(p1.getNumCin(), p1);
    pair<int, Patient> pair2(p2.getNumCin(), p2);
    pair<int, Patient> pair3(p3.getNumCin(), p3);
    s.inserer(pair1);
    s.inserer(pair2);
    s.inserer(pair3);
    cout << s << endl;
    map<int, Patient>::iterator itmap;
    //Recherche selon la cle
    itmap = s.rechercher(p2.getNumCin());
    if (itmap != s.fin()) cout << itmap->second << endl;

	//Recherche selon nom du patient
   
    itmap =s.rechercher(p2.getNom());
    if (itmap != s.fin()) cout << itmap->second << endl;

    //modifier une valeur la cle
    s.modifierNumtel(p2.getNumCin(), 25252525);
    cout << s << endl;

    //modifier une valeur selon le nom de patient
    s.modifierNumtel("Hadhraoui", 21212121);
    cout << s<<endl;

    //supprimer un patient selon le nom de patient
    s.supprimer("Hadhraoui");
    cout << s<<endl;

    //supprimer un patient selon la valeurde la cle
    s.supprimer(p2.getNumCin());
    cout << s<<endl;
    
    
    return 0;

   






}

