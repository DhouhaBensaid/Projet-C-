#pragma once
#include<string>
using namespace std;
class noteOperatoire
{
	int idNote;
	string description;
public:
	noteOperatoire(int = 0, string = "");
	void saisir();
	void afficher();
	friend ostream& operator<< (ostream&, noteOperatoire&);
	friend istream& operator >>(istream&, noteOperatoire&);

	bool operator==(noteOperatoire&);
	~noteOperatoire(void);
};

