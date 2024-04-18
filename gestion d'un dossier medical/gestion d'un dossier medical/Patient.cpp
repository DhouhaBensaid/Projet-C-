#include "Patient.h"
#include<iostream>
#include "Secretaire.h"
Patient::Patient(int numCin, string nom, string prenom, int numTel, char groupeSanguin) :Personne(numCin, nom, prenom, numTel), groupeSanguin(groupeSanguin)
{
}

void Patient::saisir()
{
	cout << "\t ++++ Saisir du Patient ++++" << endl;
	char rep;
	Personne::saisir();
	cout << "Donner le groupe sanguin du patient : " << endl;
	cin >> groupeSanguin;
	cout << "Voulez vous ajouter une complication au patient ? (o / n)" << endl;
	cin >> rep;
	while (rep == 'o')
	{
		ajouterComplication();
		cout << "Voulez vous ajouter une complication au patient ? (o / n)" << endl;
		cin >> rep;
	}
	cout << endl << "-----------------------------------------------------------------------------------" << endl;

}

void Patient::afficher()
{
	cout << "\t ++++Affichage des information du patient ++++" << endl << endl;
	Personne::afficher();
	cout << " Groupe sanguin : " <<groupeSanguin<< endl;
	for (int i = 0; i < tab.size(); i++)
	{
		tab[i]->afficher();
	}
	cout << endl << "-----------------------------------------------------------------------------------" << endl;

}
ostream& operator<<(ostream& out, Patient& p)
{
	Personne* personne = &p;
	out << *personne;
	out << "Groupe Sanguin : " << p.groupeSanguin;
	return out;
}
ostream& operator<<(ostream& out, Patient* p)
{
	Personne* personne = p;
	out << personne;
	out << ",Groupe Sanguin :" << p->groupeSanguin;
	for (int i = 0; i < p->tab.size(); i++) {
		out << p->tab[i];
	}
	return out;

}

istream& operator>>(istream& in, Patient& p)
{
	Personne* personne = &p;
	in >> *personne;
	cout << "Donner le groupe sanguin" << endl;
	in >> p.groupeSanguin;
	return in;
}
istream& operator>>(istream& in, Patient* p)
{
	Personne* personne = p;
	in >> personne;
	cout << "Donner le groupe sanguin" << endl;
	in >> p->groupeSanguin;
	return in;
}
Patient& Patient::operator=(const Patient& p)
{
	if (this != &p)
	{
		this->numCin = p.numCin;
		this->nom = p.nom;
		this->prenom = p.prenom;
		this->numTel = p.numTel;
		this->groupeSanguin = p.groupeSanguin;
		for (int i = 0;i < p.tab.size();i++) 
			delete p.tab[i];
		tab.clear();
		for (int i = 0;i < p.tab.size();i++) 
			tab.push_back(new Complication(*p.tab[i]));
	}
	return *this;
}



bool Patient::operator==(Patient& p)
{
	return (groupeSanguin == p.groupeSanguin);
}
void Patient::ajouterComplication()
{
	Complication* c = new Complication(); 
	c->saisir();
	tab.push_back(c);
}
void Patient::supprimerComplication(int id)
{
	for (int i = 0;i < tab.size();i++)
	{
		if (tab[i]->getId() == id)
			tab.erase(tab.begin() + i);
		else
			cout << "Cette complication ou l id est" << id << "n'existe pas " << endl;
	}
}

Patient::~Patient() {
	for (int i = 0;i < tab.size();i++)
		delete tab[i];
	tab.clear();
};