#include <iostream>
#include "zoologico.h"
#include "animales.h"
#include "habitat.h"


// Metodo para poder realizar la agregación del habitat. Sirve para poder llamarlo en el menu y así facilmente
// llamar al otro metodo para que agregue el habitat.
void primeraOpcion(zoologico *pHabitat){
    string tipoHabitat;
    cout<<"Escriba el habitat que desea agregar: "<<endl;
    cin>>tipoHabitat;
    pHabitat->agregarZoologico(tipoHabitat);
}
// El metodo sirve para poder realizar la agregación de los animales. Se pregunta de una vez todas las caracteristicas del animal, y
// se recorre el vector habitat para saber si existe el habitat y así agregar el animal al habitat correspondiente
void segundaOpcion(habitat *pAnimales, zoologico *pZoologico){
    string nombre, especie, tipoHabitat,tipoAlimentacion, estadoSalud;
    int edad,id;
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
    if(pZoologico->recorrerVectorHabitat(tipoHabitat) == tipoHabitat){
        pAnimales->agregarZoologico(id,nombre,especie,tipoHabitat,edad,tipoAlimentacion,estadoSalud);
    }
    else{
        cout <<"El animal no pertenece a este tipo de habitat"<<endl;
    }


}
// Este metodo nos ayuda a ver detalladamente la información de cada animal del zoologico.
void mostrarInfoAnimales(habitat *pAnimales){
    int idAnimal;
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
}

// Se muestra el menu y se llaman los metodos.
void mostrarMenu(zoologico *pZoologico, habitat *pHabitat, animales *pAnimales) {
    int opc = 0, respuesta;
    string tipoDieta;
    do
    {
        cout << "\n**** Bienvenido al Zoologico de Cali ****\n";
        cout << "1. Agregar habitat al zoologico\n";
        cout << "2. Agregar un animal al zoologico\n";
        cout << "3. Ver lista de animales del zoologico\n";
        cout << "4. Agregar dieta al animal seleccionado\n";
        cout << "5. Editar las dietas de los animales\n";
        cout << "6. Ver lista de comidas\n";
        cout << "7. Realizar una accion con el animal\n";
        cout << "0. Salir\n" << endl;
        cin >> opc;
        switch (opc) {
            case 1:
                primeraOpcion(pZoologico);
                break;
            case 2:
                segundaOpcion(pHabitat, pZoologico);
                break;
            case 3:
                pZoologico->mostrarInfo();
                mostrarInfoAnimales(pHabitat);
                do{
                    cout << "Quisieras ver informacion de otro animal?"<<endl;
                    cout << "1. Si"<<endl;
                    cout << "2. No"<<endl;
                    cin>>respuesta;
                    if(respuesta == 1){
                        mostrarInfoAnimales(pHabitat);
                    }else{
                        cout << "Ya viste la informacion de los animales, vuelves al menu"<<endl;
                    }
                }while(respuesta != 2);
                break;
            case 4:
                cuartaOpcion(pZoologico,pHabitat);
                do{
                    cout << "Quisieras agregar comida a otro animal?"<<endl;
                    cout << "1. Si"<<endl;
                    cout << "2. No"<<endl;
                    cin>>respuesta;
                    if(respuesta == 1){
                        cuartaOpcion(pZoologico,pHabitat);
                    }else{
                        cout << "Ya agregaste la comida a los animales, vuelves al menu"<<endl;
                    }
                }while(respuesta != 2);
                break;
            case 5:
                quintaOpcion(pZoologico, pHabitat);
                break;
            case 6:
                mostrarInfoDieta(pZoologico);
                do{
                    cout << "Quisieras ver informacion de otro animal?"<<endl;
                    cout << "1. Si"<<endl;
                    cout << "2. No"<<endl;
                    cin>>respuesta;
                    if(respuesta == 1){
                        mostrarInfoDieta(pZoologico);
                    }else{
                        cout << "Ya viste la informacion de los animales, vuelves al menu"<<endl;
                    }
                }while(respuesta != 2);
                break;
            case 7:
                break;
            default:
                break;
        }
    } while (opc != 0);
}

int main() {
    zoologico *pZoologico = new zoologico("Zoologico");
    animales *pAnimal = new animales("Animales");
    habitat *pHabitat = new habitat("Habitats");
    mostrarMenu(pZoologico,pHabitat,pAnimal);
}