#include <iostream>
#include "zoologico.h"

// Creamos una función que pide por consola el nombre del hábitat a crear y verificamos que sea el correcto. Esta función se implementa
// en el main debido a que va relacionada al case 1 del switch dentro de la función mostrarMenu.
void primeraOpcion(zoologico *pHabitat){
    string tipoHabitat;
    int bandera = 0;
    cout << "Hola usuario, estas son las opciones para agregar habitats" << endl;
    cout << "-> desertico\n" << "-> selvatico\n" << "-> polar\n" << "-> acuatico\n" << endl;
    cout<<"Escriba el habitat que desea agregar: "<<endl;
    cin>>tipoHabitat;
    do{
        if(tipoHabitat != "desertico" and tipoHabitat != "selvatico" and tipoHabitat != "polar" and tipoHabitat != "acuatico"){
            cout << "Asegurate de colocar bien el tipo de habitat" << endl;
            cin>>tipoHabitat;
        }
        else{
            bandera = 1;
        }
    }while(bandera == 0);
    pHabitat->agregarHabitat(tipoHabitat);
}

// Esta función se encargara de recibir los datos del animal a ingresar para así llamar al metodo ingresarAnimal. Esta función se realiza dentro del main
// debido a que corresponde al case 2 del switch de mostrarMenu

void segundaOpcion(zoologico *pZoologico){
    string nombre, especie, tipoHabitat,tipoAlimentacion, estadoSalud;
    int edad,id, horasDormir;
    cout << "Escriba el id del animal: "<<endl;
    cin>>id;
    cout << "Escriba el nombre del animal: "<<endl;
    getline(cin >> std::ws, nombre);
    cout << "Escriba la especie del animal: "<<endl;
    getline(cin >> std::ws, especie);
    cout << "Escriba el habitat al que pertenece el animal: "<<endl;
    cin>>tipoHabitat;
    cout << "Escriba la edad, debe ser menor a 15 anios: "<<endl;
    do{
        cin>>edad;
        if(edad < 0 or edad > 15){
            cout<< "Escribe de nuevo la edad"<<endl;
        }
    }while(edad < 0 or edad > 15);
    cout << "Escriba el tipo de alimentacion: "<<endl;
    do{
        getline(cin >> std::ws, tipoAlimentacion);
        if(tipoAlimentacion != "carnivoro" and tipoAlimentacion != "herbivoro" and tipoAlimentacion != "omnivoro"){
            cout<< "Escribe de nuevo el tipo de alimentacion"<<endl;
        }
    }while(tipoAlimentacion != "carnivoro" and tipoAlimentacion != "herbivoro" and tipoAlimentacion != "omnivoro");
    cout << "Escriba su estado de salud: "<<endl;
    getline(cin >> std::ws, estadoSalud);
    cout << "Indique cuantas horar debe dormir el animal, debe ser entre 5 y 20 horas: " << endl;
    do{
        cin >> horasDormir;
        if(horasDormir < 5 or horasDormir > 20){
            cout<< "Escribe de nuevo las horas"<<endl;
        }
    }while(horasDormir < 5 or horasDormir > 20);
    pZoologico->ingresarAnimal(id,nombre, especie, tipoHabitat, edad, tipoAlimentacion, estadoSalud, horasDormir, 1, 0);

}
// Esta función recibirá el id y hábitat del animal para llamar al metodo buscarAnimal y se pasa también como parametro a la opción a realizar.
// Esta función esta dentro del main porque corresponde a los case 5, 6 y 7 del mostrarMenu.
void opcionAuxiliar(zoologico *pZoologico, int opcion){
    int idAnimal;
    string aHabitat;
    cout << "Indique el habitat del Animal" << endl;
    cin >> aHabitat;
    cout << "Indique el id del animal" << endl;
    cin >> idAnimal;
    pZoologico->buscarAnimal(idAnimal, aHabitat, opcion);
}
// Se muestra el menu y se llaman los metodos.
void mostrarMenu(zoologico *pZoologico) {
    int opc = 0;
    do
    {
        cout << "\n\t**** Bienvenido al Zoologico de Cali ****\n";
        cout << "1. Agregar habitat al zoologico\n";
        cout << "2. Agregar un animal al zoologico\n";
        cout << "3. Ver lista de Habitats\n";
        cout << "4. Ver lista de animales del zoologico\n";
        cout << "5. Ver informacion sobre un animal\n";
        cout << "6. Menu de comidas\n";
        cout << "7. Interactuar con un animal\n";
        cout << "8. Salir\n" << endl;
        cin >> opc;
        switch (opc) {
            case 1:
                primeraOpcion(pZoologico);
                break;
            case 2:
                segundaOpcion(pZoologico);
                break;
            case 3:
                pZoologico->mostrarHabitats();
                break;
            case 4:
                pZoologico->mostrarAnimalesZoo();
                break;
            case 5:
                opcionAuxiliar(pZoologico, 5);
                break;
            case 6:
                opcionAuxiliar(pZoologico, 6);
                break;
            case 7:
                opcionAuxiliar(pZoologico, 7);
                break;
            case 8:
                cout << "\t----EXIT----\n";
                cout << "Vuelva pronto!";
                break;
            default:
                cout << "Opcion invalida!\n";
                break;
        }
    } while (opc != 8);
}

int main() {
    zoologico *pZoologico = new zoologico("Zoologico de Cali");
    mostrarMenu(pZoologico);
    return 0;
}