#include "intervention.h"
#include<iostream>
using namespace std;
Intervention::Intervention(int id,  string nom, int duree) : idIntervention(id), nom(nom), duree(duree) 
{}


void Intervention::saisir() {
    cout << "donner ID de l intervention : " << endl;
    cin >> idIntervention;
    cout << " donner nom de l intervention : " << endl;
    cin >> nom;
    cout << "donner duree de l intervention : " << endl;
    cin >> duree;
}

void Intervention::afficher()  {
    cout << "ID de l  intervention : " << idIntervention << endl;
    cout << "Nom de l intervention : " << nom << endl;
    cout << "Duree de l intervention : " << duree << endl;
}

ostream& operator<<(ostream& out, Intervention& intervention) {
    out << "ID : " << intervention.idIntervention << ", Nom : " << intervention.nom << ", Duree : " << intervention.duree;
    return out;
}
istream& operator>>(istream& in, Intervention& intervention) {
    cout << "ID de l intervention : ";
    in >> intervention.idIntervention;
    cout << "Nom de l intervention : ";
    in >> intervention.nom;
    cout << "Duree de l intervention : ";
    in >> intervention.duree;
    return in;
}
Intervention Intervention::operator+(const Intervention& i) 
{
    Intervention res;
    res.duree = this->duree + i.duree; 
    return res;
}
#include "Intervention.h"
