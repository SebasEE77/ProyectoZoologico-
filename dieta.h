//
// Created by sebat on 4/04/2023.
//

#ifndef ZOOLOGICO_DIETA_H
#define ZOOLOGICO_DIETA_H
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


class dieta: public animales {
public:
    dieta() = default;
    dieta(string tipoDieta);
    void agregarComidaVectores(string tipoDieta);

};


#endif //ZOOLOGICO_DIETA_H
