//
// Created by sebat on 4/04/2023.
//

#ifndef ZOOLOGICO_ANIMALES_H
#define ZOOLOGICO_ANIMALES_H
#include <iostream>
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

class animales {
public:
    //string accionAnimal;
    string nombreZoologico;
    int idAnimal;
    string nombre;
    string especie;
    int edad;
    string tipoAlimentacion;
    string estadoSalud;
    string tipoHabitat;
    vector<animales*> vectorAnimales;
    vector<animales*> vectorComida;
public:
    animales() = default;
    animales(string nombreZoologico);
    animales(int idAnimal, string nombre,string especie, string tipoHabitat,
             int edad, string tipoAalimentacion, string estadoSalud);
    void agregarComida(string nombre, string tipoAlimentacion, string comida);
    void mostrarInfo();
    void agregarZoologico(string nombre, string especie, string tipoHabitat,
                          int edad, string tipoAlimentacion, string estadoSalud);
    void agregarZoologico(string tipoHabitat);
    //void agregarComidaCarnivoro(int idAnimal, string tipoAlimentacion, string tipoDieta);


    int getIdAnimal();
    string getEspecie();
    int getEdad();
    string getTipoAlimentacion();
    string getNombre();
    string getEstadoSalud();
    string getHabitat();
};


#endif //ZOOLOGICO_ANIMALES_H
