//
// Created by sebat on 4/04/2023.
//

#include "animales.h"
#include <cstdlib>



// Constructor de la clase animal. Aunque esta clase no tenga los atributos, se pone aquí el constructor por coherencia
animales::animales(int idAnimal, string nombre, string especie, string tipoHabitat, int edad, string tipoAlimentacion,
                   string estadoSalud, int horasDormir, int estadoActivo, int estadoJugar) {
    this->idAnimal = idAnimal;
    this->nombre = nombre;
    this->especie = especie;
    this->tipoHabitat = tipoHabitat;
    this->edad = edad;
    this->tipoAlimentacion = tipoAlimentacion;
    this->estadoSalud = estadoSalud;
    this->horasDormir = horasDormir;
    this->estadoActivo = estadoActivo;
    this->estadoJugar = estadoJugar;
}

// Constructor de animales para comenzar el zoologico, ubicado en el main
<<<<<<< HEAD

=======
animales::animales(string nombreAnimal) {
    this->nombreAnimal = nombreAnimal;
}
>>>>>>> af80c4b4186192fbcd2e9f1edb26383c49918029
// Constructor de la dieta de los animales para así especificamente saber su comida en relación a su tipo de alimentación
// no va mientras

<<<<<<< HEAD
// Constructor de las acciones de los animales para así saber qué es lo que hacen o qué es lo que ya hicieron.



=======
>>>>>>> af80c4b4186192fbcd2e9f1edb26383c49918029




// Desde aqui van los Gets y Sets
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
int animales::getHoras(){
    return horasDormir;
}
int animales::getEstadoActivo(){
    return estadoActivo;
}
int animales::getEstadoJugar(){
    return estadoJugar;
}
void animales::setEstadoActivo(int estadoActivo){
    this->estadoActivo = estadoActivo;
}
void animales::setEstadoJugar(int estadoJugar){
    this->estadoJugar = estadoJugar;
}

int animales::verificarComida(string comida){
    int bandera = 0;
    for(int i = 0; i < 6; i++){
        if(arregloCarnivoro[i] == comida or arregloHerbivoro[i] == comida or arregloOmnivoros[i] == comida){
            bandera = 1;
            return bandera;
        }
    }
    return bandera;

}
void animales::agregarComida(string comida){
    vectorDieta.push_back(comida);
    cout << "Se agregó la comida!\n";
}

void animales::modificarDieta(string accion, string comida){
    string nuevaComida;
    int bandera = 0;
    vector<string>::iterator itComida;
    if(accion == "modificar" || accion == "Modificar"){
        cout << "Ingrese la comida a cambiar por " << comida << ":";
        getline(cin >> std::ws, nuevaComida);
        for(int i = 0; i < vectorDieta.size() && bandera == 0; i++){
            if(vectorDieta[i] == comida) {
                vectorDieta[i] = nuevaComida;
                bandera = 1;
            }
        }
    }
    else if(accion == "eliminar" || accion == "Eliminar"){
        for(itComida = vectorDieta.begin(); itComida != vectorDieta.end() and bandera == 0; itComida++){
            string iComida = *itComida;
            if(iComida == comida) {
               vectorDieta.erase(itComida);
                bandera = 1;
            }
        }
    }
    if(bandera == 0){
        cout << "La comida: " << comida << ", no se encontraba en la dieta" << endl;
    }
    else{
        cout<<"Accion valida!"<<endl;
    }
}

void animales::mostrarDietaAnimal(){
    cout<<"La dieta del animal "<< this->nombre << " y de id " << this->idAnimal<< " es:" << endl;
    if(vectorDieta.size() != 0){
        for(int i = 0; i < vectorDieta.size(); i++){
            cout << vectorDieta[i] << endl;
        }
    }
    else{
        cout << "Por el momento no tiene :(" << endl;
    }
}

void animales::mostrarDietasDisponoble(string dieta) {
    int i = 0;
    cout<<"\t->Para el animal esta disponible la siguiente dieta<-" << endl;
    if(dieta == "carnivoro" or dieta == "Carnivoro"){
        for(i; i < 6;i++){
            cout<<"-"<<arregloCarnivoro[i]<<endl;
        }
    }
    else if(dieta == "Herbivoro" or dieta == "herbivoro"){
        for(i; i < 6;i++){
            cout<<"-"<<arregloHerbivoro[i]<<endl;
        }
    }
    else{
        for(i; i < 6;i++){
            cout<<"-"<<arregloOmnivoros[i]<<endl;
        }
    }
}

void animales::jugar() {
    int num = -1;
    int intentos = 3;
    int aleatorio = rand() % 10 + 1;
    cout << "Hola! Ahora vas a jugar con " << this->nombre << endl;
    cout << "El juego consiste en que adivines un numero entre el 1 y el 10\n";
    cout << "Listo?";
    while(num != aleatorio and intentos > 0){
        cout << "Di tu respuesta: ";
        cin >> num;
        if(num == aleatorio){
            cout << "Has ganado, " << this->nombre << " esta feliz" << endl;
        }
        else{
            cout << "Te has equivocao!" << endl;
            intentos--;
        }
    }
}
void animales::dormir() {
    int horas = -1;
    do{
        cout << "Indica las horas para que el animal duerma: ";
        cin >> horas;
        if(horas > this->horasDormir){
            cout << "Son muchas horas para dormir!\n";
        }
        else if(horas < this->horasDormir){
            cout << "Son pocas horas para dormir\n";
        }
        else{
            cout << "El animal ya duerme tranquilo\n";
        }
    }while(horas != this->horasDormir);
}
void animales::comer(){
    string comida;
    if(vectorDieta.size() != 0){
        cout << "\tDieta del animal " << this->nombre << endl;
        for(int i = 0; i < vectorDieta.size(); i++){
            cout << vectorDieta[i] << endl;
        }
        cout << "Ahora elige una comida para el animal: ";
        cin >> comida;
        cout << "-------------" << endl;
        cout << "yummmmm " << this->nombre << " ha comida, te lo agredece mucho" << endl;
    }
    else{
        cout << "Lo sentimos pero no puedes alimentar al animal en este momento" << endl;
    }
}