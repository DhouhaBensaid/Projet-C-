#pragma once
#include "dossierMedical.h"
#include"noteOperatoire.h"
#include"date.h"
#include<vector>
#include<string>
#include <iostream>
using namespace std;
template<class T>
class dossierChirurgical :public dossierMedical
{
	string typeIntervention;
	date dateIntervention;
	vector<noteOperatoire*> notes;
	T dureeIntervention;
public:
	dossierChirurgical(string = "", string = "", int = 0, int = 0, int = 0, char = 'F', string = "",string = "", int = 0, int = 0, int = 0,T=0);
	dossierChirurgical(const dossierChirurgical&);
	void saisir();
	void afficher();
	void modifierDate(date);
	void ajouterNote(noteOperatoire no);
	friend ostream& operator<< <> (ostream&, dossierChirurgical&);
	friend istream& operator>> <> (istream&, dossierChirurgical&);
	dossierChirurgical<T>& operator=(const dossierChirurgical<T>&);
	bool operator==(dossierChirurgical&);
	~dossierChirurgical();
};

template<class T>
dossierChirurgical<T>::dossierChirurgical(string nomP, string prenomP, int j, int m, int a, char sexe, string specialiste, string  type, int jI, int mI, int aI,T duree) :
	dossierMedical(nomP, prenomP, j, m, a, sexe, specialiste), typeIntervention(type), dateIntervention(jI, mI, aI),dureeIntervention(duree)
{
}
template<class T>
dossierChirurgical<T>::dossierChirurgical(const dossierChirurgical<T>& dC) :
	dossierMedical(dC), typeIntervention(dC.typeIntervention), dateIntervention(dC.dateIntervention),dureeIntervention(dC.dureeIntervention) {
	for (int i = 0;i < dC.notes.size();i++) {
		noteOperatoire* nv = new noteOperatoire(*dC.notes[i]);
		notes.push_back(nv);
	}

}
template<class T>
void dossierChirurgical<T>::ajouterNote(noteOperatoire no)
{
	noteOperatoire* nvNote = new noteOperatoire(no);
	notes.push_back(nvNote);
}
template<class T>
void dossierChirurgical<T>::saisir()
{
	char rep;
	cout << "\t ++++ Saisie des informations du dossier chirurgical ++++" << endl << endl;
	dossierMedical::saisir();
	cout << "Donner le type d intervention chirurgicale : ";
	cin >> typeIntervention;
	cout << "Donner la date de l'intervention chirurgical : " << endl;
	cin >> dateIntervention;
	cout << "Voulez vous ajouter une note operatoire au dossier ? (o / n)" << endl;
	cin >> rep;
	while (rep == 'o')
	{
		noteOperatoire note;
		cout << "<<<< Saisie d une note >>>> " << endl << endl;
		cin >> note;
		ajouterNote(note);
		cout << "Voulez vous ajouter une note dossier ? (o / n)" << endl;
		cin >> rep;
	}
}
template<class T>
void dossierChirurgical<T>::afficher()
{
	cout << "\t ++++ Affichage informations du dossier chirurgical ++++" << endl << endl;
	dossierMedical::afficher();
	cout << "Type d intervention chirurgicale : " << typeIntervention << endl;
	cout << "Date de l intervention chirurgicale : " << dateIntervention << endl;
	cout << "Notes operatoires : " << endl;
	for (int i = 0;i < notes.size();i++)
	{
		notes[i]->afficher();
	}
	cout << endl;
}
template<class T>
void dossierChirurgical<T>::modifierDate(date d)
{
	dateIntervention = d;
}
template<class T>
ostream& operator<< (ostream& out, dossierChirurgical<T>& dossier)
{
	dossierMedical* dm = &dossier;
	out << *dm;
	out << "Type d intervention chirurgicale : " << dossier.typeIntervention << endl;
	out << "Date de l intervention chirurgicale : " << dossier.dateIntervention << endl;
	out << "Notes operatoires : " << endl;
	return out;
}
template<class T>
istream& operator >> (istream& in, dossierChirurgical<T>& dossier) {
	dossierMedical* dm = &dossier;
	in >> *dm;
	cout << "Donner le type d intervention chirurgicale : ";
	in >> dossier.typeIntervention;
	cout << "Donner la date de l intervention chirurgicale : ";
	in >> dossier.dateIntervention;
	return in;
}
template<class T>
dossierChirurgical<T>& dossierChirurgical<T>::operator=(const dossierChirurgical<T>& dC) 
{
	if (this != &dC) {
		dossierMedical::operator=(dC);
		typeIntervention = dC.typeIntervention;
		dateIntervention = dC.dateIntervention;
		dureeIntervention = dC.dureeIntervention;
		for (int i = 0;i < dC.notes.size();i++)
			delete dC.notes[i];
		notes.clear();
		for (int i = 0;i < dC.notes.size();i++)
			notes.push_back(new noteOperatoire(*dC.notes[i]));
	}
	return *this;
}

template<class T>
bool dossierChirurgical<T>::operator==(dossierChirurgical& dCh) {
	return (typeIntervention == dCh.typeIntervention && dateIntervention == dCh.dateIntervention);
}
template<class T>
dossierChirurgical<T>::~dossierChirurgical() {
	for (int i = 0;i < notes.size();i++)
	{
		delete notes[i];
	}
	notes.clear();
}



