#include "Chirurgien.h"
#include <iostream>
Chirurgien::Chirurgien(int numCin, string nom, string prenom, int numTel, string specialite) :Personne(numCin, nom, prenom, numTel), specialite(specialite)
{}

void Chirurgien::saisir()
{
    cout << "\t++++ Saisir du Chirurgien ++++" << endl << endl;
    Personne::saisir();
    cout << "Donner la specialite du chirurgien " << endl;
    cin >> specialite;
    cout <<endl<< "-----------------------------------------------------------------------------------" << endl;

}
void Chirurgien::afficher()
{
    cout << "\t ++++ Affichage des informations du Chirurgien ++++" << endl << endl;
	Personne::afficher();
    cout << "Specialite : " << specialite << endl;
    cout <<endl<< "-----------------------------------------------------------------------------------" << endl;

}
void Chirurgien::consulterDossier(Secretaire& s)
{
    int pos;
    cout << "Donner la position du Dossier à consulter ! " << endl;
    cin >> pos;
	s.consulterDossier(pos); 
}
void Chirurgien::saisirPatients()
{
    char rep;
    do {
        Patient* p = new Patient();
        p->saisir();
        tab.push_back(p);
        cout << "Voulez vous ajouter un patient ? o/n" << endl;
        cin >> rep;
    } while (rep == 'o');
}
void Chirurgien::modifierInfoPatient()
{
    int pos;
    cout <<endl<< "-----------------------------------------------------------------------------------" << endl;
    cout << "\t++++ Modifier les informations d'un patient ++++" << endl << endl;
    cout << "Donner son position : ";
    cin >> pos;  
    tab[pos]->saisir();

}
void Chirurgien::afficherTousLesPatients()
{
	cout << "\t++++ Liste des Patients ++++" << endl << endl;
    for (int i = 0;i < tab.size();i++)
        tab[i]->afficher();

}
void Chirurgien::AjouterNote(Secretaire& s)
{
    noteOperatoire note;
    int pos;
    cout << "\t ++++ Saisie d une nouvelle  note ++++: " << endl<<endl;
    cin >> note;
	cout << "donner la position du dossier ou vous allez ajouter la note" << endl;
    cin >> pos;
	dossierChirurgical* dc = s.getDossierChirurgical(pos);
    dc->ajouterNote(note);
}

void Chirurgien::ajouterComplication()
{
    int pos;
	cout << "\t++++ Ajouter une complication au patient ++++" << endl<<endl;
    cout << "Donner son position : ";
    cin >> pos;
	tab[pos]->ajouterComplication(); 
    cout <<endl<< "-----------------------------------------------------------------------------------" << endl;

}
void Chirurgien::supprimerComplicationDuPatient()
{
    int pos;
    int id;
    cout <<endl<< "-----------------------------------------------------------------------------------" << endl;
    cout << "\t++++ Supprimer une complication d'un patient ++++" << endl << endl;
    cout << "Donner son position : ";
    cin >> pos;
    cout << "Donner l'id de la complication à supprimer : ";
    cin >> id;
    tab[pos]->supprimerComplication(id);
    cout <<endl<< "-----------------------------------------------------------------------------------" << endl;

}

Chirurgien::~Chirurgien() {
    for (int i = 0;i < tab.size();i++)
        delete tab[i];
	tab.clear();
};