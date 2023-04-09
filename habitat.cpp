//
// Created by sebat on 4/04/2023.
//
#include "habitat.h"

 //Constructor de la clase habitat
habitat::habitat(string tipoHabitat){
    this->tipoHabitat = tipoHabitat;
}

// Este metodo agrega los animales al vector teniendo en cuenta las caracteristicas pedidas en el main. Aqui hay una bandera ya que
// ayuda a para el ciclo del for cuando se debe y no lo recorra inecesariamente.
void habitat::agregarZoologico(int id, string nombre, string especie, string tipoHabitat, int edad, string tipoAlimentacion,
                          string estadoSalud, int horasDormir, int estadoActivo, int estadoJugar) {

        vectorAnimales.push_back(new animales(id, nombre, especie, tipoHabitat,
                                                  edad, tipoAlimentacion, estadoSalud, horasDormir, estadoActivo, estadoJugar));
        cout << "Se agrego un animal"<<endl;
}

void habitat::mostrarAnimales() {
    if(this->vectorAnimales.size() != 0){
        cout << "La lista de animales dentro del habitat " << this->tipoHabitat << " son:" << endl;
        vector<animales*>::iterator itVectorAnimales;
        for (itVectorAnimales = this->vectorAnimales.begin(); itVectorAnimales != this->vectorAnimales.end(); ++itVectorAnimales) {
            animales *pAnimales = *itVectorAnimales;
            cout << "-----------------------------------" << endl;
            cout << "Nombre: " << pAnimales->getNombre() << endl;
            cout << "Especie: " << pAnimales->getEspecie() << endl;
            cout << "-----------------------------------";
        }

    }
    else{
        cout << "En este momento no hay animales dentro del habitat " << this->tipoHabitat << endl;
    }
}
// Solamente muestra la información general del animal. Uno puede decidir que información
// ver de cuaqluier animal de acuerdo al id que tenga a gusto del usuario.
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

<<<<<<< HEAD
void habitat::dietaVectorAnimales(int idAnimal) {
    int opcion = -1;
=======
// Este metodo se encarga especificamente de recorrer el vector animal para poder saber si, en este caso, el id
// concuerda con que se pide en el main (metodos: quintaOpcion y cuartaOpcion)
int habitat::recorrerVectorAnimales(int idAnimal) {
>>>>>>> af80c4b4186192fbcd2e9f1edb26383c49918029
    int bandera = 0;
    string comida;
    cout<< "Bienvenido al menu de dieta para los animales del Zoo\n";
    cout <<"->[1]. Ver la dieta del animal\n";
    cout <<"->[2]. Agregar comida a la dieta del animal\n";
    cout <<"->[3]. Modificar/Eliminar comida de la dieta del animal\n";
    cout<<"Elige una opcion: ";
    do{
        cin >> opcion;
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
                cout << "Ingrese la comida:" << endl;
                cin >> comida;
                if(accion == 1){
                    pAnimales->modificarDieta("modificar", comida);
                }
                else{
                    pAnimales->modificarDieta("eliminar", comida);
                }
            }
        }
    }
    if(bandera == 0){
        cout << "El animal indicado no existe\n";
    }
}


// A partir de aqui estan los gets
string habitat::getHabitat(){
    return tipoHabitat;
}

void habitat::interactuarAnimal(int idAnimal) {
    int bandera = 0;
    int opcion = -1;
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
                        pAnimales->jugar();
                    }
                    else if(opcion == 2){
                        pAnimales->comer();
                    }
                    else{
                        pAnimales->dormir();
                    }
                    bandera = 1;
                }
    }
}