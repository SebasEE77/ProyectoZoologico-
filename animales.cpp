//
// Created by sebat on 4/04/2023.
//

#include "animales.h"

// Constructor de la clase animal. Aunque esta clase no tenga los atributos, se pone aquí el constructor por coherencia
animales::animales(int idAnimal, string nombre, string especie, string tipoHabitat, int edad, string tipoAalimentacion,
                   string estadoSalud) {
    this->idAnimal = idAnimal;
    this->nombre = nombre;
    this->especie = especie;
    this->tipoHabitat = tipoHabitat;
    this->edad = edad;
    this->tipoAlimentacion = tipoAalimentacion;
    this->estadoSalud = estadoSalud;
}
animales::animales(string nombreAnimal) {
    this->nombreAnimal = nombreAnimal;
}
animales::animales(int idAnimal, string tipoDieta) {
    this->idAnimal = idAnimal;
    this->tipoDieta = tipoDieta;
}

void animales::agregarComida(int idAnimal, string tipoDieta) {
    animales *pAnimales = new animales(idAnimal, tipoDieta);
    this->mapaComida.insert(make_pair(idAnimal, pAnimales));
    cout << "Se agrego una comida a la lista"<<endl;
}

void animales::mostrarInfoDieta() {
    unordered_map<int, animales *>::iterator itMap;
    for (itMap = this->mapaComida.begin(); itMap != this->mapaComida.end(); ++itMap) {
        int llave = itMap->first;
        animales *pAnimales = itMap->second;
        cout << "Id: " << itMap->first << " " << "Tipo Dieta: " << itMap->second->getTipoDieta() << endl;
    }
}



// Desde aqui van los Gets
int animales::getIdAnimal(){
    return idAnimal;
}
string animales::getEspecie() {
    return especie;
}
int animales::getEdad() {
    return edad;
}
string animales::getTipoAlimentacion() {
    return tipoAlimentacion;
}
string animales::getEstadoSalud() {
    return estadoSalud;
}
string animales::getNombre(){
    return nombre;
}
string animales::getHabitat() {
    return tipoHabitat;
}
string animales::getTipoDieta(){
    return tipoDieta;
}

