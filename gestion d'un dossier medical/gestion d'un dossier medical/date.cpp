#include "date.h"
#include<iostream>
using namespace std;
date::date()
{

}
void date::saisirDate()
{
    cout << "donner le jour" << endl;
    cin >> jour;
    cout << "donner le mois" << endl;
    cin >> mois;
    cout << "donner l'annee" << endl;
    cin >> annee;
}
void date::afficherDate()
{
    cout << "\n la date est:" << jour << "/" << mois << "/" << annee << endl;
}
date::~date()
{

}
