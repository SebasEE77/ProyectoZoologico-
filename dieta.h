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
protected:
    //string tipoDieta;
    string tipoDietaCarnivoro;
    string tipoDietaHerbivoro;
    string tipoDietaOmnivoro;
    vector<dieta*> vectorCarnivoro;
    vector<dieta*> vectorOmnivoro;
    vector<dieta*> vectorHerbivoro;
public:
    dieta() = default;
    dieta(string tipoDietaCarnivoro, string tipoDietaHerbivoro, string tipoDietaOmnivoro);
    //dieta(string tipoDieta, string tipoDietaCarnivoro, string tipoDietaHerbivoro, string tipoDietaOmnivoro);
    void agregarComida(int idAnimal, string tipoAlimentacion,string tipoDieta);
    void agregarComida2(int idAnimal, string tipoAlimentacion);

    void mostrarInfo();
    void mostrarInfo2();


    string getTipoDietaCarnivoro();
    string getTipoDietaHerbivoro();
    string getTipoDietaOmnivoro();
    void setTipoDietaCarnivoro(string tipoDieta);

};


#endif //ZOOLOGICO_DIETA_H
