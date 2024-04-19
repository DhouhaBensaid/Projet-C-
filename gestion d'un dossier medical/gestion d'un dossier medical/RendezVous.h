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
	date getDateRdv() { return this->DateRdv; }
	int getHeureRdv() { return this->heureRdv; }
	friend ostream& operator<<(ostream&, RendezVous&);
	friend istream& operator>>(istream&, RendezVous&);
	~RendezVous();
};

