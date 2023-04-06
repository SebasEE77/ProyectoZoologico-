//
// Created by sebat on 4/04/2023.
//

#include "zoologico.h"
#include "animales.h"

// Constructor del Zoologico

zoologico::zoologico(string nombreZoologico) {
    this->nombreZoologico = nombreZoologico;
}

// Este metodo agrega los habitats en el vector de habitats ya que mas adelante nos ayudara para saber si un animal
// pertenece al habitat o no.
void zoologico::agregarZoologico(string tipoHabitat) {
    vectorHabitat.push_back(new habitat(tipoHabitat));
    cout << "Se agrego un habitat"<<endl;
}

// Muestra las habitats que tiene el vector
void zoologico::mostrarInfo() {
    vector<habitat *>::iterator itVectorHabitat;
    cout << "\nLista de habitats del Zoologico:\n";
    for (itVectorHabitat = this->vectorHabitat.begin();
         itVectorHabitat != this->vectorHabitat.end(); ++itVectorHabitat) {
        habitat *pHabitat = *itVectorHabitat;
        cout << "Habitat: " << pHabitat->getHabitat() << endl;
        cout <<endl;
    }
}

