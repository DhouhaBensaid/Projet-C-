#pragma once
#include<string>
using namespace std;
class Intervention
{
    int idIntervention;
    string nom;
    int duree; 

public:
    Intervention(int id = 0,string = "", int duree = 0);
    void saisir();
    void afficher() ;
    friend ostream& operator<<(ostream&, Intervention&);
    friend istream& operator>>(istream&, Intervention&);
    Intervention operator+(const Intervention&);
};

