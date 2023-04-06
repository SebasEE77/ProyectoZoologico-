//
// Created by sebat on 4/04/2023.
//
#include "zoologico.h"
#include "habitat.h"

 //Constructor de la clase habitat
habitat::habitat(string tipoHabitat){
    this->tipoHabitat = tipoHabitat;
}

// Este metodo agrega los habitats en el vector de habitats ya que mas adelante nos ayudara para saber si un animal
// pertenece al habitat o no.
void zoologico::agregarZoologico(string tipoHabitat) {
    vectorHabitat.push_back(new habitat(tipoHabitat));
    cout << "Se agrego un habitat"<<endl;
}

string habitat::getHabitat(){
    return tipoHabitat;
}

void zoologico::agregarZoologico(string nombre, string especie, string tipoHabitat,
                                 int edad, string tipoAlimentacion, string estadoSalud){
    int bandera = 0;
    vector<habitat*>::iterator itVectorHabitat;
    for (itVectorHabitat = this->vectorHabitat.begin(); itVectorHabitat != this->vectorHabitat.end() and bandera == 0; ++itVectorHabitat) {
        animales *pHabitat = *itVectorHabitat;
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