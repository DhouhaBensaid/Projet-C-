#include "dossierChirurgical.h"
#include "dossierMedical.h"
#include <iostream>
using namespace std;
dossierChirurgical::dossierChirurgical(string nomP, string prenomP, int j, int m, int a, char sexe, string specialiste, string  type , int jI, int mI, int aI): dossierMedical(nomP,prenomP, j, m, a,sexe,specialiste), typeIntervention(type) , dateIntervention(jI,mI,aI)
 {
 }
void dossierChirurgical::ajouterNote(noteOperatoire no) 
{
    noteOperatoire* nvNote= new noteOperatoire(no); 
    notes.push_back(nvNote);
}
void dossierChirurgical::saisir() 
{
    char rep;
    cout << "\t ++++ Saisie des informations du dossier chirurgical ++++" << endl<<endl;
    dossierMedical::saisir();
    cout<< "Donner le type d intervention chirurgicale : ";
    cin >> typeIntervention;
    cout << "Donner la date de l'intervention chirurgical : " << endl;
    cin >> dateIntervention;
    cout << "Voulez vous ajouter une note operatoire au dossier ? (o / n)" << endl;
    cin >> rep;
    while (rep == 'o')
    {
        noteOperatoire note;
        cout<< "<<<< Saisie d une note >>>> " << endl<<endl;
        cin >> note;
        ajouterNote(note);
        cout<< "Voulez vous ajouter une note dossier ? (o / n)" << endl;
        cin >> rep;
    }
}

void dossierChirurgical::afficher() 
{
    cout << "\t ++++ Affichage informations du dossier chirurgical ++++" << endl << endl;
    dossierMedical::afficher();
    cout << "Type d intervention chirurgicale : " << typeIntervention << endl;
    cout << "Date de l intervention chirurgicale : "<<dateIntervention<< endl;
    cout << "Notes operatoires : " << endl;
    for (int i = 0;i<notes.size();i++)
    {
        notes[i]->afficher();
    }
    cout << endl;
}
void dossierChirurgical::modifierDate(date d) 
{
    dateIntervention = d;
}
ostream& operator<< (ostream& out, dossierChirurgical& dossier) 
{
    out << "Type d intervention chirurgicale : " << dossier.typeIntervention << endl;
    out << "Date de l intervention chirurgicale : " << dossier.dateIntervention << endl;
    out << "Notes operatoires : " << endl;
    return out;
}
istream& operator >> (istream& in, dossierChirurgical& dossier) {
    cout << "Donner le type d intervention chirurgicale : ";
    in >> dossier.typeIntervention;
    cout << "Donner la date de l intervention chirurgicale : ";
    in >> dossier.dateIntervention;
    return in;
}

bool dossierChirurgical::operator==(dossierChirurgical& dCh) {
    return (typeIntervention == dCh.typeIntervention && dateIntervention == dCh.dateIntervention);
}

dossierChirurgical::~dossierChirurgical() {
    for (int i = 0;i < notes.size();i++)
    {
        delete notes[i];
    }
    notes.clear();
}
