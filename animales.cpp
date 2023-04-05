//
// Created by sebat on 4/04/2023.
//

#include "animales.h"

// Constructor de la clase animal. Aunque esta clase no tenga los atributos, se pone aquí el constructor por coherencia
animales::animales(int idAnimal, string nombre, string especie, string tipoHabitat, int edad, string tipoAalimentacion,
                   string estadoSalud) {
    this->idAnimal = idAnimal;
    this->nombre = nombre;
    this->especie = especie;
    this->tipoHabitat = tipoHabitat;
    this->edad = edad;
    this->tipoAlimentacion = tipoAalimentacion;
    this->estadoSalud = estadoSalud;

}

// Este metodo agrega los animales al vector teniendo en cuenta las caracteristicas pedidas en el main. Aqui hay una bandera ya que
// ayuda a para el ciclo del for cuando se debe y no lo recorra inecesariamente.
void zoologico::agregarZoologico(string nombre, string especie, string tipoHabitat,
                                 int edad, string tipoAlimentacion, string estadoSalud){
    int bandera = 0;
    vector<zoologico*>::iterator itVectorHabitat;
    for (itVectorHabitat = this->vectorHabitat.begin(); itVectorHabitat != this->vectorHabitat.end() and bandera == 0; ++itVectorHabitat) {
        zoologico *pHabitat = *itVectorHabitat;
        if(pHabitat->getHabitat() == tipoHabitat) {
            vectorAnimales.push_back(new animales(this->idAnimal, nombre, especie, tipoHabitat,
                                                  edad, tipoAlimentacion, estadoSalud));
            bandera = 1;
        }
    }
    if(bandera == 0){
        cout << "No se encontro un habitat para este animal"<<endl;
    }else{
        cout << "El animal se agrego satisfactoriamente"<<endl;
        this->idAnimal++;
    }
}

// Desde aqui van los Gets
string animales::getTipoDieta(){
    return tipoDieta;
}
