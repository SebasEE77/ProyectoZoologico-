#include <iostream>
#include "zoologico.h"
#include "animales.h"
#include "habitat.h"


// El metodo para poder realizar la agregación del habitat.
void primeraOpcion(zoologico *pHabitat){
    string tipoHabitat;
    cout << "Hola usuario, estas son las opciones para agregar habitats" << endl;
    cout << "-> desertico\n" << "-> selvatico\n" << "-> polar\n" << "-> acuatico\n" << endl;
    cout<<"Escriba el habitat que desea agregar: "<<endl;
    do{
        cin>>tipoHabitat;
    }while(tipoHabitat != "desertico" and tipoHabitat != "selvatico" and tipoHabitat != "polar" and tipoHabitat != "acuatico");
    pHabitat->agregarHabitat(tipoHabitat);
}
// El metodo sirve para poder realizar la agregación de los animales. Se pregunta de una vez todas las caracteristicas del animal y los
// ifs sirven para confirmar que el usuario escogió bien el tipo de habitat del animal, ya que podra suceder que un animal sea asignado
// a un habitat incoherente.
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
    cout << "Escriba la edad: "<<endl;
    cin>>edad;
    cout << "Escriba el tipo de alimentacion: "<<endl;
    getline(cin >> std::ws, tipoAlimentacion);
    cout << "Escriba su estado de salud: "<<endl;
    getline(cin >> std::ws, estadoSalud);
    cout << "Indique cuantas horar debe dormir el animal: " << endl;
    cin >> horasDormir;
    pZoologico->ingresarAnimal(id,nombre, especie, tipoHabitat, edad, tipoAlimentacion, estadoSalud, horasDormir, 1, 0);

}
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
        cout << "6. Menú de comidas\n";
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
    } while (opc != 0);
}

int main() {
    zoologico *pZoologico = new zoologico("Zoologico");
    mostrarMenu(pZoologico);
}