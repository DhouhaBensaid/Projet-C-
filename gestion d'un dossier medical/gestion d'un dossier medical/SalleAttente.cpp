#include "SalleAttente.h"
#include"RendezVous.h"
#include<iostream>
#include <algorithm>
using namespace std;

SalleAttente::SalleAttente() {};
void SalleAttente::afficherToutRdv()
{
    cout << "Affichage de tous les rendez-vous dans la salle d'attente." << endl;
    list<RendezVous>::iterator it;
    for (it = l.begin(); it != l.end(); ++it)
        it->afficher();
}
void SalleAttente::ajouterRdv()
{
    cout << "Ajout d'un rendez-vous dans la salle d'attente." << endl;
    char rep;
    do {
        RendezVous nvRdv;
        cin >> nvRdv;
        l.push_back(nvRdv);
        cout << "Voulez Vous ajouter un rendezVous ? 'o/n'";
        cin >> rep;
    }
    while (rep == 'o');
}

void SalleAttente::supprimerDoublonsRdv()
{
    cout << "Suppression des doublons de rendez-vous dans la salle d'attente." << endl;
    l.unique();
}


list<RendezVous>::iterator SalleAttente::rechercherRdv( RendezVous& rdv)
{
    return find(l.begin(), l.end(), rdv);
}


int SalleAttente::nombreRdv()
{
    cout << "Calcul du nombre de rendez-vous dans la salle d'attente." << endl;
    int count = 0;
    list<RendezVous>::iterator it;
    for (it = l.begin(); it != l.end(); ++it) 
        count++; 
    return count;
}
void SalleAttente::insererRdv()
{
    cout << "Insertion d'un rendez-vous à une position specifique dans la salle d'attente." << endl;
    int pos;
    list<RendezVous>::iterator it;
    cout << "Donner la position ou vous voulez inserer le rendez-vous : ";
    cin >> pos;
    RendezVous nvRdv;
    cin >> nvRdv;

    if ( pos <= l.size()) {
        it = l.begin();
        advance(it, pos); 
        l.insert(it, nvRdv);
    }
    else 
        cout << "Position invalide, l insertion a echoue" << endl;
    
}
void SalleAttente::supprimerToutRdv()
{
    cout << "Suppression de tous les rendez-vous dans la salle d'attente." << endl;
    l.clear();
}

//Map functions
ostream& operator<< (ostream& out , SalleAttente& s)
{
    map<int, Patient>::iterator it;
    cout << "Nombre des Patient" << s.m.size() << endl;
    for (it = s.m.begin(); it != s.m.end();it++)
    {
        out << "cle : " << it->first << endl;
		out << "Valeur " << it->second << endl;
    }
    return out;
}

istream& operator>> (istream& in, SalleAttente& s)
{
    int cle;
    Patient p;
    char rep;
    do {
        cout << "Saisir la cle" << endl;
        in >> cle;
        cout << "Saisir Valeur" << endl;
        in >> p;
        cout << "Voulez vous rajouter ? 'o/n'";
        cin >> rep;

    } while (rep == 'o');
    return in;
}
map<int, Patient>::iterator SalleAttente::rechercher(int numCin)
{
    cout << "Recherche d'un patient par numéro de CIN." << endl;
    map<int, Patient>::iterator it;
    it = m.find(numCin);
    return it;
}
void SalleAttente::inserer(pair<int, Patient> p)
{
    cout << "Insertion d'un patient dans la salle d'attente." << endl;
    m.insert(p);
}
map<int, Patient>::iterator SalleAttente::rechercher(string val)
{
    cout << "Recherche d'un patient par nom." << endl;
    map<int, Patient>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
        if ((it->second).getNom() == val) return it;
    return it;
}
void SalleAttente::modifierNumtel(int numcin, int numtel)
{
    cout << "Modification du numéro de téléphone d'un patient par numéro de CIN." << endl;
    map<int, Patient>::iterator it;
    it = m.find(numcin);
	if (it != m.end())
		(it->second).setNumTel(numtel);
}

void SalleAttente::modifierNumtel(string nom, int numtel)
{
    cout << "Modification du numéro de téléphone d'un patient par nom." << endl;
    map<int, Patient>::iterator it;
    it = rechercher(nom);
    if (it != m.end())
        (it->second).setNumTel(numtel);
}
void SalleAttente::supprimer(int numCin)
{
    cout << "Suppression d'un patient par numéro de CIN." << endl;
    m.erase(numCin);
}

void SalleAttente::supprimer(string nom)
{
    cout << "Suppression d'un patient par nom." << endl;
    map<int, Patient>::iterator it;
    it = rechercher(nom);
    if(it!=m.end())
        m.erase(it);
}


SalleAttente::~SalleAttente() {};
