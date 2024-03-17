#pragma once
#ifndef DOSSIERMEDICAL_H
#define DOSSIERMEDICAL_H
#include "date.h"
#include<string>
#include<ostream>
#include<istream>
using namespace std;

class dossierMedical
{
protected:
    string nomPatient;
    string prenonPatient;
    date dateNaiss;
    char sexe;
    string specialistConsulte;
public:
        dossierMedical(string, string, date, char, string);
        virtual void saisir() = 0;
        virtual void afficher(string = "") = 0;
        virtual void modifierPatient(Patient p) = 0;
        virtual void supprimerHistorique() = 0;
        friend ostream& operator<< (ostream&, dossierMedical&);
        friend istream& operator>>(istream&, dossierMedical);
        friend istream& operator==(istream&, dossierMedical);
        virtual ~dossierMedical();

};

#endif // DOSSIERMEDICAL_H


