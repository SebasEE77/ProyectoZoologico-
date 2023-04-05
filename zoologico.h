//
// Created by sebat on 4/04/2023.
//

#ifndef ZOOLOGICO_ZOOLOGICO_H
#define ZOOLOGICO_ZOOLOGICO_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

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
    string nombre;
    string especie;
    int edad;
    string tipoAlimentacion;
    string estadoSalud;
    int idAnimal;
    string tipoHabitat;
    vector<zoologico*> vectorHabitat;
    vector<zoologico*> vectorAnimales;

public:
    zoologico() = default;
    zoologico(string nombreZoologico);
    void agregarZoologico(string tipoHabitat);
    void mostrarInfo();
    void agregarZoologico(string nombre, string especie, string tipoHabitat,
                          int edad, string tipoAlimentacion, string estadoSalud);

    int getIdAnimal();
    string getHabitat();
    string getEspecie();
    int getEdad();
    string getTipoAlimentacion();
    string getNombre();
    string getEstadoSalud();


};


#endif //ZOOLOGICO_ZOOLOGICO_H
