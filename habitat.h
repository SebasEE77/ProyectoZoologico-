//
// Created by sebat on 4/04/2023.
//

#ifndef ZOOLOGICO_HABITAT_H
#define ZOOLOGICO_HABITAT_H
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

class habitat{
protected:
    string tipoHabitat;
    vector<animales*> vectorAnimales;
public:
    habitat() = default;
    habitat(string tipoHabitat);
    void agregarZoologico(string nombre, string especie, string tipoHabitat,
                          int edad, string tipoAlimentacion, string estadoSalud);


    string getHabitat();
};


#endif //ZOOLOGICO_HABITAT_H
