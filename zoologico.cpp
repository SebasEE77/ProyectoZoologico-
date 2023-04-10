//
// Created by sebat on 4/04/2023.
//

#include "zoologico.h"
#include "animales.h"

// Constructor del Zoologico para iniciar la simulación
zoologico::zoologico(string nombreZoologico) {
    this->nombreZoologico = nombreZoologico;
}

// Este metodo de zoologico recibira el nombre del habitat a agregar dentro del vector habitats dentro de la clase zoologico. Dentro de la funcion
// tambien se verificara si tal habitat ya se ha creado o no.
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

// Este metodo dentro de zoologico recibira todos los datos del animal que se esta queriendo ingresar, primero verificando que su habitat exista y
// posteriormente agregando al animal llamando al metodo agregarZoologico del habitat correspondiente
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
// Este metodo recibe el id del animal , como el habitat en la que se encuentra y la opcion a realizar con dicho animal. Dentro de esta se recorre
// el vector de habitat buscando el habitat especifica del animal y luego de acuerdo a la opcion especificada se llama el metodo correspondiente del
// habitat, ya sea mostrarInfo, dietaVectorAnimales o interactuarAnimal
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
        }else{
            cout << "El habitat escrito no existe"<<endl;
        }
    }
    if(bandera == 0){
        cout << "No existe tal habitat, por lo tanto tampoco el animal" << endl;
    }
}

// Este metodo recorre el vector de habitat dentro de zoologico, mostrando asi las habitats existentes
void zoologico::mostrarHabitats() {
    vector<habitat *>::iterator itVectorHabitat;
    if(vectorHabitat.size() != 0){
        cout << "\tLista de habitats del Zoologico:\n";
        for (itVectorHabitat = this->vectorHabitat.begin();
             itVectorHabitat != this->vectorHabitat.end(); ++itVectorHabitat) {
            habitat *pHabitat = *itVectorHabitat;
            cout << "Habitat: "<< pHabitat->getHabitat() << endl;
            cout <<endl;
        }
    }
    else{
        cout << "EL zoologico no cuenta con Habitats por el momento" << endl;
    }
}

// Este metodo recorre el vector de habitats para asi en cada una llamar al metodo de mostrarAnimales, mostrando de tal modo los animales dentro de
// cada habitat existente
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

