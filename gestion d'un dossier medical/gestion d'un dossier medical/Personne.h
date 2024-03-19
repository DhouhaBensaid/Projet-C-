#pragma once
#include<string>
using namespace std;
#include<istream>
#include<ostream>
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
	friend std::ostream& operator<<(std::ostream&, Personne&);
	friend istream& operator>>(istream&, Personne&);
	bool operator==(Personne&);

};

