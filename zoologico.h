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
<<<<<<< HEAD
=======
    string arregloCarnivoro[6] = {"carne", "pescado", "pechuga", "gusanos", "ave", "huevos"};
    string arregloHerbivoro[6] = {"hierbas", "hojas", "savia", "raices", "semillas", "flores"};
    string arregloOmnivoros[6] = {"frutas", "carne", "vegetales", "plantas", "pescado", "verduras"};
>>>>>>> af80c4b4186192fbcd2e9f1edb26383c49918029
    vector<habitat *> vectorHabitat;

public:
    zoologico() = default;

    zoologico(string nombreZoologico);

    void agregarHabitat(string tipoHabitat);

    void mostrarHabitats();
    void ingresarAnimal(int id, string nombre, string especie, string tipoHabitat, int edad, string tipoAlimentacion,
                                 string estadoSalud, int horasDormir, int estadoActivo, int estadoJugar);
    void buscarAnimal(int idAnimal, string habitat, int opcion);
    void mostrarAnimalesZoo();

    vector<habitat*> getVectorHabitat();


};


#endif //ZOOLOGICO_ZOOLOGICO_H
