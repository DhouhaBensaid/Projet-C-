#include "postChirurgicale.h"
#include"dossierMedical.h"
#include "date.h"
#include<iostream>
using namespace std;
postChirurgicale::postChirurgicale(string nomP, string prenomP, int j, int m, int a, char sexe, string specialiste, string heureRd, string objectifRd, string progres)
	: dossierMedical(nomP, prenomP, j, m, a, sexe, specialiste), heureRdv(heureRd), objectifsRdv(objectifRd), progresRealises(progres) {}

void postChirurgicale::saisir()
{
	char rep;
	cout << "***Saisie des informations du post chirurgical***" << endl;
	dossierMedical::saisir();
	cout << "Donner l heure du rendez-vous " << endl;
	cin >> heureRdv;
	cout << "Donner la date de rendez-vous" << endl;
	cin >> DateRdv;
	cout << " Donner le progres du rendez - vous" << endl;
	cin >> progresRealises;
	cout << "Donner l objectif de rendez-vous" << endl;
	cin >> objectifsRdv;
	cout << "Voulez vous ajouter une complication au patient ? (o / n)" << endl;
	cin >> rep;
	while (rep == 'o')
	{
		ajouterComplication();
		cout << "Voulez vous ajouter une complication au patient ? (o / n)" << endl;
		cin >> rep;
	}
}
void postChirurgicale::afficher()
{
	cout << "***Affichage des informations du post chirurgical***" << endl;
	dossierMedical::afficher();
	cout << "Heure du rendez-vous : " << heureRdv << endl;
	cout << "Date du rendez-vous : " << DateRdv << endl;
	cout << "Progres realises au cours du rendez-vous : " << progresRealises<< endl;
	cout << "Objectifs du rendez-vous : " << objectifsRdv<< endl;
	for (int i = 0; i < tab.size(); i++)
	{
		tab[i]->afficher();
	}

}
void postChirurgicale::modifierDate(date d)
{
	DateRdv= d;// I think zeyda el fonction!!!!
}
void postChirurgicale::ajouterComplication() 
{
	Complication* nvComplication= new Complication(); 
	nvComplication->saisir();
	tab.push_back(nvComplication);
}

ostream& operator<< (ostream& out, postChirurgicale& post)
{
	dossierMedical* dossier = &post;
	out << *dossier;
	out<< "Date du rendez-vous : " << post.DateRdv << endl;
	out<< "Heure du rendez-vous : " << post.heureRdv << endl;
	out<< "Objectifs du rendez-vous : " << post.objectifsRdv << endl;
	out<< "Progrès réalises : " << post.progresRealises << endl;
	return out;
}
istream& operator >>(istream& in, postChirurgicale& post)
{
	dossierMedical* dossier = &post;
	in>> *dossier;
	cout << "donner l heure du rendez-vous " << endl;
	in >> post.heureRdv;
	cout << "donner la date de rendez-vous" << endl;
	in >> post.DateRdv;
	cout << "donner le progres du rendez-vous" << endl;
	in >> post.progresRealises;
	cout << "donner l objectif de rendez-vous" << endl;
	in >>post.objectifsRdv;
	return in;
}
bool postChirurgicale::operator == (postChirurgicale& post) 
{
	return (DateRdv == post.DateRdv &&
		heureRdv == post.heureRdv &&
		objectifsRdv == post.objectifsRdv &&
		progresRealises == post.progresRealises);
}
postChirurgicale::~postChirurgicale()
{
	for (int i = 0; i < tab.size(); i++)
		delete tab[i];
	tab.clear();
}