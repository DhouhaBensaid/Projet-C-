#include "Patient.h"
#include<iostream>
Patient::Patient(int numCin, string nom, string prenom, int numTel, char groupeSanguin) :Personne(numCin, nom, prenom, numTel), groupeSanguin(groupeSanguin)
{}

void Patient::saisir()
{
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
}

void Patient::afficher()
{
	Personne::afficher();
	cout << " Groupe sanguin : " <<groupeSanguin<< endl;
	for (int i = 0; i < tab.size(); i++)
	{
		tab[i]->afficher();
	}

}
ostream& operator<<(ostream& out, Patient& p)
{
	Personne* personne = &p;
	out << *personne;
	out << "Groupe Sanguin : " << p.groupeSanguin;
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