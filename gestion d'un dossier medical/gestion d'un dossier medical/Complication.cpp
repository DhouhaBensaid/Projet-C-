#include "Complication.h"
#include<iostream>
Complication::Complication(int id, string type, string gravite) :id(id), type(type), gravite(gravite){}
void Complication::saisir()
{
	cout << "Donner id du complication : " << endl;
	cin >> id;
	cout << "Donner le type de complication" << endl;
	cin >> type;
	cout << "Donner la gravite de complication" << endl;
	cin >> gravite;
}
void Complication::afficher()
{
	cout << "Id de la complication : " << id << endl;
	cout << "Le type de complication<< : " << type << endl;
	cout << "La gravite de la complication : " << gravite << endl;

}
#include "Complication.h"

Complication::~Complication() 
{
	
}

