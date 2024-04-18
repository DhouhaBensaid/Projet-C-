#include "Secretaire.h"
#include "dossierChirurgical.h"
#include <stdexcept>
#include <iostream>
#pragma once
Secretaire::Secretaire(int numCin, string nom, string prenom, int numTel, float salaire) : Personne(numCin, nom, prenom, numTel), salaire(salaire) {}

void Secretaire::creerDossierChirurgical() {
    char rep;
    do {

        cout << "\t<<<< Creation d'un dossier chirurgical >>>>" << endl<<endl;
        dossierChirurgical<int>* dc = new dossierChirurgical<int>();
        dc->saisir();
        dossiers.push_back(dc);
		cout << "Voulez Vous ajouter un dossier chirurgical ? o/n" << endl;
        cin >> rep;
    } while (rep == 'o');
    cout << endl << "-----------------------------------------------------------------------------------" << endl;

}

void Secretaire::planifierRdv() {
    char rep;
    cout << "\t ++++ Planification des rendez-Vous ++++" << endl << endl;
    do {
        RendezVous* rdv = new RendezVous();
        rdv->saisir();
        tab.push_back(rdv);
        cout << "Voulez vous ajouter un Rendez-Vous ? o/n " << endl;
        cin >> rep;
    }
    while (rep == 'o');
    
    cout << endl << "-----------------------------------------------------------------------------------" << endl;

}
void Secretaire::supprimerRdv(int pos) {
    try {
        cout << "\t ++++ Suppression du rendez-Vous qui a la position " << pos << " ++++" << endl << endl;
        if (pos >= 0 && pos < tab.size()) {
            tab.erase(tab.begin() + pos);
        }
        else {
            throw out_of_range("Invalid rendez-vous position"); 
        }
        cout << endl << "-----------------------------------------------------------------------------------" << endl;
    }
    catch (const exception& e) {
        cout << "Exception caught: " << e.what() << endl; 
    }
}

dossierChirurgical<int>* Secretaire::getDossierChirurgical(int pos)
{
    return dossiers[pos];
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
Secretaire& Secretaire::operator=(const Secretaire& s)
{
    if (this != &s)
    {
        this->numCin = s.numCin;
        this->nom = s.nom;
        this->prenom = s.prenom;
        this->numTel = s.numTel;
        this->salaire = s.salaire;
        for (int i = 0;i<s.tab.size();i++) 
            delete s.tab[i];
        tab.clear();
        for (int i = 0;i < s.tab.size();i++) 
            tab.push_back(new RendezVous(*s.tab[i]));
        
        for (int i = 0;i < s.dossiers.size();i++) 
            delete s.dossiers[i];
        dossiers.clear();
        for (int i = 0;i < s.dossiers.size();i++) 
            dossiers.push_back(new dossierChirurgical<int>(*s.dossiers[i]));
    }
    return *this;
}

bool Secretaire::operator==(Secretaire& s) {
	bool res = Personne::operator==(s);
    if (  res && salaire == s.salaire   ) return true;
    else return false;
}

void Secretaire::afficher()
{
    cout << "\t +++++ Affichage des information du Secretaire +++++" << endl << endl;
	Personne::afficher();
    cout << "Salaire : " << salaire << endl << endl;
    cout << endl << "-----------------------------------------------------------------------------------" << endl;


}
void Secretaire::afficherTousLesRendezVous()
{
    cout << "\t ++++ Liste des Rendez-Vous ++++ : " << endl << endl;
    for (int i = 0;i < tab.size();i++)
    {
        tab[i]->afficher();
    }
    cout << endl << "-----------------------------------------------------------------------------------" << endl;
}
void Secretaire::consulterToutLesDossier()
{
    cout << "\t ++++ Liste des dossiers ++++ : " << endl << endl;
    for (int i = 0;i < dossiers.size();i++)
    {
        dossiers[i]->afficher();
    }
    cout << endl << "-----------------------------------------------------------------------------------" << endl;

}
void Secretaire::consulterDossier(int& pos) {
    try {
        cout << endl << "-----------------------------------------------------------------------------------" << endl;
        if (pos >= 0 && pos < dossiers.size()) {
            dossiers.at(pos)->afficher(); // Use at() function for bounds checking
        }
        else {
            throw out_of_range("Invalid dossier position"); // Throw an out_of_range exception for invalid position
        }
        cout << endl << "-----------------------------------------------------------------------------------" << endl;
    }
    catch (const exception& e) {
        cout << "Exception caught: " << e.what() << endl; // Print exception message
    }
}

void Secretaire::saisir() {
    try {
        cout << "\t++++ Saisir du Secretaire ++++" << endl << endl;
        Personne::saisir();
        cout << "Donner Salaire : ";
        cin >> salaire;
        if (salaire < 0) {
            throw invalid_argument("Salaire invalide : doit être un nombre positif");
        }
        cout << endl << "-----------------------------------------------------------------------------------" << endl;
    }
    catch (const exception& e) {
        cout << "Erreur : " << e.what() << endl;

    }
}
Secretaire::~Secretaire() {
    for (int i = 0;i < tab.size();i++)
    {
        delete tab[i];
    }
    for (int i = 0;i < dossiers.size();i++)
    {
        delete dossiers[i];
    }
    tab.clear();
	dossiers.clear(); 
};
