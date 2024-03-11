#ifndef DOSSIERMEDICAL_H
#define DOSSIERMEDICAL_H
#include "Date.h"
#include<string>
class dossierMedical
{
protected:
    string nomPatient;
    string prenonPatient;
    Date dateNaiss;
    char sexe;
    string specialistConsulte;
public:
        dossierMedical(string,string,Date,char,string);
        virtual void saisir()=0
        virtual void afficher(string="")=0
        virtual void modifierPatient(Patient p)=0
        virtual void supprimerHistorique()=0
        friend ostrem& operator<< (ostream&,dossierMedical&)
        friend istream& operator >>(istream&,dossierMedical)
        friend istream& operator =(istream&,dossierMedical)
        virtual ~dossierMedical();

};

#endif // DOSSIERMEDICAL_H
