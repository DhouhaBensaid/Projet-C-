#pragma once
#include<string>
#include<istream>
#include<ostream>
using namespace std;
class Personne
{
protected :
	int numCin;
	string nom;
	string prenom;
	int numTel;
public:
	Personne(int, string, string, int);
	virtual ~Personne();
	virtual void afficher()=0;
	virtual void saisir() = 0;
	friend ostream& operator<<(ostream&, Personne&);
	friend istream& operator>>(istream&, Personne&);
	bool operator==(Personne&);

};

