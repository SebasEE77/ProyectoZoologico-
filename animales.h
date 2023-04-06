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
protected:
    //string accionAnimal;
    int idAnimal;
    string nombreAnimal;
    string nombre;
    string especie;
    int edad;
    string tipoAlimentacion;
    string estadoSalud;
    string tipoHabitat;
    string tipoDieta;
    vector<animales*> vectorComida;
    unordered_map<int, animales*> mapaComida;
public:
    animales() = default;
    animales(string nombreAnimal);
    animales(int idAnimal,string tipoDieta);
    animales(int idAnimal, string nombre,string especie, string tipoHabitat,
             int edad, string tipoAalimentacion, string estadoSalud);
    void agregarComida(int idAnimal,string tipoDieta);
    void mostrarInfoDieta();
    //void agregarComidaCarnivoro(int idAnimal, string tipoAlimentacion, string tipoDieta);


    int getIdAnimal();
    string getEspecie();
    int getEdad();
    string getTipoAlimentacion();
    string getNombre();
    string getEstadoSalud();
    string getHabitat();
    string getTipoDieta();
};


#endif //ZOOLOGICO_ANIMALES_H
