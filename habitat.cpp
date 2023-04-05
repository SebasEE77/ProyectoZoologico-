//
// Created by sebat on 4/04/2023.
//
#include "animales.h"
#include "habitat.h"

 //Constructor de la clase habitat
habitat::habitat(string tipoHabitat){
    this->tipoHabitat = tipoHabitat;
}

// Este metodo agrega los habitats en el vector de habitats ya que mas adelante nos ayudara para saber si un animal
// pertenece al habitat o no.
void animales::agregarZoologico(string tipoHabitat) {
    vectorHabitat.push_back(new habitat(tipoHabitat));
    cout << "Se agrego un habitat"<<endl;
}


string habitat::getHabitat(){
    return tipoHabitat;
}