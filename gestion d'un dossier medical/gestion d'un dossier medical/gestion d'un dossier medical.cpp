

#include <iostream>
#include"Patient.h"
int main()
{
    //test du classe patient
    Patient p;
    p.saisir();
    p.afficher();
    p.supprimerComplication(2);
    p.afficher();

}


