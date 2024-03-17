#include "dossierMedical.h"
#include<iostream>
#include "date.h"
#pragma once

using namespace std;

dossierMedical::dossierMedical(string nom, string prenom, date date, char s, string m)
{
    nomPatient = nom;
    prenonPatient = prenom;
    dateNaiss = date;
    sexe = s;
    specialistConsulte = m;
}
void ostream& operator<< (ostream& out, dossierMedical& dm)
{
    out << "\n le nom du patient " << dm.nomPatient;
    out << "\n le prenom du patient" << dm.prenonPatient.
        out << "\n la date de naissance" << dm.dateNaiss;
    out << "\n le sexe" << dm.sexe;
    out << "\n le specialiste consulte" << dm.specialistConsulte;
}
void istream& operator >>(istream& in, dossierMedical& dm)
{
    cout << "saisir le nom du patient" << endl;
    in >> dm.nomPatient;
    cout << "saisir le prenom du patient" << endl;
    in >> dm.prenonPatient;
    cout << "saisir la date de naissance du patient" << endl;
    in >> dm.dateNaiss;
    cout << "saisir le sexe du patient" << endl;
    in >> dm.sexe;
    cout << "saisir le specialiste consulte par le patient" << endl;
    in >> dm.specialistConsulte;
    return in;

}
istream& operator =(istream& in, dossierMedical dm)
dossierMedical::~dossierMedical()
{
    //dtor
}
