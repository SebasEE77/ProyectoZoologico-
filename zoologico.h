//
// Created by sebat on 4/04/2023.
//

#ifndef ZOOLOGICO_ZOOLOGICO_H
#define ZOOLOGICO_ZOOLOGICO_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "habitat.h"

using std::cout;
using std::string;
using std::endl;
using std::iterator;
using std::cin;
using std::unordered_map;
using std::make_pair;
using std::vector;
using std::array;

class zoologico {

protected:
    string nombreZoologico;
    string lugarZoologico;
    string arregloCarnivoro[6] = {"carne", "pescado", "pechuga", "gusanos", "ave", "huevos"};
    string arregloHerbivoro[6] = {"hierbas", "hojas", "savia", "raices", "semillas", "flores"};
    string arregloOmnivoros[6] = {"frutas", "carne", "vegetales", "plantas", "pescado", "verduras"};
    vector<habitat *> vectorHabitat;
    vector<animales *> vectorComida;
    string tipoDieta;

public:
    zoologico() = default;

    zoologico(string nombreZoologico);

    void agregarZoologico(string tipoHabitat);

    void mostrarInfo();

    void agregarComida(int idAnimal, string tipoDieta,string tipoAlimentacion);

    string recorrerVectorHabitat(string tipoHabitat);

    void mostrarArreglo(string tipoAlimentacion);

    void mostrarInfo(int idAnimal);

    void cambiarComida(int idAnimal, string modificar, string tipoDieta);

    void eliminarComida(int idAnimal, string modificar);

    vector<habitat*> getVectorHabitat();
    vector<animales*> getVectorComida();
    string getArregloCarnivoro();


};


#endif //ZOOLOGICO_ZOOLOGICO_H
