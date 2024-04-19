#include "SalleAttente.h"
#include"RendezVous.h"
#include<iostream>
#include <algorithm>
using namespace std;
void SalleAttente::afficherToutRdv()
{
    list<RendezVous>::iterator it;
    for (it = l.begin(); it != l.end(); ++it)
        it->afficher();
}
void SalleAttente::ajouterRdv(RendezVous nvRdv)
{
    l.push_back(nvRdv);
}
bool SalleAttente::supprimerDoublonsRdv(RendezVous rdv)
{
    l.remove(rdv);
    return true;
}
RendezVous  SalleAttente::rechercherRdv(date d)
{
    list<RendezVous>::iterator it;
    find(l.begin(), l.end(), d);
    if (it != l.end()) 
        return *it;
    else 
        return RendezVous();
}
int SalleAttente::nombreRdv()
{
    int count = 0;
    list<RendezVous>::iterator it;
    for (it = l.begin(); it != l.end(); ++it) 
        count++; 
    return count;
}
void SalleAttente::insererRdv(int pos, RendezVous rdv)
{
    list<RendezVous>::iterator it;
    if ( pos <= l.size()) {
        it = l.begin();
        advance(it, pos); 
        l.insert(it, rdv);
    }
    else 
        cout << "Position invalide, l insertion a echoue" << endl;
    
}
void SalleAttente::supprimerRdv()
{
    l.clear();
}
