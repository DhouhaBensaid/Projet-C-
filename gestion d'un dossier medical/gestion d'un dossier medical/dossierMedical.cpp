#include "dossierMedical.h"
#include<iostream>
#include "date.h"
#pragma once

using namespace std;

dossierMedical::dossierMedical(string nom, string prenom, date date, char s, string m)
{
    nomPatient = nom;
    prenomPatient = prenom;
    dateNaiss = date;
    sexe = s;
    specialistConsulte = m;
}
 ostream& operator<< (ostream& out, dossierMedical& dm)
{
    out << "\n le nom du patient " << dm.nomPatient;
    out << "\n le prenom du patient" << dm.prenomPatient;
   // out << "\n la date de naissance"<< dm.dateNaiss; // tu dois acceder à chaque champ du date avec les getters 
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
   // in >> dm.dateNaiss.; // tu dois acceder au champs de date par les setters !!
    cout << "saisir le sexe du patient" << endl;
    in >> dm.sexe;
    cout << "saisir le specialiste consulte par le patient" << endl;
    in >> dm.specialistConsulte;
    return in;

}
 bool dossierMedical::operator ==(dossierMedical& dm) {
     return ((nomPatient == dm.nomPatient) && (prenomPatient == dm.prenomPatient));
}
dossierMedical::~dossierMedical()
{
    //dtor
}
