#include "Date.h"
#include<iostream>
using namespace std;
Date::Date()
{

}
void Date::saisirDate()
{
    cout<<"donner le jour"<<endl;
    cin>>jour;
    cout<<"donner le mois"<<endl;
    cin>>mois;
    cout<<"donner l'annee"<<endl;
    cin>>annee;
}
void Date::afficherDate()
{
    cout<<"\n la date est:"<<jour<<"/"<<mois<<"/"<<annee<<endl;
}
Date::~Date()
{

}
