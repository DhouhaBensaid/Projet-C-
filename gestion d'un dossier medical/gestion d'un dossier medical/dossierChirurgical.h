#pragma once
#include "dossierMedical.h"
#include"noteOperatoire.h"
#include"date.h"
#include<vector>
#include<string>
using namespace std;
class dossierChirurgical :public dossierMedical
{
	string typeIntervention;
	date dateIntervention;
	vector<noteOperatoire*> notes;
public:
	dossierChirurgical(string = "", string = "", int = 0, int = 0, int = 0, char = 'F', string = "",string = "", int = 0, int = 0, int = 0);
	void saisir();
	void afficher();
	void modifierDate(date);
	void ajouterNote(noteOperatoire no);
	friend ostream& operator<< (ostream&, dossierChirurgical&);
	friend istream& operator >>(istream&, dossierChirurgical&);
		
	bool operator==(dossierChirurgical&);
	~dossierChirurgical();
};

