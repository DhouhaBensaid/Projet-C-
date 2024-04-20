#pragma once
#include "Personne.h"
#include"Complication.h"
#include"Intervention.h"
#include<vector>
#include<list>
using namespace std;

class Patient : public Personne
{
	
	char groupeSanguin;
	vector<Complication*>tab;

public:
	Patient(int=0,string="", string="", int=0, char = 'A');
	
	friend ostream& operator<<(ostream&, Patient&);
	friend ostream& operator<<(ostream&, Patient*);
	friend istream&  operator>>(istream&, Patient&);
	friend istream& operator>>(istream&, Patient*);
	Patient& operator=(const Patient&);
	bool operator==(Patient&);
	int getNumCin() const{ return this->numCin; };
	string getNom() { return this->nom; };
	void setNumTel(int numTel) { this->numTel = numTel; }

	void saisir();
	void afficher();
	void ajouterComplication();
	void supprimerComplication(int);
	void modifierNumeroTel(int);
	~Patient();
};

