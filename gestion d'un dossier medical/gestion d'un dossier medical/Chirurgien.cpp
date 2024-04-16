#include "Chirurgien.h"
#include <iostream>
#include<fstream>
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
void Chirurgien::saisirPatients(fstream& f)
{
    char rep;
    do {
        Patient* p = new Patient();
        p->saisir();
        tab.push_back(p);
        f << p << endl;
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
void Chirurgien::creer(fstream& f)
{
    f.open(/*"C:\\Users\\marwa\\patients.txt"*/"C:\\Users\\hp\\Desktop\\patients.txt", ios::in | ios::out | ios::trunc);
    if (!f.is_open()) {
        cout << "Erreur: Impossible d'ouvrir le fichier pour écriture." << endl;
        exit(-1);
    }
}
void Chirurgien::supprimerPatient(fstream& f)
{
    int pos;
    cout << "Donner la position du patient à supprimer dans le tableau : ";
    cin >> pos;
    int cin = tab[pos]->getNumCin();
	tab.erase(tab.begin() + pos);
    string ligne;
    bool patientTrouve = false;
    fstream fichierTemp(/*"C:\\Users\\marwa\\temp.txt"*/"C:\\Users\\hp\\Desktop\\temp.txt", ios::in | ios::out | ios::trunc);
    if (!fichierTemp.is_open()) {
        cout << "Erreur: Impossible d'ouvrir le fichier temporaire pour écriture." << endl;
        exit(-1);
    }
    f.seekg(0);
    while (getline(f, ligne)) {
        if (ligne.substr(0, 8) == "NumCin: ") {
            // Extraire le numéro de CIN après "NumCin: "
            string numCINFromLine = ligne.substr(8, 8); // Commence à l'index 8, longueur 8
            if (to_string(cin) == numCINFromLine) {
                patientTrouve = true;
                cout << "Patient trouvé " << endl;
            }
            else {
                fichierTemp << ligne << endl;
            }
        }
    }
    // Fermer les fichiers
    f.close();
    fichierTemp.close();

    // Supprimer le fichier original
    remove("C:\\Users\\marwa\\patients.txt");
    // Renommer le fichier temporaire pour remplacer le fichier original
    rename(/*"C:\\Users\\marwa\\temp.txt"*/"C:\\Users\\hp\Desktop\\temp.txt", /*"C:\\Users\\marwa\\patients.txt"*/"C:\\Users\\hp\\Desktop\\patients.txt");

    if (!patientTrouve) {
        cout << "Patient avec le numero de CIN donne non trouve." << endl;
    }
    else {
        cout << "Patient supprime avec succes." << endl;
    }
}

void Chirurgien::afficherAPartirDuFicher(fstream& f)
{
    cout << "***Affichage a partir du ficher****" << endl;
    f.open(/*"C:\\Users\\marwa\\patients.txt"*/"C:\\Users\\hp\\Desktop\\patients.txt", ios::in);
    if (!f.is_open()) {
        cout << "Erreur: Impossible d'ouvrir le fichier pour la lecture." << endl;
        exit(-1);

    }
    string ligne;
    while (getline(f, ligne))
    {
        cout << ligne << endl;
    }
    f.close();
 }




Chirurgien::~Chirurgien() {
    for (int i = 0;i < tab.size();i++)
        delete tab[i];
	tab.clear();
};