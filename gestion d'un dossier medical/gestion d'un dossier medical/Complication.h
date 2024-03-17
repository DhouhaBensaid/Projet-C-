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
	Complication(int,string,string);
	void saisir();
	void afficher(string = "");
	friend ostream operator<<(ostream&, Complication&);
	friend istream operator>>(istream&, Complication&);
	friend istream operator==(istream&, Complication&);
	~Complication();

};

