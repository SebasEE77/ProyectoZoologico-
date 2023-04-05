//
// Created by sebat on 4/04/2023.
//

#ifndef ZOOLOGICO_ACCIONANIMAL_H
#define ZOOLOGICO_ACCIONANIMAL_H
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "animales.h"

using std::cout;
using std::string;
using std::endl;
using std::iterator;
using std::cin;
using std::unordered_map;
using std::make_pair;
using std::vector;


class AccionAnimal: public animales{
protected:
    string comer;
    string dormir;
    string jugar;
    int numHorasDormir;
    int accionAnimal;
public:
    AccionAnimal() = default;
    AccionAnimal(string comer, string dormir, string jugar, int numHorasDormir,int accionAnimal);
    };


#endif //ZOOLOGICO_ACCIONANIMAL_H
