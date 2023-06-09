//
// Created by sebat on 4/04/2023.
//
#include "habitat.h"

 //Constructor de la clase habitat
habitat::habitat(string tipoHabitat){
    this->tipoHabitat = tipoHabitat;
}

// Este metodo agrega los animales al vectorAnimales teniendo en cuenta las características recibidas en el metodo de ingresarAnimales
//  de zoologico.
void habitat::agregarZoologico(int id, string nombre, string especie, string tipoHabitat, int edad, string tipoAlimentacion,
                          string estadoSalud, int horasDormir, int estadoActivo, int estadoJugar) {

        vectorAnimales.push_back(new animales(id, nombre, especie, tipoHabitat,
                                                  edad, tipoAlimentacion, estadoSalud, horasDormir, estadoActivo, estadoJugar));
        cout << "Se agrego un animal"<<endl;
}

// Este metodo lo que hace es listar los animales dentro del vectorAnimales mostrando su nombre y tipo de alimentación,
// además, si no existe ningun animal se muestra el mensaje indicando que no existen.
void habitat::mostrarAnimales() {
    if(this->vectorAnimales.size() != 0){
        cout << "La lista de animales dentro del habitat " << this->tipoHabitat << " son:" << endl;
        vector<animales*>::iterator itVectorAnimales;
        for (itVectorAnimales = this->vectorAnimales.begin(); itVectorAnimales != this->vectorAnimales.end(); ++itVectorAnimales) {
            animales *pAnimales = *itVectorAnimales;
            cout << "-----------------------------------" << endl;
            cout << "Nombre: " << pAnimales->getNombre() << endl;
            cout << "Tipo de Alimentacion: " << pAnimales->getTipoAlimentacion() << endl;
            cout << "-----------------------------------";
        }

    }
    else{
        cout << "En este momento no hay animales dentro del habitat " << this->tipoHabitat << endl;
    }
}
// Este metodo se encarga de mostrar la información completa del animal de acuerdo al id pasado como parametro de la función. Aquí se busca
// dentro del vectorAnimales del habitat que encuentra buscarAnimal de la clase zoologico.
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
        cout << "\t ->Esta es la  ficha de informacion del animal<-"<<endl;
    }
}

// Este metodo lo que se encarga es de buscar al animal dentro del vectorAnimales de acuerdo a su id para de tal modo gestionar la dieta del animal,
// ya sea agregar una comida, cambiarla por otra o eliminarla de su dieta.

void habitat::dietaVectorAnimales(int idAnimal) {
    int opcion = -1;
    int bandera = 0;
    string comida;
    cout<< "Bienvenido al menu de dieta para los animales del Zoo\n";
    cout <<"->[1]. Ver la dieta del animal\n";
    cout <<"->[2]. Agregar comida a la dieta del animal\n";
    cout <<"->[3]. Modificar/Eliminar comida de la dieta del animal\n";
    cout<<"Elige una opcion: ";
    do{
        cin >>opcion;
        if(opcion > 3 or opcion < 1){
            cout<<"Elige una opcion: ";
        }
    }while(opcion > 3 or opcion < 1);
    vector<animales *>::iterator itVectorAnimales;
    for (itVectorAnimales = this->vectorAnimales.begin();
         itVectorAnimales != this->vectorAnimales.end() and bandera == 0; ++itVectorAnimales) {
        animales *pAnimales = *itVectorAnimales;
        if (pAnimales->getIdAnimal() == idAnimal) {
            if(opcion == 1){
                pAnimales->mostrarDietaAnimal();
                bandera = 1;
            }
            else if (opcion == 2){
                bandera = 1;
                string dieta = pAnimales->getTipoAlimentacion();
                pAnimales->mostrarDietasDisponoble(dieta);
                cout << "-----------------------------------------" << endl;
                cout << "Elige una comida de la lista para el animal\n";
                cin >> comida;
                while(pAnimales->verificarComida(comida) == 0){
                    cout << "Vuelva a escribir una comida de acuerdo a la lista"<<endl;
                    cin >> comida;
                }
                pAnimales->agregarComida(comida);

            }
            else{
                bandera = 1;
                int accion = -1;
                cout << "->[1]. Modificar\n";
                cout << "->[2]. Eliminar\n";
                cout << "->Escoge una opcion<-\n";
                do{
                    cin >> accion;
                }while(accion < 1 or accion > 2);
                if(accion == 1){
                    pAnimales->mostrarDietaAnimal();
                    cout <<endl<<"Ingrese la comida que quisiera modificar:" << endl;
                    cin >> comida;
                    pAnimales->modificarDieta("modificar", comida);
                }
                else{
                    pAnimales->mostrarDietaAnimal();
                    cout <<endl<< "Ingrese la comida que quisiera eiminar:" << endl;
                    cin >> comida;
                    pAnimales->modificarDieta("eliminar", comida);
                }
            }
        }
    }
    if(bandera == 0){
        cout << "El animal indicado no existe\n";
    }
}


// Este metodo se encargara de buscar al animal dentro del hábitat de acuerdo al id mandado como parametro. Luego pedira al usuario que escoga
// una opcion para interactuar con el animal, ya sea jugar, dormir o comer.
void habitat::interactuarAnimal(int idAnimal) {
    int bandera = 0;
    int opcion = -1;
    string res;
    vector<animales *>::iterator itVectorAnimales;
    for (itVectorAnimales = this->vectorAnimales.begin();
         itVectorAnimales != this->vectorAnimales.end() and bandera == 0; ++itVectorAnimales) {
                animales *pAnimales = *itVectorAnimales;
                if (pAnimales->getIdAnimal() == idAnimal){
                    cout << "Gracias por querer interactuar con nuestros animales!" << endl;
                    cout << "->[1]. Jugar\n" << "->[2]. Comer\n" << "->[3]. Dormir\n";
                    cout << "Elige la accion que quieras hacer: ";
                    do{
                        cin >> opcion;
                    }while(opcion < 1 or opcion > 3);
                    if(opcion == 1){
                        if(pAnimales->getEstadoActivo() == 0){
                            cout << "El animal esta dormiendo en este momento" << endl;
                        }
                        else if(pAnimales->getEstadoJugar() == 1){
                            cout << "El animal ya ha jugado. Desea jugar con él?";
                            do{
                                cin >> res;
                            }while(res != "si" or res != "no");
                            if(res == "si"){
                                pAnimales->jugar();
                            }
                            else{
                                pAnimales->setEstadoJugar(0);
                            }
                        }
                        else{
                            pAnimales->jugar();
                        }
                    }
                    else if(opcion == 2){
                        if(pAnimales->getEstadoActivo() == 0){
                            cout << "El animal esta dormiendo en este momento" << endl;
                        }
                        else {
                            pAnimales->comer();
                        }
                    }
                    else{
                        if(pAnimales->getEstadoActivo() == 0){
                            cout << "Se desperto el animal" << endl;
                            pAnimales->setEstadoActivo(1);
                        }
                        else {
                            pAnimales->dormir();
                        }
                    }
                    bandera = 1;
                }
    }
    if(bandera == 0){
        cout << "El animal no existe" << endl;
    }
}
// Este es el get del nombre del habitat.
string habitat::getHabitat(){
    return tipoHabitat;
}