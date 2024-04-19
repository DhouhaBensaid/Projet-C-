#pragma once
#include "Personne.h"
#include"Patient.h"
#include"Complication.h"
#include "Secretaire.h"
#include<string>
#include<vector>
using namespace std;
class Chirurgien :
    public Personne
{
    string specialite;
    vector<Patient*>tab;

public :
    Chirurgien(int=0, string="", string="", int=0, string="");
    void saisir();
	void afficher();
    void saisirPatients(fstream&);
    void consulterDossier(Secretaire&);
    void AjouterNote(Secretaire&);
    void ajouterComplication();
    void modifierInfoPatient();
	void supprimerComplicationDuPatient();
    void afficherTousLesPatients();
    friend ostream& operator<<(ostream&, Chirurgien&);
    friend istream operator>>(istream&, Chirurgien&);
    friend istream& operator==(istream&, Chirurgien&);
    Chirurgien& operator=(const Chirurgien&);
    static void creer(fstream&);
    void supprimerPatient(fstream&);

    static void afficherAPartirDuFicher(fstream&);
    ~Chirurgien(); 

};

