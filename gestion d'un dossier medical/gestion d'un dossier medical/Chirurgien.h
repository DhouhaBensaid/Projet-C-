#pragma once
#include "Personne.h"
#include"Patient.h"
#include"Complication.h"
#include<string>
using namespace std;
class Chirurgien :
    public Personne
{
    string specialite;
public :
    Chirurgien(int, string, string, int, string);
    void consulterDossier();
    void consulterHistorique();
    void AjouterNote();
    void ajouterComplication(Complication);
    void modifierInfoPatient(Patient);
    friend ostream& operator<<(ostream&, Chirurgien&);
    friend istream operator>>(istream&, Chirurgien&);
    friend istream& operator==(istream&, Chirurgien&);
    ~Chirurgien();

};

