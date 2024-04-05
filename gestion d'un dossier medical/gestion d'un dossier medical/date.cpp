#include "date.h"
#include<iostream>
using namespace std;
date::date()
{
}
date::date(int j, int m, int a) : jour(j), mois(m), annee(a)
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
ostream& operator<<(ostream& out, date& date)
{
    out << date.jour << "/" <<date.mois << "/ " << date.annee;
    return out;

}
istream& operator>>(istream& in , date& date)
{
    cout << "Enter le jour ";
    in >> date.jour;
    cout << "Enter le mois";
    in >> date.mois;
    cout << "Enter l annee ";
    in >> date.annee;
    return in;
}
bool date::operator==(date& d) 
{
    return (annee == d.annee && mois == d.mois && jour == d.jour);
}

date::~date()
{}
