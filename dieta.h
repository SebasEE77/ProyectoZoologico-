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
    string tipoDieta;
//    vector<dieta*> vectorCarnivoro;
//    vector<dieta*> vectorOmnivoro;
//    vector<dieta*> vectorHerbivoro;
  //  vector<dieta*> vectorComida;

public:
    dieta() = default;
    dieta(string tipoDieta);
    //dieta(string tipoDieta, string tipoDietaCarnivoro, string tipoDietaHerbivoro, string tipoDietaOmnivoro);
    void agregarComida(int idAnimal, string tipoAlimentacion,string tipoDieta);

    void mostrarInfo();


    string getTipoDietaCarnivoro();
    string getTipoDietaHerbivoro();
    string getTipoDietaOmnivoro();
    string getTipoDieta();
    void setTipoDietaCarnivoro(string tipoDieta);

};


#endif //ZOOLOGICO_DIETA_H
