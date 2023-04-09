//
// Created by sebat on 4/04/2023.
//

#include "zoologico.h"
#include "animales.h"

// Constructor del Zoologico para iniciar la simulación
zoologico::zoologico(string nombreZoologico) {
    this->nombreZoologico = nombreZoologico;
}

// Este metodo agrega los habitats en el vector de habitats ya que mas adelante nos ayudara para saber si un animal
// pertenece al habitat o no.
void zoologico::agregarHabitat(string tipoHabitat) {
    vector<habitat *>::iterator itVectorHabitat;
    int bandera = 0;
    for (itVectorHabitat = this->vectorHabitat.begin();itVectorHabitat != this->vectorHabitat.end() and bandera == 0; ++itVectorHabitat){
        habitat *pHabitat = *itVectorHabitat;
        if(pHabitat->getHabitat() == tipoHabitat){
            bandera = 1;
            cout << "Esta habitat ya se ha creado, intente de nuevo." << endl;
        }
    }
    if(bandera == 0){
        vectorHabitat.push_back(new habitat(tipoHabitat));
        cout << "Se agrego un habitat"<<endl;
    }
}

void zoologico::ingresarAnimal(int id, string nombre, string especie, string tipoHabitat, int edad, string tipoAlimentacion,
                             string estadoSalud, int horasDormir, int estadoActivo, int estadoJugar){
    vector<habitat *>::iterator itVectorHabitat;
    int bandera = 0;
    for (itVectorHabitat = this->vectorHabitat.begin();itVectorHabitat != this->vectorHabitat.end() and bandera == 0; ++itVectorHabitat){
        habitat *pHabitat = *itVectorHabitat;
        if(pHabitat->getHabitat() == tipoHabitat){
            pHabitat->agregarZoologico(id, nombre, especie, tipoHabitat,edad, tipoAlimentacion,
                    estadoSalud, horasDormir, estadoActivo, estadoJugar);
            bandera = 1;
        }
    }
    if(bandera == 0){
        cout << "Lo sentimos el animal no se pudo agregar," << tipoHabitat
        << " no existe como un habitat en nuestro sistema por el momento\n";
    }


}

void zoologico::buscarAnimal(int idAnimal, string aHabitat, int opcion) {
    vector<habitat*>::iterator itVectorHabitat;
    int bandera = 0;
    for (itVectorHabitat = this->vectorHabitat.begin();
         itVectorHabitat != this->vectorHabitat.end() and bandera == 0; ++itVectorHabitat) {
        habitat *pHabitat = *itVectorHabitat;
        if(pHabitat->getHabitat() == aHabitat){
            if(opcion == 5){
                pHabitat->mostrarInfo(idAnimal);
            }
            else if(opcion == 6){
                pHabitat->dietaVectorAnimales(idAnimal);
            }
            else{
                pHabitat->interactuarAnimal(idAnimal);
            }
            bandera = 1;
        }
    }
}

// Muestra las habitats que tiene el vector
void zoologico::mostrarHabitats() {
    vector<habitat *>::iterator itVectorHabitat;
    if(vectorHabitat.size() != 0){
        cout << "\nLista de habitats del Zoologico:\n";
        for (itVectorHabitat = this->vectorHabitat.begin();
             itVectorHabitat != this->vectorHabitat.end(); ++itVectorHabitat) {
            habitat *pHabitat = *itVectorHabitat;
            cout << pHabitat->getHabitat() << endl;
            cout <<endl;
        }
    }
    else{
        cout << "EL zoologico no cuenta con Habitats por el momento" << endl;
    }
}

void zoologico::mostrarAnimalesZoo(){
    vector<habitat *>::iterator itVectorHabitat;
    if(vectorHabitat.size() != 0){
        cout << "\tListado de animales Zoo de Cali" << endl;
        for (itVectorHabitat = this->vectorHabitat.begin();
             itVectorHabitat != this->vectorHabitat.end(); ++itVectorHabitat) {
            habitat *pHabitat = *itVectorHabitat;
            pHabitat->mostrarAnimales();
            cout << endl;
        }
    }
    else{
        cout << "EL zoologico no cuenta con Habitats por el momento, por lo tanto tampoco con animales" << endl;
    }
}

// Desde aqui inician los gets
vector<habitat*> zoologico::getVectorHabitat() {
    return this->vectorHabitat;
}

