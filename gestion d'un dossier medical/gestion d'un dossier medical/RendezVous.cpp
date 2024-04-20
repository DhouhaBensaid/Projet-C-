#include "RendezVous.h"
#include <iostream>
int RendezVous::totalRdv = 0;
RendezVous::RendezVous(int j, int m, int a, int h):DateRdv(j, m, a), heureRdv(h)
{
	totalRdv++;
}

void RendezVous::saisir()
{
	cout << "*** Saisir d'un Rendez-Vous ***" << endl;
	cout << "Date du Rendez-Vous" << endl;
	cin >> DateRdv;
	cout << " Donner l'heure du Rendez-Vous" << endl;
	cin >> heureRdv;

}

void RendezVous::afficher()
{
	//cout << "*** Affichage des informations du Rendez-Vous ***" << endl;
	cout << "Date Rendez-Vous : " << DateRdv << endl;
	cout << "Heure du Rendez-Vous : " << heureRdv << endl<<endl; 
}

ostream& operator<<(ostream& out, RendezVous& rdv)
{
	cout << "*** Affichage des informations du Rendez-Vous par operator<< ***" << endl;
	out << "Date Rendez-Vous : " << rdv.DateRdv << endl;
	out << "Heure du Rendez-Vous : " << rdv.heureRdv << endl;
	return out;
}
istream& operator>>(istream& in, RendezVous& rdv)
{
	cout << "*** Saisir d'un Rendez-Vous par operator ***" << endl;
	cout << "Date du Rendez-Vous" << endl;
	in >> rdv.DateRdv;
	cout << " Donner l'heure du Rendez-Vous" << endl;
	in >> rdv.heureRdv;
	return in;
}

bool RendezVous::operator==(const RendezVous& rdv) const {
	return (heureRdv == rdv.heureRdv);
}

RendezVous::~RendezVous() {};