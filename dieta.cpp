//
// Created by sebat on 4/04/2023.
//

#include "dieta.h"
#include "zoologico.h"
dieta::dieta(string tipoDieta){
    this->tipoDieta = tipoDieta;
}

// Este metodo ayuda a agregar la comida de los animales a sus respectivos vectores dependiendo de su tipo de alimentación


//void animales::agregarComida() {
//    string tipoDieta, tipoAlimentacion;
//    int idAnimal;
//    cout << "Escribe el id del animal para agregar una dieta" << endl;
//    cin >> idAnimal;
//    cout << "Escribe el tipo de alimentacion del animal:" << endl;
//    cin >> tipoAlimentacion;
//    cout << "Escribe la comida a darle:" << endl;
//    cin >> tipoDieta;
//    vector<animales*>::iterator itVectorAnimal;
//    int bandera = 0;
//    for (itVectorAnimal = this->vectorAnimales.begin(); itVectorAnimal != this->vectorAnimales.end() and bandera == 0; ++itVectorAnimal) {
//        animales *pAnimales = *itVectorAnimal;
//        if(pAnimales->getIdAnimal() == idAnimal and pAnimales->getTipoAlimentacion() == tipoAlimentacion) {
//            agregarComida(idAnimal,tipoDieta);
//            bandera = 1;
//        }
//    }
//    if(bandera == 0){
//        cout << "No se encontro algun animal con ese Id o con el mismo tipo de alimentacion"<<endl;
//    }else{
//        cout << "Se agrego la comida a la lista"<<endl;
//    }
//
//}

//void zoologico::mostrarInfoDieta() {
//    unordered_map<int, animales *>::iterator itMap;
//    int bandera = 0;
//    for (itMap = this->mapaComida.begin(); itMap != this->mapaComida.end(); ++itMap) {
//        int llave = itMap->first;
//        animales *pAnimales = itMap->second;
//        cout <<"Id: "<< itMap->first << " " << "Tipo Dieta: "<< itMap->second->getTipoDieta()<< endl;
//    }
//    vector<animales*>::iterator itVectorAnimal;
//    for (itVectorAnimal = this->vectorComida.begin(); itVectorAnimal != this->vectorComida.end(); ++itVectorAnimal) {
//        animales *pAnimales = *itVectorAnimal;
//            cout << "Id: "<<pAnimales->getIdAnimal()<<endl<<"Tipo Dieta: "<<pAnimales->getTipoDieta()<<endl;
//        }
//}

//void dieta::mostrarInfo() {
//    vector<animales*>::iterator itVectorComida;
//    vector<dieta*>::iterator itVectorHerbivoro;
//    vector<dieta*>::iterator itVectorOmnivoro;
//    int bandera = 0;
//    cout << "\nLista de comida carnivoros:\n";
//    for (itVectorComida = this->vectorComida.begin(); itVectorComida != this->vectorComida.end(); ++itVectorComida) {
//        dieta *pComida = *itVectorComida;
//        if (pComida->getTipoAlimentacion() == "carnivoro") {
//            cout << "Dieta: " << pComida->getTipoDieta() << endl;
//        }
//    }
//    cout << "\nLista de comida Herbivoros:\n";
//    for (itVectorHerbivoro = this->vectorHerbivoro.begin(); itVectorHerbivoro != this->vectorHerbivoro.end()and bandera == 0; ++itVectorHerbivoro) {
//        dieta *pHerbivoro = *itVectorHerbivoro;
//        cout << "Dieta: " << pHerbivoro->getTipoDietaHerbivoro()<<endl;
//        bandera = 1;
//    }
//    cout << "\nLista de comida Omnivoros:\n";
//    for (itVectorOmnivoro = this->vectorOmnivoro.begin(); itVectorOmnivoro != this->vectorOmnivoro.end()and bandera == 0; ++itVectorOmnivoro) {
//        dieta *pOmnivoro = *itVectorOmnivoro;
//        cout << "Dieta: " << pOmnivoro->getTipoDietaOmnivoro()<<endl;
//        bandera = 1;
//    }
//    }
//}

string dieta::getTipoDieta(){
    return tipoDieta;
}
//void dieta::setTipoDietaCarnivoro(string tipoDietaCarnivoro) {
//    this->tipoDietaCarnivoro = tipoDietaCarnivoro;
//}