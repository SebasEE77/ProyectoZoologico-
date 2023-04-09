#include <iostream>
#include "zoologico.h"
#include "animales.h"
#include "habitat.h"


// Metodo para poder realizar la agregación del habitat. Sirve para poder llamarlo en el menu y así facilmente
// llamar al otro metodo para que agregue el habitat.
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
<<<<<<< HEAD
// El metodo sirve para poder realizar la agregación de los animales. Se pregunta de una vez todas las caracteristicas del animal y los
// ifs sirven para confirmar que el usuario escogió bien el tipo de habitat del animal, ya que podra suceder que un animal sea asignado
// a un habitat incoherente.
void segundaOpcion(zoologico *pZoologico){
=======
// El metodo sirve para poder realizar la agregación de los animales. Se pregunta de una vez todas las caracteristicas del animal, y
// se recorre el vector habitat para saber si existe el habitat y así agregar el animal al habitat correspondiente
void segundaOpcion(habitat *pAnimales, zoologico *pZoologico){
>>>>>>> af80c4b4186192fbcd2e9f1edb26383c49918029
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
<<<<<<< HEAD
    string aHabitat;
    cout << "Indique el habitat del Animal" << endl;
    cin >> aHabitat;
    cout << "Indique el id del animal" << endl;
    cin >> idAnimal;
    pZoologico->buscarAnimal(idAnimal, aHabitat, opcion);
=======
    cout << "Escribe el id del animal al que quisieras ver su informacion:"<<endl;
    cin>>idAnimal;
    pAnimales->mostrarInfo(idAnimal);
}

// Este metodo nos ayuda para agregar comida al vector de tipoAlimentacion,
// y así saber que come cada animal de acuerdo su alimentación.
void cuartaOpcion(zoologico *pDieta, habitat *pAnimales) {
    string tipoDieta, tipoAlimentacion;
    int id;
    cout << "Escribe el id del animal para agregar una dieta" << endl;
    cin >> id;
    if(pAnimales->recorrerVectorAnimales(id) == id){
        pAnimales->mostrarInfo(id);
        cout << "Escribe el tipo de alimentacion del animal:" << endl;
        cin >> tipoAlimentacion;
        pDieta->mostrarArreglo(tipoAlimentacion);
        cout << "Escribe la comida que le quieras agregar" << endl;
        getline(cin >> std::ws, tipoDieta);
        pDieta->agregarComida(id, tipoDieta,tipoAlimentacion);
    }else{
        cout << "No existe este id en el zoologico"<<endl;
    }

}

// En este metodo se recorre primero el vector animal para ver si concuerda con el id introducido al principio y después
// se debe escoger entre modificar o eliminar alguna comida del vector.
void quintaOpcion(zoologico *pDieta, habitat *pAnimales){
    int id, respuesta;
    string comidaAgregar, comidaModificar, comidaEliminar,tipoAlimentacion;
    cout << "Escribe el id del animal para modificar una dieta" << endl;
    cin >> id;
    if(pAnimales->recorrerVectorAnimales(id) == id){
        cout << "En este caso quieres modificar la dieta o eliminar una dieta?" << endl;
        cout << "1. Modificar" << endl;
        cout << "2. Eliminar" << endl;
        cin>>respuesta;
        if(respuesta == 1){
            cout << "Esta es la informacion de los animales que tienen dieta" << endl;
            pDieta->mostrarInfo(id);
            cout << "Escribe el tipo de alimentacion del animal" << endl;
            cin>>tipoAlimentacion;
            cout << "Escribe la comida que quieras modificar" << endl;
            cin>>comidaModificar;
            pDieta->mostrarArreglo(tipoAlimentacion);
            cout << "Ahora escribe la comida que quieras agregar de acuerdo a la lista" << endl;
            cin>>comidaAgregar;
            pDieta->cambiarComida(id,comidaModificar,comidaAgregar);
        }else{
            cout << "Esta es la informacion de los animales que tienen dieta" << endl;
            pDieta->mostrarInfo(id);
            cout << "Escribe la comida que quieras eliminar" << endl;
            cin>>comidaEliminar;
            pDieta->eliminarComida(id,comidaEliminar);
        }
    }else{
        cout << "No existe este id en el zoologico"<<endl;
    }

}

// El metodo ayuda a mostrar la información de cada animal que tenga una dieta establecida
void mostrarInfoDieta(zoologico *pDieta){
    int idAnimal;
    cout << "Escribe el id del animal al que quisieras ver su informacion de la comida:"<<endl;
    cin>>idAnimal;
    pDieta->mostrarInfo(idAnimal);
}

// En proceso...
void septimaOpcion(animales *pAccion, habitat *pAnimales){
    int id;
    string accionAnimal;
    cout << "A cual animal quisieras hacerle una accion? Escribe su ID de acuerdo a la lista de la opcion 3 del menu: "<<endl;
    cin>>id;
    pAnimales->mostrarInfo(id);
    cout << "Escribe la accion que quisieras hacer?"<<endl;
    cout << "Comer, dormir o jugar"<<endl;
    cin>> accionAnimal;
    if(accionAnimal == "comer" || accionAnimal == "Comer"){
    }
>>>>>>> af80c4b4186192fbcd2e9f1edb26383c49918029
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
<<<<<<< HEAD
                opcionAuxiliar(pZoologico, 7);
                break;
            case 8:
                cout << "\t----EXIT----\n";
                cout << "Vuelva pronto!";
=======
>>>>>>> af80c4b4186192fbcd2e9f1edb26383c49918029
                break;
            default:
                cout << "Opcion invalida!\n";
                break;
        }
    } while (opc != 0);
}

int main() {
    zoologico *pZoologico = new zoologico("Zoologico");
<<<<<<< HEAD
    mostrarMenu(pZoologico);
=======
    animales *pAnimal = new animales("Animales");
    habitat *pHabitat = new habitat("Habitats");
    mostrarMenu(pZoologico,pHabitat,pAnimal);
>>>>>>> af80c4b4186192fbcd2e9f1edb26383c49918029
}