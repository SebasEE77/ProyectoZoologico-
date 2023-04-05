//
// Created by sebat on 4/04/2023.
//

#include "zoologico.h"
#include "habitat.h"
#include "animales.h"

// Constructor del Zoologico
zoologico::zoologico(string nombreZoologico){
    this->idAnimal = 1;
    this->nombreZoologico = nombreZoologico;
}

// Se muestra las habitats y los animales agregados al zoologico
void zoologico::mostrarInfo() {
    vector<zoologico*>::iterator itVectorHabitat;
    vector<zoologico*>::iterator itVectorAnimales;
    cout << "\nLista de habitats:\n";
    for (itVectorHabitat = this->vectorHabitat.begin(); itVectorHabitat != this->vectorHabitat.end(); ++itVectorHabitat) {
        zoologico *pHabitat = *itVectorHabitat;
        cout << "Habitat: "<<pHabitat->getHabitat()<<endl;

    }
    cout << "\nLista de animales:\n";
    for (itVectorAnimales = this->vectorAnimales.begin(); itVectorAnimales != this->vectorAnimales.end(); ++itVectorAnimales) {
        zoologico *pAnimales = *itVectorAnimales;
        cout << "Id: "<<pAnimales->getIdAnimal()<<endl;
        cout << "Nombre: "<<pAnimales->getNombre()<<endl;
        cout << "Especie: "<<pAnimales->getEspecie()<<endl;
        cout << "Habitat: "<<pAnimales->getHabitat()<<endl;
        cout << "Edad: "<<pAnimales->getEdad()<<endl;
        cout << "Tipo de Alimentacion: "<<pAnimales->getTipoAlimentacion()<<endl;
        cout << "Estado de salud: "<<pAnimales->getEstadoSalud()<<endl;
        cout <<endl;
    }
}




//De aqui para abajo estan los Gets.
int zoologico::getIdAnimal() {
    return idAnimal;
}
string zoologico::getHabitat() {
    return tipoHabitat;
}
string zoologico::getEspecie() {
    return especie;
}
int zoologico::getEdad() {
    return edad;
}
string zoologico::getTipoAlimentacion() {
    return tipoAlimentacion;
}
string zoologico::getEstadoSalud() {
    return estadoSalud;
}
string zoologico::getNombre(){
    return nombre;
}