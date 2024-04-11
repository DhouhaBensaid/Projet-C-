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
ostream& operator<<(ostream& out, Complication& c) {
	
		out << "Id Complication : " << c.id << ",Type Complication : " << c.type << ",Gravite : " << c.gravite;
		return out;
}

ostream& operator<<(ostream& out, Complication* c) {

	out << ",Id Complication : " << c->id << ",Type Complication : " << c->type << ",Gravite : " << c->gravite;
	return out;
}

istream& operator>>(istream& in, Complication& c) {

	cout << "Donner id du complication : " << endl;
	in >> c.id;
	cout << "Donner le type de complication" << endl;
	in >> c.type;
	cout << "Donner la gravite de complication" << endl;
	in >> c.gravite;
	return in;
}

istream& operator>>(istream& in, Complication* c) {

	cout << "Donner id du complication : " << endl;
	in >> c->id;
	cout << "Donner le type de complication" << endl;
	in >> c->type;
	cout << "Donner la gravite de complication" << endl;
	in >> c->gravite;
	return in;
}
Complication::~Complication() 
{
	
}

