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

// Este metodo verificar que la comida que se pase como parametro este dentro de la opciones de dieta tambien de carnivoro, herbivoro y omnivoro.
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
//Este metodo se encarga solo de meter la comida dentro del vector comidas del animal.
void animales::agregarComida(string comida){
    vectorDieta.push_back(comida);
    cout << "Se agregó la comida!\n";
}

//Este metodo se encarga de lo relacionado a cambiar la dieta del animal, por eso se recibe como parametro
// una comida y esta accion que significa si se quiere cambiar o eliminar de la dieta.
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

// Este metodo se encarga de mostrar las comidas dentro del vectorComida del animal.
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

// Este metodo se encarga de mostrar las posible comidas para el animal de acuerdo a su dieta.
void animales::mostrarDietasDisponoble(string dieta) {
    cout<<"\t->Para el animal esta disponible la siguiente dieta<-" << endl;
    if(dieta == "carnivoro" or dieta == "Carnivoro"){
        for(int i = 0; i < 6;i++){
            cout<<"-"<<arregloCarnivoro[i]<<endl;
        }
    }
    else if(dieta == "Herbivoro" or dieta == "herbivoro"){
        for(int i = 0; i < 6;i++){
            cout<<"-"<<arregloHerbivoro[i]<<endl;
        }
    }
    else{
        for(int i = 0; i < 6;i++){
            cout<<"-"<<arregloOmnivoros[i]<<endl;
        }
    }
}

//Este metodo es el que se encarga de que el usuario interactue con animal con un juego de adivinar un numero.
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
    if(intentos == 0){
        cout << "El animal esta triste, no ganaste" << endl;
    }
}

// Este metodo se encarga de mandar al animal a dormir si se especifica el numero de horas exacta.
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
            setEstadoActivo(0);
        }
    }while(horas != this->horasDormir);
}

// Este metodo se encarga de darle de comer al animal.
void animales::comer(){
    string comida;
    if(vectorDieta.size() != 0){
        mostrarDietaAnimal();
     //   cout << "\tDieta del animal " << this->nombre << endl;
       // for(int i = 0; i < vectorDieta.size(); i++){
          //  cout << vectorDieta[i] << endl;
        //}
        cout << "Ahora elige una comida para el animal: ";
        cin >> comida;
        cout << "-------------" << endl;
        cout << "yummmmm " << this->nombre << " ha comido, te lo agredece mucho" << endl;
    }
    else{
        cout << "Lo sentimos pero no puedes alimentar al animal en este momento" << endl;
    }
}