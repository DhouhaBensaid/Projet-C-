#include "service.h"
#include"Patient.h"
#include"Chirurgien.h"
#include"Secretaire.h"
#include"dossierMedical.h"
#include"postChirurgicale.h"
#include"dossierChirurgical.h"
#include<iostream>
#include<fstream>
using namespace std;
service::service()
{}
service::service(const service& s)
{
    for (int i = 0; i < s.dossierMed.size(); i++) {
        
        if (typeid(*s.dossierMed[i]) == typeid(postChirurgicale)) {
            postChirurgicale* d = new postChirurgicale(*dynamic_cast<postChirurgicale*>(s.dossierMed[i]));
            dossierMed.push_back(d);
        }
        else if (typeid(*s.dossierMed[i]) == typeid(dossierChirurgical<int>)) {
            dossierChirurgical<int>* dC = new dossierChirurgical<int>(*dynamic_cast<dossierChirurgical<int>*>(s.dossierMed[i]));
            dossierMed.push_back(dC);
        }
    }

    
    for (int i = 0; i < s.personne.size(); i++) {
        if (typeid(*s.personne[i]) == typeid(Patient)) {
            Patient* p = new Patient(*dynamic_cast<Patient*>(s.personne[i]));
            personne.push_back(p);
        }
        else if (typeid(*s.personne[i]) == typeid(Chirurgien)) {
            Chirurgien* c = new Chirurgien(*dynamic_cast<Chirurgien*>(s.personne[i]));
            personne.push_back(c);
        }
        else if (typeid(*s.personne[i]) == typeid(Secretaire)) {
            Secretaire* sec = new Secretaire(*dynamic_cast<Secretaire*>(s.personne[i]));
            personne.push_back(sec);
        }
    }
}
ostream& operator<<(ostream& out, service& s)
{
    for (int i = 0; i < s.dossierMed.size(); i++)
    {
        if (typeid(*s.dossierMed[i]) == typeid(postChirurgicale))
            out << *dynamic_cast<postChirurgicale*>(s.dossierMed[i]);

        else if(typeid(*s.dossierMed[i]) == typeid(dossierChirurgical<int>))
            out << *dynamic_cast<dossierChirurgical<int>*>(s.dossierMed[i]);
       
    }

    for (int i = 0; i < s.personne.size(); i++)
    {
       
        if (typeid(*s.personne[i]) == typeid(Patient) || typeid(*s.personne[i]) == typeid(Chirurgien) || typeid(*s.personne[i]) == typeid(Secretaire))
            out << *s.personne[i];
    }

    return out;
}
void service::saisir()
{
    char choix;
    do {
        cout << "Menu :" << endl;
        cout << "1. Saisir un patient" << endl;
        cout << "2. Saisir une secrétaire" << endl;
        cout << "3. Saisir un chirurgien" << endl;
        cout << "4. Saisir un dossier chirurgical" << endl;
        cout << "5. Saisir un dossier post chirurgical" << endl;
        cout << "q. Quitter" << endl;

        cout << "Votre choix : " << endl;
        cin >> choix;

        switch (choix) {
        case '1': {
            Patient* nvPatient = new Patient();
            nvPatient->saisir();
            personne.push_back(nvPatient);
            char choixP;
            do {
                cout << "****Menu Patient:*****" << endl;
                cout << "1. Supprimer une complication" << endl;
                cout << "q. Quitter le menu de gestion des complications" << endl;

                cout << "Votre choix : " << endl;
                cin >> choixP;

                switch (choixP) {
                case '1': {
                    int idComplication;
                    cout << "Numero de la complication a supprimer : "<<endl;
                    cin >> idComplication;
                    nvPatient->supprimerComplication(idComplication);
                    break;
                }
                case 'q':
                    cout << "Sortie du menu de gestion des complications" << endl;
                    break;
                default:
                    cout << "Choix invalide,Veuillez choisir une option valide" << endl;
                }
            } while (choixP != 'q');
            break;
            break;
        }
        case '2': {
            Secretaire* nvSecretaire = new Secretaire();
            nvSecretaire->saisir();
            personne.push_back(nvSecretaire);
            char choixS;
            do {

                cout << "----Menu de la secretaire :----" << endl;
                cout << "1. Creer un dossier chirurgical" << endl;
                cout << "2. Planifier un rendez-vous" << endl;
                cout << "3. Supprimer un rendez-vous" << endl;
                cout << "4. Consulter un dossier chirurgical" << endl;
                cout << "5. Consulter tous les dossiers chirurgicaux" << endl;
                cout << "6. Afficher tous les rendez-vous" << endl;
                cout << "q. Quitter" << endl;

                cout << "Votre choix : " << endl;
                cin >> choixS;

                switch (choixS) {
                case '1': {
                    nvSecretaire->creerDossierChirurgical();
                    break;
                }
                case '2': {
                    nvSecretaire->planifierRdv();
                    break;
                }
                case '3': {
                    int pos;
                    cout << "Entrez la position du rendez-vous à supprimer : " << endl;
                    cin >> pos;
                    nvSecretaire->supprimerRdv(pos);
                    break;
                }
                case '4': {
                    int pos;
                    cout << "Donner la position du dossier à consulter : ";
                    cin >> pos;
                    nvSecretaire->consulterDossier(pos);
                    break;
                }
                case '5': {
                    nvSecretaire->consulterToutLesDossier();
                    break;
                }
                case '6': {
                    nvSecretaire->afficherTousLesRendezVous();
                    break;
                }
                case 'q':
                    cout << "Sortie du menu de la secrétaire" << endl;
                    break;
                default:
                    cout << "Choix invalide, Veuillez choisir une option valide" << endl;
                }
            } while (choixS != 'q');

            break;

            break;
        }
        case '3': {

            Chirurgien* nvChirurgien = new Chirurgien();
            fstream f;
            nvChirurgien->creer(f);
            nvChirurgien->saisir();
            char choixC;
            do {
                cout << "____Menu Chirurgien :____" << endl;
                cout << "1. Saisir les informations d un patient et les mettre dans un fichier txt" << endl;
                cout << "2. Ajouter une complication a un patient" << endl;
                cout << "3. Modifier les informations d un patient" << endl;
                cout << "4. Supprimer une complication d un patient" << endl;
                cout << "5. Afficher tous les patients" << endl;
                cout << "6. Supprimer un patient" << endl;
                cout << "7. Afficher les patients à partir du fichier" << endl;
                cout << "q. Quitter" << endl;
                cout << "Votre choix : ";
                cin >> choixC;

                switch (choixC) {
                case '1': {

                   
                    nvChirurgien->saisirPatients(f);
                    break;
                }
                  
                case '2': {
                    nvChirurgien->ajouterComplication();
                    break;
                }
                case '3': {
                    nvChirurgien->modifierInfoPatient(f);
                    break;
                }
                case '4': {
                    nvChirurgien->supprimerComplicationDuPatient();
                    break;
                }
                case '5': {
                    nvChirurgien->afficherTousLesPatients();
                    break;
                }

                case '6': {
                    nvChirurgien->supprimerPatient(f);
                    break;
                }

                case '7': {
                        nvChirurgien->afficherAPartirDuFicher(f);
                    break;
                }
                case 'q':
                    cout << "Sortie du menu Chirurgien" << endl;
                    break;
                default:
                    cout << "Choix invalide,Veuillez choisir une option valide" << endl;
                }
                personne.push_back(nvChirurgien);

            } while (choixC != 'q');
            break;
        }
        case '4': {

            dossierChirurgical<int>* nvDossierChirurgical = new dossierChirurgical<int>();
            nvDossierChirurgical->saisir();
            dossierMed.push_back(nvDossierChirurgical);

            break;
        }

        case '5': {

            postChirurgicale* nvDossierPostChirurgical = new postChirurgicale();
            nvDossierPostChirurgical->saisir();
            dossierMed.push_back(nvDossierPostChirurgical);
            char ChoixPost;
            do {

                cout << "****Menu pour les dossiers post chirurgicaux**** :" << endl;
                cout << "1. Modifier la date d un dossier post chirurgical" << endl;
                cout << "2. Ajouter une complication à aun dossier post chirurgical" << endl;
                cout << "q. Retour au menu principal" << endl;

                cout << "Votre choix : " << endl;
                cin >> ChoixPost;

                switch (ChoixPost) {

                case '1': {
                    date d;
                    cout << "Donner la nouvelle date: " << endl;
                    cin >> d;
                    nvDossierPostChirurgical->modifierDate(d);
                    break;
                }
                case '2': {
                    nvDossierPostChirurgical->ajouterComplication();

                    break;
                }
                case 'q':
                    cout << "Retour au menu principal " << endl;
                    break;
                default:
                    cout << "Choix invalide,Veuillez choisir une option valide " << endl;
                }
            } while (ChoixPost != 'q');
            break;
        }
        case 'q':
            cout << "Sortie du menu de saisie." << endl;
            break;
        default:
            cout << "Choix invalide. Veuillez choisir une option valide." << endl;
        }
    }while (choix != 'q');
}
void service::afficher(service s) {
    char choix;
    do {
     
        cout << "Menu :" << endl;
        cout << "1. Afficher les patients" << endl;
        cout << "2. Afficher les secrétaires" << endl;
        cout << "3. Afficher les chirurgiens" << endl;
        cout << "4. Afficher les dossiers chirurgicaux" << endl;
        cout << "5. Afficher les dossiers post chirurgicaux" << endl;
        cout << "q. Quitter" << endl;

        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
        case '1': {
           
            cout << "Liste des patients :" << endl;
            for (int i = 0;i<s.personne.size();i++) {
                Patient* patient = dynamic_cast<Patient*>(s.personne[i]);
                if (patient) {
                    patient->afficher();
                }
            }
            break;
        }
        case '2': {
            cout << "Liste des secretaires :" << endl;
            for (int i = 0;i < s.personne.size();i++) {
                Secretaire* secretaire = dynamic_cast<Secretaire*>(s.personne[i]);
                if (secretaire) {
                    secretaire->afficher();
                }
            }
            break;
        }
        case '3': {
            cout << "Liste des chirurgiens :" << endl;
            for (int i = 0;i < s.personne.size();i++) {
                Chirurgien* chirurgien = dynamic_cast<Chirurgien*>(s.personne[i]);
                if (chirurgien) {
                    chirurgien->afficher();
                }
            }
            break;
        }
        case '4': {
            cout << "Liste des dossiers chirurgicaux :" << endl;
            for (int i = 0; i < dossierMed.size(); i++) {
                dossierChirurgical<int>* dossier = dynamic_cast<dossierChirurgical<int>*>(dossierMed[i]);
                if (dossier) {
                    dossierMed[i]->afficher();
                }
            }
            break;
        }
        case '5': {
            cout << "Liste des dossiers post chirurgicaux :" << endl;
            for (int i = 0; i < dossierMed.size(); i++){
                cout << *(dossierMed[i]) << endl;
                postChirurgicale* dossierPostChirurgical = dynamic_cast<postChirurgicale*>(dossierMed[i]);
                if (dossierPostChirurgical) {
                   dossierMed[i]->afficher();
                }
            }
            break;
        }
        case 'q':
            cout << "Sortie du menu d'affichage." << endl;
            break;
        default:
            cout << "Choix invalide. Veuillez choisir une option valide." << endl;
        }
    } while (choix != 'Q' && choix != 'q');
}


service::~service()
{
    for (int i = 0; i < dossierMed.size(); i++)
        delete dossierMed[i];
    dossierMed.clear();
    for (int i = 0; i < personne.size(); i++)
        delete personne[i];
    personne.clear();

}
