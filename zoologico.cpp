//
// Created by sebat on 4/04/2023.
//

#include "zoologico.h"
#include "animales.h"

// Constructor del Zoológico para iniciar la simulación.
zoologico::zoologico(string nombreZoologico) {
    this->nombreZoologico = nombreZoologico;
}

// Este metodo de zoológico recibira el nombre del hábitat donde se agregará al vector hábitat que esta dentro de la clase zoologico.
// Dentro de la función, también se verificará si tal habitat existe o no.
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

// Este metodo dentro de zoológico recibira todos los datos del animal que se esta queriendo ingresar, primero verificando que su hábitat exista y
// posteriormente agregando al animal llamando al metodo agregarZoologico del hábitat correspondiente. Aquí hay una bandera ya que
// ayuda a para el ciclo del for cuando se debe y asì no recorrerlo innecesariamente.
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
// Este metodo recibe el id del animal, el hábitat y la opción a realizar con el animal. Dentro de esta se recorre
// el vector de habitat buscando el hábitat especifica del animal, luego de acuerdo a la opción específicada se llama el metodo correspondiente del
// hábitat, ya sea mostrarInfo, dietaVectorAnimales o interactuarAnimal.
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

// Este metodo recorre el vector de hábitat dentro de zoológico, mostrando así las hábitats existentes.
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

