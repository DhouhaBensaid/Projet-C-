#pragma once
#include<string>
#include<istream>
#include<ostream>
using namespace std;
class Complication
{
	int id;
	string type;
	string gravite;
public:
	Complication(int=0,string="", string="");
	//Complication();
	void saisir();
	void afficher();
	int getId() { return id; };
	friend ostream operator<<(ostream&, Complication&);
	friend istream operator>>(istream&, Complication&);
	bool  operator==(Complication&);
	~Complication();

};

