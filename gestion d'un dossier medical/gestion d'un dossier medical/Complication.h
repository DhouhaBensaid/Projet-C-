#pragma once
#include<string>
#include<istream>
#include<ostream>
using namespace std;
class Complication
{
	int idComplication;
	string type;
	string gravite;
public:

	Complication(int=0,string="", string="");
	void saisir();
	void afficher();
	int getIdComplication() { return idComplication; }
	friend ostream& operator<<(ostream&, Complication&);
	friend ostream& operator<<(ostream&, Complication*);

	friend istream& operator>>(istream&, Complication&);
	friend istream& operator>>(istream&, Complication*);

	bool  operator==(Complication&);
	~Complication();

};

