#pragma once
#include "Personne.h"
#include<string>
using namespace std;
#include<istream>
#include<ostream>
class Secretaire :
    public Personne
{
    float salaire;
public :
    Secretaire(int, string, string, int, float);
    void creerDossierMedicale();
    void ajouterConsultationAHistorique();
    void creerDossierChirurgical();
    void planifierRdv();
    friend ostream operator<<(ostream&, Secretaire&);
    friend istream operator>>(istream&, Secretaire&);
    friend istream operator==(istream&, Secretaire&);
    ~Secretaire();
};

