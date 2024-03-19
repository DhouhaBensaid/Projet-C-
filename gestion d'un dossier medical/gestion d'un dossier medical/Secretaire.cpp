#include "Secretaire.h"
#include <iostream>
#pragma once
Secretaire::Secretaire(int numCin, string nom, string prenom, int numTel, float salaire) : Personne(numCin, nom, prenom, numTel), salaire(salaire) {}

void Secretaire::creerDossierMedicale() {
}



void Secretaire::creerDossierChirurgical() {
}

void Secretaire::planifierRdv() {
}

ostream& operator<< (ostream& out, Secretaire& s) {
    Personne* p = &s;
    out <<*p; // appel de operator<< de la classe personne
    out << "Salaire : " << s.salaire;
    return out;
}

istream& operator>> (istream& in, Secretaire& s) {
    Personne* p = &s;
    in >> *p;
    cout << "Enter Salaire: ";
    in >> s.salaire;
    return in;
}

bool Secretaire::operator==(Secretaire& s) {
	bool res = Personne::operator==(s);
    if (  res && salaire == s.salaire   ) return true;
    else return false;
}

void Secretaire::afficher()
{
	Personne::afficher();
    cout << "Salaire : " << salaire << endl;

}
void Secretaire::saisir()
{
    Personne::saisir();
    cout << "Donner Salaire " << endl;
    cin >> salaire;
}
Secretaire::~Secretaire() {};
