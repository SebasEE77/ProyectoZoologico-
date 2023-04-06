//
// Created by sebat on 4/04/2023.
//

#include "dieta.h"
//dieta::dieta(string tipoDieta){
//    this->tipoDieta = tipoDieta;
//}
dieta::dieta(string tipoDietaCarnivoro, string tipoDietaHerbivoro, string tipoDietaOmnivoro){
    this->tipoDietaCarnivoro = tipoDietaCarnivoro;
    this->tipoDietaHerbivoro = tipoDietaHerbivoro;
    this->tipoDietaOmnivoro = tipoDietaOmnivoro;
}

// Este metodo ayuda a agregar la comida de los animales a sus respectivos vectores dependiendo de su tipo de alimentación
void dieta::agregarComida(int idAnimal, string tipoAlimentacion, string tipoDieta) {
    string tipoDietaCarnivoro,tipoDietaOmnivoro,tipoDietaHerbivoro;
    vector<animales*>::iterator itVectorAnimal;
    int bandera = 0;
    for (itVectorAnimal = this->vectorAnimales.begin(); itVectorAnimal != this->vectorAnimales.end() and bandera == 0; ++itVectorAnimal) {
        animales *pAnimales = *itVectorAnimal;
        if(pAnimales->getIdAnimal() == idAnimal and pAnimales->getTipoAlimentacion() == "carnivoro") {
            vectorCarnivoro.push_back(new dieta(tipoDieta,tipoDietaHerbivoro,tipoDietaOmnivoro));
            bandera = 1;
        }
        else if(pAnimales->getIdAnimal() == idAnimal and pAnimales->getTipoAlimentacion() == "herbivoro") {
                vectorHerbivoro.push_back(new dieta(tipoDietaCarnivoro,tipoDieta,tipoDietaOmnivoro));
                bandera = 1;
        }
        else{
            vectorOmnivoro.push_back(new dieta(tipoDietaCarnivoro,tipoDietaHerbivoro,tipoDieta));
            bandera = 1;
        }
    }
    if(bandera == 0){
        cout << "No se encontro algun animal con ese Id o con el mismo tipo de alimentacion"<<endl;
    }else{
        cout << "Se agrego la comida a la lista"<<endl;
    }
}

void dieta::mostrarInfo() {
    vector<dieta*>::iterator itVectorCarnivoro;
    vector<dieta*>::iterator itVectorHerbivoro;
    vector<dieta*>::iterator itVectorOmnivoro;
    int bandera = 0;
    cout << "\nLista de comida carnivoros:\n";
    for (itVectorCarnivoro = this->vectorCarnivoro.begin(); itVectorCarnivoro != this->vectorCarnivoro.end() and bandera == 0; ++itVectorCarnivoro) {
        dieta *pCarnivoro = *itVectorCarnivoro;
        cout << "Dieta: " << pCarnivoro->getTipoDietaCarnivoro()<<endl;
        bandera = 1;
    }
    cout << "\nLista de comida Herbivoros:\n";
    for (itVectorHerbivoro = this->vectorHerbivoro.begin(); itVectorHerbivoro != this->vectorHerbivoro.end()and bandera == 0; ++itVectorHerbivoro) {
        dieta *pHerbivoro = *itVectorHerbivoro;
        cout << "Dieta: " << pHerbivoro->getTipoDietaHerbivoro()<<endl;
        bandera = 1;
    }
    cout << "\nLista de comida Omnivoros:\n";
    for (itVectorOmnivoro = this->vectorOmnivoro.begin(); itVectorOmnivoro != this->vectorOmnivoro.end()and bandera == 0; ++itVectorOmnivoro) {
        dieta *pOmnivoro = *itVectorOmnivoro;
        cout << "Dieta: " << pOmnivoro->getTipoDietaOmnivoro()<<endl;
        bandera = 1;
    }
}

//void dieta::mostrarInfo2() {
//    vector<dieta *>::iterator itVectorOmnivoro;
//    cout << "\nLista de comida Omnivoros:\n";
//    for (itVectorOmnivoro = this->vectorOmnivoro.begin(); itVectorOmnivoro != this->vectorOmnivoro.end(); ++itVectorOmnivoro) {
//        dieta *pOmnivoro = *itVectorOmnivoro;
//        cout << "Dieta: " << pOmnivoro->getTipoDieta()<<endl;
//    }
//}

string dieta::getTipoDietaCarnivoro(){
    return tipoDietaCarnivoro;
}
string dieta::getTipoDietaHerbivoro(){
    return tipoDietaHerbivoro;
}
string dieta::getTipoDietaOmnivoro(){
    return tipoDietaOmnivoro;
}

//string dieta::getTipoDieta2(){
//    return tipoDieta2;
//}
void dieta::setTipoDietaCarnivoro(string tipoDietaCarnivoro) {
    this->tipoDietaCarnivoro = tipoDietaCarnivoro;
}