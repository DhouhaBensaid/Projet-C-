#include "Personne.h"
#include<iostream>
Personne::Personne(int numCin, string nom, string prenom, int numTel) : numCin(numCin), nom(nom), prenom(prenom), numTel(numTel) {}

Personne::~Personne() {}

ostream& operator<<(ostream& out,  Personne& personne) {
    //cout << "Affichage  des information du personne : " << endl;
    out << "NumCin: " << personne.numCin << ", Nom: " << personne.nom << ", Prenom: " << personne.prenom << ", NumTel: " << personne.numTel;
    return out;
}

istream& operator>>(istream& in, Personne& personne) {
    cout << "Enter NumCin: ";
    in >> personne.numCin;
    cout << "Enter Nom: ";
    in >> personne.nom;
    cout << "Enter Prenom: ";
    in >> personne.prenom;
    cout << "Enter NumTel: ";
    in >> personne.numTel;
    return in;
}

bool Personne::operator==( Personne& p) {
    return (numCin == p.numCin) && (nom == p.nom) && (prenom == p.prenom) && (numTel == p.numTel);
}
void Personne::afficher()
{
    //cout << "*** Affichage  des information du personne : ***" << endl;
    cout << "CIN : " << numCin << endl;
	cout << "Nom : " << nom << endl;
	cout << "Prenom : " <<prenom<< endl;
	cout << "Numero telephone : " <<numTel<< endl;
}
void Personne::saisir()
{
   // cout << "*** Saisir les information du personne : ***" << endl;
    cout << endl << "-----------------------------------------------------------------------------------" << endl;
    cout << "Donner CIN : "  << endl;
    cin >> numCin;
    cout << "Donner le Nom : " << endl;
    cin >> nom;
    cout << "Donner le Prenom : "  << endl;
	cin >> prenom;
    cout << "Donner le Numero telephone : " << endl;
    cin >> numTel;

}
