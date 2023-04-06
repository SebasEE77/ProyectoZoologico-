#include <iostream>
#include "zoologico.h"
#include "animales.h"
#include "dieta.h"
#include "habitat.h"


// El metodo para poder realizar la agregación del habitat.
void primeraOpcion(zoologico *pHabitat){
    string tipoHabitat;
    cout<<"Escriba el habitat que desea agregar: "<<endl;
    cin>>tipoHabitat;
    pHabitat->agregarZoologico(tipoHabitat);
}
// El metodo sirve para poder realizar la agregación de los animales. Se pregunta de una vez todas las caracteristicas del animal y los
// ifs sirven para confirmar que el usuario escogió bien el tipo de habitat del animal, ya que podra suceder que un animal sea asignado
// a un habitat incoherente.
void segundaOpcion(habitat *pAnimales){
    string nombre, especie, tipoHabitat,tipoAlimentacion, estadoSalud;
    int edad, tipoDesertico, tipoAcuatico, tipoPolar, tipoSelvatico,id;
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
    if(tipoHabitat == "desertico" || tipoHabitat == "Desertico"){
        cout << "El animal pertenece al desierto?"<<endl;
        cout << "1. Si"<<endl;
        cout << "2. No"<<endl;
        cin>>tipoDesertico;
        if(tipoDesertico == 1){
            pAnimales->agregarZoologico(id,nombre,especie,tipoHabitat,edad,tipoAlimentacion,estadoSalud);
        }
        else{
            cout <<"El animal no pertenece a este tipo de habitat"<<endl;
        }
    }
    else if(tipoHabitat == "acuatico" || tipoHabitat == "Acuatico") {
        cout << "El animal respira en el agua?" << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cin >> tipoAcuatico;
        if (tipoAcuatico == 1) {
            pAnimales->agregarZoologico(id,nombre, especie, tipoHabitat, edad, tipoAlimentacion, estadoSalud);
        } else {
            cout << "El animal no pertenece a este tipo de habitat" << endl;
        }
    }
    else if(tipoHabitat == "selvatico" || tipoHabitat == "Selvatico") {
        cout << "El animal vive en la selva?" << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cin >> tipoSelvatico;
        if (tipoSelvatico == 1) {
            pAnimales->agregarZoologico(id,nombre, especie, tipoHabitat, edad, tipoAlimentacion, estadoSalud);
        } else {
            cout << "El animal no pertenece a este tipo de habitat" << endl;
        }
    }
    else if(tipoHabitat == "polar" || tipoHabitat == "Polar") {
        cout << "El animal soporta extremas bajas temperaturas?" << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cin >> tipoPolar;
        if (tipoPolar == 1) {
            pAnimales->agregarZoologico(id,nombre, especie, tipoHabitat, edad, tipoAlimentacion, estadoSalud);
        } else {
            cout << "El animal no pertenece a este tipo de habitat" << endl;
        }
    }
}
// Este metodo nos ayuda a ver detalladamente la información de cada animal del zoologico.
void mostrarInfoAnimales(habitat *pAnimales){
    int idAnimal;
    cout << "Escribe el id del animal al que quisieras ver su informacion:"<<endl;
    cin>>idAnimal;
    pAnimales->mostrarInfo(idAnimal);
}

// Este metodo nos ayuda pra agregar comida al vector de tipoAlimentacion,
// para así saber que come cada animal de acuerdo su alimentación.
void cuartaOpcion(animales *pDieta) {
    string tipoDieta, tipoAlimentacion;
    int id;
    cout << "Escribe el id del animal para agregar una dieta" << endl;
    cin >> id;
    cout << "Escribe el tipo de alimentacion del animal:" << endl;
    cin >> tipoAlimentacion;
    if (tipoAlimentacion == "Carnivoro" || tipoAlimentacion == "carnivoro") {
        cout << "Esta es la dieta que puede comer: " << endl;
        cout << "Carne" << endl << "Pescado" << endl << "Pechuga" << endl << "Gusanos" << endl << "Ave" << endl
             << "Huevos" << endl;
        cout << "Escribe la comida que le quieras agregar" << endl;
        getline(cin >> std::ws, tipoDieta);
        pDieta->agregarComida(id, tipoDieta);
    }
    else if(tipoAlimentacion == "Herbivoro" || tipoAlimentacion == "herbivoro") {
        cout << "Esta es la dieta que puede comer: " << endl;
        cout << "Hierbas" << endl << "Hojas" << endl << "Savia" << endl << "Raices" << endl << "Semillas" << endl
             << "Flores" << endl;
        cout << "Escribe la comida que le quieras agregar" << endl;
        getline(cin >> std::ws, tipoDieta);
        pDieta->agregarComida(id, tipoDieta);
    }
    else if(tipoAlimentacion == "Omnivoro" || tipoAlimentacion == "omnivoro") {
        cout << "Esta es la dieta que puede comer: " << endl;
        cout << "Carne" << endl << "Frutas" << endl << "Vegetales" << endl << "Plantas" << endl << "Pescado" << endl
             << "Verduras" << endl;
        cout << "Escribe la comida que le quieras agregar" << endl;
        getline(cin >> std::ws, tipoDieta);
        pDieta->agregarComida(id, tipoDieta);
    }
}

void quintaOpcion(animales *pAnimales){
    int id;
    cout << "Escribe el id del animal para agregar una dieta" << endl;
    cin >> id;
}



//void sextaOpcion(animales *pAccion){
//    int id,accionAnimal;
//    string tipoDieta;
//    cout << "A cual animal quisieras hacerle una accion? Escribe su ID de acuerdo a la lista de la opcion 3: "<<endl;
//    cin>>id;
//    cout << "Que accion quisieras hacer?"<<endl;
//    cout << "1. Comer"<<endl;
//    cout << "2. dormir"<<endl;
//    cout << "3. jugar"<<endl;
//    cin>>accionAnimal;
//    pAccion->accionDelAnimal(id,accionAnimal);
//}

// Se muestra el menu y se llaman los metodos.
void mostrarMenu(zoologico *pZoologico, habitat *pHabitat, animales *pAnimales) {
    dieta *pDieta;
    int opc = 0, respuesta;
    do
    {
        cout << "\n**** Bienvenido al Zoologico de Cali ****\n";
        cout << "1. Agregar habitat al zoologico\n";
        cout << "2. Agregar un animal al zoologico\n";
        cout << "3. Ver lista de animales del zoologico\n";
        cout << "4. Agregar dieta al animal seleccionado\n";
        cout << "5. Editar las dietas de los animales\n";
        cout << "6. Ver lista de comidas\n";
        cout << "0. Salir\n" << endl;
        cin >> opc;
        switch (opc) {
            case 1:
                primeraOpcion(pZoologico);
                break;
            case 2:
                segundaOpcion(pHabitat);
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
                cuartaOpcion(pAnimales);
                do{
                    cout << "Quisieras agregar comida a otro animal?"<<endl;
                    cout << "1. Si"<<endl;
                    cout << "2. No"<<endl;
                    cin>>respuesta;
                    if(respuesta == 1){
                        cuartaOpcion(pAnimales);
                    }else{
                        cout << "Ya agregaste la comida a los animales, vuelves al menu"<<endl;
                    }
                }while(respuesta != 2);
                break;
            case 5:
                break;
            case 6:
                pAnimales->mostrarInfoDieta();
                break;
            default:
                break;
        }
    } while (opc != 0);
}

int main() {
    zoologico *pZoologico = new zoologico("Zoologico");
    animales *pAnimales = new animales("Animales");
    habitat *pHabitat = new habitat("Habitats");
    mostrarMenu(pZoologico,pHabitat,pAnimales);
}