#pragma once
#include<string>
using namespace std;
class noteOperatoire
{
	int idNote;
	string description;
	int duree;
public:
	noteOperatoire(int = 0, string = "", int = 0);
	void saisir();
	void afficher();
	friend ostream& operator<< (ostream&, noteOperatoire&);
	friend istream& operator >>(istream&, noteOperatoire&);

	bool operator==(noteOperatoire&);
	~noteOperatoire(void);
};

