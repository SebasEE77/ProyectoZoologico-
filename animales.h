//
// Created by sebat on 4/04/2023.
//

#ifndef ZOOLOGICO_ANIMALES_H
#define ZOOLOGICO_ANIMALES_H
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "zoologico.h"

using std::cout;
using std::string;
using std::endl;
using std::iterator;
using std::cin;
using std::unordered_map;
using std::make_pair;
using std::vector;

class animales: public zoologico {
protected:
    string tipoDieta;
    vector<animales*> vectorCarnivoro;
    vector<animales*> vectorOmnivoro;
    vector<animales*> vectorHerbivoro;
public:
    animales() = default;
    animales(int id, string nombre,string especie, string tipoHabitat,
             int edad, string tipoAalimentacion, string estadoSalud);
    void accionDelAnimal(int idAnimal, int accionAnimal,string tipoDieta);
    void agregarComidaVectores(string tipoDieta);

    string getTipoDieta();
};


#endif //ZOOLOGICO_ANIMALES_H
