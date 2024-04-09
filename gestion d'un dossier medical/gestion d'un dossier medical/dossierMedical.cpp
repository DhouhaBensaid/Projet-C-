#include "dossierMedical.h"
#include "Patient.h"
#include<iostream>
#include "date.h"
#pragma once

using namespace std;

dossierMedical::dossierMedical(string nom, string prenom, int jour, int mois, int annee, char s, string m)
    : nomPatient(nom), prenomPatient(prenom), dateNaiss(jour, mois, annee), sexe(s), specialistConsulte(m) {
}

 ostream& operator<< (ostream& out, dossierMedical& dm)
{
    out << "\n le nom du patient " << dm.nomPatient;
    out << "\n le prenom du patient" << dm.prenomPatient;
    out << "\n le jour de naissance" << dm.dateNaiss.getJour();
    out << "\n le mois de naissance" << dm.dateNaiss.getMois();
    out << "\n l'annee de naissance" << dm.dateNaiss.getAnnee();
    out << "\n le sexe" << dm.sexe;
    out << "\n le specialiste consulte" << dm.specialistConsulte;
    return out;
}
 istream& operator >>(istream& in, dossierMedical& dm)
{
 
    cout << "saisir le nom du patient" << endl;
    in >> dm.nomPatient;
    cout << "saisir le prenom du patient" << endl;
    in >> dm.prenomPatient;
    cout << "saisir la date de naissance du patient" << endl;
    in >> dm.dateNaiss;
    cout << "saisir le sexe du patient" << endl;
    in >> dm.sexe;
    cout << "saisir le specialiste consulte par le patient" << endl;
    in >> dm.specialistConsulte;
    return in;

}
 bool dossierMedical::operator ==(dossierMedical& dm) {
     return ((nomPatient == dm.nomPatient) && (prenomPatient == dm.prenomPatient));
}
 void dossierMedical::saisir()
 {
     cout << "\t**** Saisie des informations du dossier Medical ****" << endl<<endl;
     cout << "Donner le nom du patient : " << endl;
     cin >>nomPatient;
     cout << "Donner le prenom du patient : " << endl;
     cin >>prenomPatient;
     cout << "Donner la date de naissance du patient  : " << endl;
     cin >>dateNaiss;
     cout << "Donner le sexe du patient  : " << endl;
     cin >> sexe;
     cout << "Donner le nom du specialiste consulte par le patient  : " << endl;
     cin >> specialistConsulte;

 }
 void dossierMedical::afficher()
 {
     cout << "\t**** Affichage informations du dossier Medical ****" << endl<<endl;
     cout << "Le nom du patient est : " << nomPatient << endl;
     cout << "Le prenom du patient est : " << prenomPatient << endl;
     cout << "La date de naissance du patient est : " << dateNaiss<< endl;
     cout << "Le sexe du patient est : " <<sexe<< endl;
     cout << "Le specialiste consulte par le  patient est : " <<specialistConsulte << endl;
 }
 void dossierMedical::modifierPatient(Patient p) {
     cout << "\t**** Modification des informations medicales du patient ****" << endl<<endl;
     cout << "Nouveau nom : ";
     cin >> nomPatient;
     cout << "Nouveau prénom : ";
     cin >> prenomPatient;
     cout << "Nouveau sexe (M/F) : ";
     cin >> sexe;
     cout << "Nouveau spécialiste consulté : ";
     cin >> specialistConsulte;
     cout << "Nouvelle date de naissance:" << endl;
     cin >> dateNaiss;
     p.saisir();
 }

dossierMedical::~dossierMedical()
{
    //dtor
}
