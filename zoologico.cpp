//
// Created by sebat on 4/04/2023.
//

#include "zoologico.h"
#include "animales.h"

// Constructor del Zoologico

zoologico::zoologico(string nombreZoologico) {
    this->nombreZoologico = nombreZoologico;
}

void animales::agregarZoologico(string nombre, string especie, string tipoHabitat,
                                int edad, string tipoAlimentacion, string estadoSalud){
    int bandera = 0;
    vector<animales*>::iterator itVectorHabitat;
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