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

// En este caso se añade la comida al vector para tener la dieta de los animales
void zoologico::agregarComida(int idAnimal, string tipoDieta,string tipoAlimentacion) {
    vectorComida.push_back(new animales(idAnimal,tipoDieta,tipoAlimentacion));
    cout << "Se agrego una comida a la lista"<<endl;
}

// Aqui solamente se muestra la información del vector comida, dando a conocer el id y la comida del animal.
void zoologico::mostrarInfo(int idAnimal) {
    vector<animales*>::iterator itVectorAnimales;
    for (itVectorAnimales = this->vectorComida.begin(); itVectorAnimales != this->vectorComida.end() ; ++itVectorAnimales) {
        animales *pAnimales = *itVectorAnimales;
        if(pAnimales->getIdAnimal() == idAnimal){
            cout << "Id: " << pAnimales->getIdAnimal()<<endl<< "Comida: " << pAnimales->getTipoDieta() <<endl
            <<"Tipo de alimentacion: "<< pAnimales->getTipoAlimentacion()<<endl<<endl;
        }
    }
}

// Aqui se modifica la comida del animal, se tiene en cuenta especialmente el id y la comida a modificar para así agregar una nueva.
void zoologico::cambiarComida(int idAnimal, string modificar,string tipoDieta) {
    vector<animales*>::iterator itVectorAnimales;
    int bandera = 0;
    for (itVectorAnimales = this->vectorComida.begin(); itVectorAnimales != this->vectorComida.end() and bandera == 0; ++itVectorAnimales) {
        animales *pAnimales = *itVectorAnimales;
        if(pAnimales->getIdAnimal() == idAnimal and pAnimales->getTipoDieta() == modificar){
            pAnimales->setTipoDieta(tipoDieta);
            bandera = 1;
        }
    }
    if(bandera == 0){
        cout << "El id no concuerda o la comida que escribiste es erronea"<<endl;
    }else{
        cout<< "Se pudo modificar la comida"<<endl;
    }
}

// Aquí se recorre la comida para saber exactamente cual eliminar, por eso se tiene en cuenta el id y la comida a eliminar.
void zoologico::eliminarComida(int idAnimal, string modificar) {
    vector<animales*>::iterator itVectorAnimales;
    int bandera = 0;
    for (itVectorAnimales = this->vectorComida.begin(); itVectorAnimales != this->vectorComida.end() and bandera == 0; ++itVectorAnimales) {
        animales *pAnimales = *itVectorAnimales;
        if(pAnimales->getIdAnimal() == idAnimal and pAnimales->getTipoDieta() == modificar){
            vectorComida.erase(itVectorAnimales);
            bandera = 1;
        }
    }
    if(bandera == 0){
        cout << "El id no concuerda o la comida que escribiste es erronea"<<endl;
    }else{
        cout<< "Se pudo eliminar la comida"<<endl;
    }
}

void zoologico::mostrarArreglo(int idAnimal, string tipoDieta,string tipoAlimentacion){
    if (tipoAlimentacion == "Carnivoro" || tipoAlimentacion == "carnivoro") {
        cout << "Esta es la dieta que puede comer: " << endl;
        for (int i = 0; i < 6; i++) {
            cout << arregloCarnivoro[i] << endl;
        }
        cout << "Escribe la comida que le quieras agregar" << endl;
        getline(cin >> std::ws, tipoDieta);
        this->agregarComida(idAnimal, tipoDieta,tipoAlimentacion);
    }
    else if(tipoAlimentacion == "Herbivoro" || tipoAlimentacion == "herbivoro") {
        cout << "Esta es la dieta que puede comer: " << endl;
        for (int i = 0; i < 6; i++) {
            cout << arregloHerbivoro[i] << endl;
        }
        cout << "Escribe la comida que le quieras agregar" << endl;
        getline(cin >> std::ws, tipoDieta);
        this->agregarComida(idAnimal, tipoDieta,tipoAlimentacion);
    }
    else{
        cout << "Esta es la dieta que puede comer: " << endl;
        for (int i = 0; i < 6; i++) {
            cout << arregloOmnivoros[i] << endl;
        }
        cout << "Escribe la comida que le quieras agregar" << endl;
        getline(cin >> std::ws, tipoDieta);
        this->agregarComida(idAnimal, tipoDieta,tipoAlimentacion);
    }
}


// Desde aqui inician los gets
vector<habitat*> zoologico::getVectorHabitat() {
    return this->vectorHabitat;
}
vector<animales*> zoologico::getVectorComida() {
    return this->vectorComida;
}



