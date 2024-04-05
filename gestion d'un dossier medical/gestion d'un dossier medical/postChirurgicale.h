#pragma once
#include "dossierMedical.h"
#include "date.h"
#include"Complication.h"
#include<istream>
#include<ostream>
#include<vector>
#include<string>
using namespace std;
class postChirurgicale :public dossierMedical
{
protected:
    date DateRdv;
    string heureRdv;
    string objectifsRdv;
    string progresRealises;
    vector<Complication*>tab;
public:
    postChirurgicale(string = "", string = "", int = 0, int = 0, int = 0, char = 'F', string = "", string = "", string = "", string = "");
    void saisir();
    void afficher();
    void modifierDate(date);
    void ajouterComplication();
    friend ostream& operator<< (ostream&, postChirurgicale&);
    friend istream& operator >>(istream&, postChirurgicale&);
    bool operator==(postChirurgicale&);
    ~postChirurgicale();
};

