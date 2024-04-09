#pragma once
#include "date.h"
#include<string>
class RendezVous
{
	date DateRdv;
	int heureRdv;
public:
	RendezVous(int = 0, int = 0, int = 0, int = 0);
	void saisir();
	void afficher();
	friend ostream& operator<<(ostream&, RendezVous&);
	friend istream& operator>>(istream&, RendezVous&);
	bool  operator==(RendezVous&);
	~RendezVous();
};

