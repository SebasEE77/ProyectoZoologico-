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

class zoologico {

protected:
    string nombreZoologico;
    string arregloCarnivoro[6] = {"Carne", "Pescado", "pechuga", "Gusanos", "Ave", "Huevos"};
    string arregloHerbivoro[6] = {"Hierbas", "Hojas", "Savia", "Raices", "Semillas", "Flores"};
    string arregloOmnivoros[6] = {"Frutas", "Carne", "Vegetales", "Plantas", "Pescado", "Verduras"};
    vector<habitat *> vectorHabitat;
    vector<animales *> vectorComida;
    string tipoDieta;

public:
    zoologico() = default;


    zoologico(string nombreZoologico);

    void agregarZoologico(string tipoHabitat);

    void mostrarInfo();

    void agregarComida(int idAnimal, string tipoDieta,string tipoAlimentacion);

    void mostrarArreglo(int idAnimal, string tipoDieta,string tipoAlimentacion);

    void mostrarInfo(int idAnimal);

    void cambiarComida(int idAnimal, string modificar, string tipoDieta);

    void eliminarComida(int idAnimal, string modificar);


    vector<habitat*> getVectorHabitat();
    vector<animales*> getVectorComida();


};


#endif //ZOOLOGICO_ZOOLOGICO_H
