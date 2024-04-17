#include "noteOperatoire.h"
#include<iostream>
using namespace std;

noteOperatoire::noteOperatoire(int id, string desc) : idNote(id), description(desc) {}

void noteOperatoire::saisir() {
    cout << "donner l identifiant de la note operatoire : "<<endl;
    cin >> idNote;
    cout << "donner  la description de la note operatoire : "<<endl;
    cin >> description;
  
}


void noteOperatoire::afficher() 
 {
    cout << "Identifiant de la note operatoire : " << idNote << endl;
    cout << "Description de la note operatoire : " << description << endl;
}


ostream& operator<< (ostream& out, noteOperatoire& note) 
{
    out << "Identifiant de la note operatoire : " << note.idNote << endl;
    out << "Description de la note operatoire : " << note.description << endl;
    return out;
}


istream& operator >> (istream& in, noteOperatoire& note) {
    cout << "donner l identifiant de la note operatoire : ";
    in >> note.idNote;
    cout << "donner la description de la note operatoire : ";
    in >> note.description;

    return in;
}


bool noteOperatoire::operator==(noteOperatoire& note) 
{
    return (idNote == note.idNote && description == note.description);
}
noteOperatoire::~noteOperatoire(void) 
{
}


