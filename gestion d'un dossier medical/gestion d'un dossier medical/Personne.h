#pragma once
#include<string>
#include<istream>
#include<ostream>
using namespace std;
class Personne
{
	int numCin;
	string nom;
	string prenom;
	int numTel;
public:
	Personne(int, string, string, int);
	virtual ~Personne();
	virtual void afficher(string="")=0;
	virtual void saisie() = 0;
	friend ostream& operator<<(ostream&, Personne&);
	friend istream& operator>>(istream&, Personne&);
	friend istream& operator==(istream&, Personne&);

};

