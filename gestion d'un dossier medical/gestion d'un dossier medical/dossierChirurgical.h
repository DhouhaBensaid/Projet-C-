#pragma once
#include "postChirurgicale.h"
#include"noteOperatoire.h"
#include"date.h"
#include<vector>
#include<string>
using namespace std;
class dossierChirurgical :public postChirurgicale
{
	string typeIntervention;
	date dateIntervention;// on ne peut pas declarer chirurgien car classe abstraite
	vector<noteOperatoire*> notes;
public:
	dossierChirurgical(string = "", string = "", int = 0, int = 0, int = 0, char = 'F', string = "", string = "", string = "", string = "",string = "", int = 0, int = 0, int = 0);
	void saisir();
	void afficher();
	void modifierDate(date);
	void ajouterNote(noteOperatoire no);
	friend ostream& operator<< (ostream&, dossierChirurgical&);
	friend istream& operator >>(istream&, dossierChirurgical&);
		
	bool operator==(dossierChirurgical&);
	~dossierChirurgical();
};

