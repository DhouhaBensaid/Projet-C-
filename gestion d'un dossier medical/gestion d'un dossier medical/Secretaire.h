#pragma once
#include "Personne.h"

class Secretaire :public Personne
{
protected:
    float salaire;
public :
    Secretaire(int, string, string, int, float);
    void creerDossierMedicale();
    void creerDossierChirurgical();
    void planifierRdv();
    friend ostream& operator<<(ostream&, Secretaire&);
    friend istream& operator>>(istream&, Secretaire&);
    bool  operator==( Secretaire&);
    void saisir();
	void afficher();
    ~Secretaire();
};

