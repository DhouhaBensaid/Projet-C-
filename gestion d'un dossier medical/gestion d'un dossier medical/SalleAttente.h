#pragma once
#include<map>
#include"Patient.h"
#include"RendezVous.h"
#include"date.h"

class SalleAttente
{
	map<int, Patient>m;
	list<RendezVous>l;
public:
	SalleAttente();
	~SalleAttente();
	friend ostream& operator<< (ostream&, SalleAttente&);
	friend istream& operator>> (istream&, SalleAttente&);
	RendezVous operator==(const RendezVous);
	RendezVous operator <(const RendezVous);
	void inserer(pair<int, Patient>);
	map<int, Patient>::iterator rechercher(int);//NumCIN
	map<int, Patient>::iterator rechercher(string);//Nom
	map<int, Patient>::iterator fin() { return m.end(); }
	void modifierNumtel(int numcin, int numtel);//modifier numtel
	void modifierNumtel(string nom, int numtel);
	void supprimer(int);//numCin
	void supprimer(string);//nom

	void afficherToutRdv();//for-each
	void ajouterRdv(RendezVous);//pushback
	bool supprimerDoublonsRdv(RendezVous);//remove
	RendezVous rechercherRdv(date);//find
	int nombreRdv();//count
	void insererRdv(int, RendezVous);//position,insert(position,valeur)
	void supprimerRdv();//clear,earse(position)
	




};

