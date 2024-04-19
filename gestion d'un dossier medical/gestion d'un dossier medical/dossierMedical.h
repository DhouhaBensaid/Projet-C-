#pragma once
#ifndef DOSSIERMEDICAL_H
#define DOSSIERMEDICAL_H
#include "date.h"
#include<string>
#include"Patient.h"
using namespace std;

class dossierMedical
{
protected:
    string nomPatient;
    string prenomPatient;
    date dateNaiss;
    char sexe;
    string specialistConsulte;
public:
        dossierMedical(string="", string="", int=0, int=0, int=0, char='F', string="");
        virtual void saisir() = 0;
        virtual void afficher() = 0;
        virtual void modifierPatient(Patient p);
        friend ostream& operator<<(ostream&, dossierMedical&);
        friend istream& operator>>(istream&, dossierMedical&);
        string getNomPatient() const { return this->nomPatient; }


        bool operator==(dossierMedical&);
        virtual ~dossierMedical();

};

#endif // DOSSIERMEDICAL_H


