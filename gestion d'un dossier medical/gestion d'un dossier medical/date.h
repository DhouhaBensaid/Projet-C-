#pragma once
#ifndef DATE_H
#define DATE_H


class date
{
    int jour;
    int mois;
    int annee;
public:
    date();
    void saisirDate();
    void afficherDate();
    ~date();


};

#endif // DATE_H

