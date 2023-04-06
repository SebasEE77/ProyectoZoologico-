//
// Created by sebat on 4/04/2023.
//

#include "animales.h"
#include "zoologico.h"

// Constructor de la clase animal. Aunque esta clase no tenga los atributos, se pone aquí el constructor por coherencia
animales::animales(string nombreZoologico){
    this->nombreZoologico = nombreZoologico;
    this->idAnimal = 1;
}

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


// Este metodo agrega los animales al vector teniendo en cuenta las caracteristicas pedidas en el main. Aqui hay una bandera ya que
// ayuda a para el ciclo del for cuando se debe y no lo recorra inecesariamente.
void zoologico::agregarZoologico(string nombre, string especie, string tipoHabitat,
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



void animales::mostrarInfo() {
    vector<animales*>::iterator itVectorAnimales;
    vector<habitat*>::iterator itVectorHabitat;
    cout << "\nLista de habitats:\n";
    for (itVectorHabitat = this->vectorHabitat.begin(); itVectorHabitat != this->vectorHabitat.end(); ++itVectorHabitat) {
        habitat *pHabitat = *itVectorHabitat;
        cout << "Habitat: "<<pHabitat->getHabitat()<<endl;
    }
    cout << "\nLista de animales:\n";
    for (itVectorAnimales = this->vectorAnimales.begin(); itVectorAnimales != this->vectorAnimales.end(); ++itVectorAnimales) {
        animales *pAnimales = *itVectorAnimales;
        cout << "Id: "<<pAnimales->getIdAnimal()<<endl;
        cout << "Nombre: "<<pAnimales->getNombre()<<endl;
        cout << "Especie: "<<pAnimales->getEspecie()<<endl;
        cout << "Habitat: "<<pAnimales->getHabitat()<<endl;
        cout << "Edad: "<<pAnimales->getEdad()<<endl;
        cout << "Tipo de Alimentacion: "<<pAnimales->getTipoAlimentacion()<<endl;
        cout << "Estado de salud: "<<pAnimales->getEstadoSalud()<<endl;
        cout <<endl;
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

