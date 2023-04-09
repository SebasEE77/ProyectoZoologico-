//
// Created by sebat on 4/04/2023.
//

#ifndef ZOOLOGICO_ANIMALES_H
#define ZOOLOGICO_ANIMALES_H
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>

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
    string arregloCarnivoro[6] = {"carne", "pescado", "pechuga", "gusanos", "ave", "huevos"};
    string arregloHerbivoro[6] = {"hierbas", "hojas", "savia", "raices", "semillas", "flores"};
    string arregloOmnivoros[6] = {"frutas", "carne", "vegetales", "plantas", "pescado", "verduras"};
    int idAnimal;
    int edad;
    int horasDormir;
    int estadoActivo;
    int estadoJugar;
    string accionAnimal;
    string nombreAnimal;
    string nombre;
    string especie;
    string tipoAlimentacion;
    string estadoSalud;
    string tipoHabitat;
    vector<string> vectorDieta;
    string tipoDieta;
    vector <animales*> vectorAcciones;
    vector <string> vectorComida;

public:
    animales() = default;
    animales(int idAnimal, string nombre,string especie, string tipoHabitat,
             int edad, string tipoAalimentacion, string estadoSalud, int horasDormir, int estadoActivo, int estadoJugar);
    void agregarComida(string comida);
    void modificarDieta(string accion, string comida);
    void mostrarDietasDisponoble(string dieta);
    void mostrarDietaAnimal();
    void jugar();
    void comer();
    void dormir();


    int getIdAnimal();
    string getEspecie();
    int getEdad();
    string getTipoAlimentacion();
    string getNombre();
    string getEstadoSalud();
    string getHabitat();
    int getHoras();
    int getEstadoActivo();
    int getEstadoJugar();
    int verificarComida(string comida);
    void setEstadoActivo(int estadoActivo);
    void setEstadoJugar(int estadoJugar);



};


#endif //ZOOLOGICO_ANIMALES_H
