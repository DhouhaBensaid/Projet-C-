#pragma once
#include"dossierMedical.h"
#include"Personne.h"
#include<vector>
class service
{
	vector<dossierMedical*>dossierMed;
	vector<Personne*>personne;

public:
	service();
	service( const service&);
	int tailleDossierMed(){ return dossierMed.size();}
	int taillePersonne() { return personne.size(); }
	friend ostream& operator<<(ostream&, service&);
	friend istream& operator>>(istream&, service&);
	void saisir();
	void afficher(service);
	~service();


};

