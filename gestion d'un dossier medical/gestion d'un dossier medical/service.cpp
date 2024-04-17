#include "service.h"
#include"Patient.h"
#include"Chirurgien.h"
#include"Secretaire.h"
#include"dossierMedical.h"
#include"postChirurgicale.h"
#include"dossierChirurgical.h"
#include<iostream>
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

istream& operator>>(istream& in, service& s)
{
    int choix;
    char rep;
    do
    {
        cout << "\n Taper 1:Dossier medical, 2:Personne" << endl;
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
