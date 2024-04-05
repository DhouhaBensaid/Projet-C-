#pragma once
#ifndef DATE_H
#define DATE_H
#include<istream>
#include<ostream>
using namespace std;
class date
{
protected:
    int jour;
    int mois;
    int annee;
public:

    date();
    date(int j, int m, int a);
    void saisirDate();
    void afficherDate();
    friend ostream& operator<<(ostream&,date&);
    friend istream& operator>>(istream&,date&);
    int getJour() { return jour; }
    int getMois() { return mois; }
    int getAnnee() { return annee; }
    void setJour(int j) { jour = j; }
    void setMois(int m) { mois = m; }
    void setAnnee(int a) { annee = a; }
    bool  operator==(date&);
    ~date();


};

#endif // DATE_H

