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
ostream& operator<<(ostream&out, service & s)
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
                    int DateRdv;
                    cout << "Entrez la date du rendez-vous à supprimer : " << endl;
                    cin >> DateRdv;
                    nvSecretaire->supprimerRdv(DateRdv);
                    break;
                }
                case '4': {
                    int pos;
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
            nvChirurgien->saisir();
            personne.push_back(nvChirurgien);
            char choixC;
            do {
                cout << "___Menu Chirurgien :____" << endl;
                cout << "1. Saisir les informations d un patient" << endl;
                cout << "2. Consulter un dossier chirurgical " << endl;
                cout << "3. Ajouter une note dans un dossier chirurgical " << endl;
                cout << "4. Ajouter une complication a un patient" << endl;
                cout << "5. Modifier les informations d un patient" << endl;
                cout << "6. Supprimer une complication d un patient" << endl;
                cout << "7. Afficher tous les patients" << endl;
                cout << "8. Creer un fichier de chirurgien" << endl;
                cout << "9. Supprimer un patient" << endl;
                cout << "q. Quitter" << endl;

                cout << "Votre choix : ";
                cin >> choixC;

                switch (choixC) {
                case '1': {

                    fstream f("C:\\Users\\hp\\Desktop\\patients.txt", ios::in);
                    if (f.is_open()) {
                        nvChirurgien->saisirPatients(f);
                        (f);
                        f.close();
                    }
                    break;
                    break;
                }
                case '2': {
                    Secretaire s;
                    nvChirurgien->consulterDossier(s);
                    break;
                }
                case '3': {
                    Secretaire s;
                    nvChirurgien->AjouterNote(s);
                    break;
                }
                case '4': {
                    nvChirurgien->ajouterComplication();
                    break;
                }
                case '5': {
                    nvChirurgien->modifierInfoPatient();
                    break;
                }
                case '6': {
                    nvChirurgien->supprimerComplicationDuPatient();
                    break;
                }
                case '7': {
                    nvChirurgien->afficherTousLesPatients();
                    break;
                }
                case '8': {
                    fstream fichier("nom_du_fichier.txt", ios::in | ios::out); // Ouverture du fichier en mode lecture/écriture
                    if (fichier.is_open()) {
                        Chirurgien::creer(fichier); // Appel de la fonction avec le fichier ouvert
                        fichier.close(); // Fermeture du fichier après utilisation
                    }
                    else {
                        cout << "Erreur : Impossible d'ouvrir le fichier." << endl;
                    }
                    break;
                }

                case '9': {
                    fstream f("C:\\Users\\hp\\Desktop\\patients.txt", ios::in ); 
                    if (f.is_open()) {
                        nvChirurgien->supprimerPatient(f);
                        f.close(); 
                    }
                    break;
                }

                case '10': {
                    fstream f("C:\\Users\\hp\\Desktop\\patients.txt", ios::in | ios::out); 
                    if (f.is_open()) {
                        nvChirurgien->afficherAPartirDuFicher(f);
                        f.close(); 
                    }
                    break;
                }

                case 'q':
                    cout << "Sortie du menu Chirurgien" << endl;
                    break;
                default:
                    cout << "Choix invalide,Veuillez choisir une option valide" << endl;
                }
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
            for (int i = 0; i < s.dossierMed.size(); i++) {
                dossierChirurgical<int>* dossier = dynamic_cast<dossierChirurgical<int>*>(s.dossierMed[i]);
                if (dossier) {
                    dossier->afficher();
                }
            }
            break;
        }
        case '5': {
            cout << "Liste des dossiers post chirurgicaux :" << endl;
            for (int i = 0; i < s.dossierMed.size(); i++){
                postChirurgicale* dossierPostChirurgical = dynamic_cast<postChirurgicale*>(s.dossierMed[i]);
                if (dossierPostChirurgical) {
                    dossierPostChirurgical->afficher();
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

istream& operator>>(istream& in, service& s)
{
    int choix;
    char rep;
    do
    {
        cout << "\n Taper 1:Dossier medical, 2:Personne" << endl;// dossier chirurgical ou post...
        in >> choix;
        if (choix == 1) {
            dossierMedical* d = new postChirurgicale(); 
            in >> *d;
            s.dossierMed.push_back(d);
        }
        else {
            int choixPers;
            cout << "\n Taper 1:Patient, 2:Chirurgien, 3:Secretaire" << endl;
            in >> choixPers;
            if (choixPers == 1)
            {
                Personne* p = new Patient();
                in >> *p;

                s.personne.push_back(p);
            }
            else if (choixPers == 2)
            {
                Personne* p = new Chirurgien();
                in >> *p;
                s.personne.push_back(p);
            }
            else if (choixPers == 3) {
                Personne* p = new Secretaire();
                in >> *p;
                s.personne.push_back(p);
            }
            else 
                cout << "Choix invalide" << endl;
            
        }

        cout << "Voulez-vous ajouter un autre element o/n ";
        in >> rep;

    } while (rep == 'o');
    return in;
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
