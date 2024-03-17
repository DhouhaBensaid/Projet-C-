#pragma once
#include "Personne.h"
#include<istream>
#include<ostream>
class Patient : public Personne
{
	char groupeSanguin;
public:
	Patient(int,string,string,int,char);
	void prendreRdv();
	void annulerRdv();
	friend ostream& operator<<(ostream&, Patient&);
	friend istream  operator>>(istream&, Patient&);
	friend istream operator==(istream&, Patient&);
};

