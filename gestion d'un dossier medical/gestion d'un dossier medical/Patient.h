#pragma once
#include "Personne.h"
#include"Complication.h"
#include<vector>
using namespace std;

class Patient : public Personne
{
	
	char groupeSanguin;
	vector<Complication*>tab;

public:
	Patient(int=0,string="", string="", int=0, char = 'A');
	
	friend ostream& operator<<(ostream&, Patient&);

	friend istream&  operator>>(istream&, Patient&);
	bool operator==(Patient&);
	void saisir();
	void afficher();
	void ajouterComplication();
	void supprimerComplication(int);
	~Patient();
};

