#pragma once
#include "Personne.h"
#include "RendezVous.h"
#include"dossierChirurgical.h"
#include <vector>
#include<string>
#include<istream>
#include<ostream>
class Secretaire :public Personne
{
protected:
    float salaire;
    vector<RendezVous*> tab;
	vector<dossierChirurgical<int>*> dossiers;
public :
    Secretaire(int=0, string="", string="", int=0, float=0.0);
    void creerDossierChirurgical();
    void planifierRdv();
	void supprimerRdv(int);
    dossierChirurgical<int>* getDossierChirurgical(int);
    friend ostream& operator<<(ostream&, Secretaire&);
    friend istream& operator>>(istream&, Secretaire&);
    bool  operator==( Secretaire&);
    void saisir();
	void afficher();
    void consulterDossier(int& pos);
    void consulterToutLesDossier();

    void afficherTousLesRendezVous();

    ~Secretaire();
};

