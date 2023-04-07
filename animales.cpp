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
// Constructor de animales para comenzar el zoologico, ubicado en el main
animales::animales(string nombreAnimal) {
    this->nombreAnimal = nombreAnimal;
}

animales::animales(int idAnimal, string tipoDieta, string tipoAlimentacion) {
    this->idAnimal = idAnimal;
    this->tipoDieta = tipoDieta;
    this->tipoAlimentacion = tipoAlimentacion;
}

void animales::accionesComer(int idAnimal, int accionAnimal) {
    string comida;


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

void animales::setTipoDieta(string tipoDieta) {
    this->tipoDieta = tipoDieta;
}
