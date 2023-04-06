//
// Created by sebat on 4/04/2023.
//
#include "zoologico.h"
#include "habitat.h"

 //Constructor de la clase habitat
habitat::habitat(string tipoHabitat){
    this->tipoHabitat = tipoHabitat;
}

// Este metodo agrega los animales al vector teniendo en cuenta las caracteristicas pedidas en el main. Aqui hay una bandera ya que
// ayuda a para el ciclo del for cuando se debe y no lo recorra inecesariamente.
void habitat::agregarZoologico(int id, string nombre, string especie, string tipoHabitat,
                                 int edad, string tipoAlimentacion, string estadoSalud){

        vectorAnimales.push_back(new animales(id, nombre, especie, tipoHabitat,
                                                  edad, tipoAlimentacion, estadoSalud));
}


// Solamente muestra la información general del animal. Uno puede decidir que información ver de cuaqluier animal de acuerdo al id que tenga a gusto del usuario.
void habitat::mostrarInfo(int idAnimal) {
    int bandera = 0;
    vector<animales*>::iterator itVectorAnimales;
    for (itVectorAnimales = this->vectorAnimales.begin(); itVectorAnimales != this->vectorAnimales.end() and bandera == 0; ++itVectorAnimales) {
        animales *pAnimales = *itVectorAnimales;
        if(pAnimales->getIdAnimal() == idAnimal){
            cout << "Id: " << pAnimales->getIdAnimal() << endl;
            cout << "Nombre: " << pAnimales->getNombre() << endl;
            cout << "Especie: " << pAnimales->getEspecie() << endl;
            cout << "Habitat: " << pAnimales->getHabitat() << endl;
            cout << "Edad: " << pAnimales->getEdad() << endl;
            cout << "Tipo de Alimentacion: " << pAnimales->getTipoAlimentacion() << endl;
            cout << "Estado de salud: " << pAnimales->getEstadoSalud() << endl;
            cout << endl;
            bandera = 1;
        }
    }
    if(bandera == 0){
        cout << "El animal no pertenece al zoologico"<<endl;
    }else{
        cout << "Esta es la informacion del animal"<<endl;
    }
}

//void habitat::mostrarInfo(animales *pAnimales) {
//    cout << "Id: " << pAnimales->getIdAnimal() << endl;
//    cout << "Nombre: " << pAnimales->getNombre() << endl;
//    cout << "Especie: " << pAnimales->getEspecie() << endl;
//    cout << "Habitat: " << pAnimales->getHabitat() << endl;
//    cout << "Edad: " << pAnimales->getEdad() << endl;
//    cout << "Tipo de Alimentacion: " << pAnimales->getTipoAlimentacion() << endl;
//    cout << "Estado de salud: " << pAnimales->getEstadoSalud() << endl;
//    cout << endl;
//}
//void dieta::agregarComida(int idAnimal, string tipoAlimentacion, string tipoDieta) {
//    vector<animales*>::iterator itVectorAnimal;
//    int bandera = 0;
//    for (itVectorAnimal = this->vectorAnimales.begin(); itVectorAnimal != this->vectorAnimales.end() and bandera == 0; ++itVectorAnimal) {
//        animales *pAnimales = *itVectorAnimal;
//        if(pAnimales->getIdAnimal() == idAnimal and pAnimales->getTipoAlimentacion() == tipoAlimentacion) {
//            vectorComida.push_back(new dieta(tipoDieta));
//            bandera = 1;
//        }
//    }
//    if(bandera == 0){
//        cout << "No se encontro algun animal con ese Id o con el mismo tipo de alimentacion"<<endl;
//    }else{
//        cout << "Se agrego la comida a la lista"<<endl;
//    }
//}
//
//void dieta::mostrarInfo() {
//    vector<dieta *>::iterator itVectorComida;
//    vector<dieta*>::iterator itVectorHerbivoro;
//    vector<dieta*>::iterator itVectorOmnivoro;
//    int bandera = 0;
//    cout << "\nLista de comida carnivoros:\n";
//    for (itVectorComida = this->vectorComida.begin(); itVectorComida != this->vectorComida.end(); ++itVectorComida) {
//        dieta *pComida = *itVectorComida;
//        if (pComida->getTipoAlimentacion() == "carnivoro") {
//            cout << "Dieta: " << pComida->getTipoDieta() << endl;
//        }

//void habitat::mostrarInfo() {
//    vector<animales *>::iterator itVectorAnimales;
//    for (itVectorAnimales = this->vectorAnimales.begin();
//         itVectorAnimales != this->vectorAnimales.end(); ++itVectorAnimales) {
//        animales *pAnimales = *itVectorAnimales;
//        cout << "Id: " << pAnimales->getIdAnimal() << endl;
//        cout << "Nombre: " << pAnimales->getNombre() << endl;
//        cout << "Especie: " << pAnimales->getEspecie() << endl;
//        cout << "Habitat: " << pAnimales->getHabitat() << endl;
//        cout << "Edad: " << pAnimales->getEdad() << endl;
//        cout << "Tipo de Alimentacion: " << pAnimales->getTipoAlimentacion() << endl;
//        cout << "Estado de salud: " << pAnimales->getEstadoSalud() << endl;
//        cout << endl;
//    }
//}

string habitat::getHabitat(){
    return tipoHabitat;
}

vector<animales*>habitat::getVectorAnimales() {
    return this->vectorAnimales;
};