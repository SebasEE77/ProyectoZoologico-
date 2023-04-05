//
// Created by sebat on 4/04/2023.
//

#include "AccionAnimal.h"
#include "dieta.h"
AccionAnimal::AccionAnimal(string comer, string dormir, string jugar, int numHorasDormir,int accionAnimal) {
    this->comer = comer;
    this->dormir = dormir;
    this->jugar = jugar;
    this->numHorasDormir = numHorasDormir;
    this->accionAnimal = accionAnimal;
}

void animales::accionDelAnimal(int idAnimal, int accionAnimal, string tipoDieta) {
    vector<zoologico*>::iterator itVectorAnimales;
    vector<animales*>::iterator itVectordieta;
    string comida;
    this->vectorCarnivoro.push_back(new dieta(tipoDieta));
    for(itVectorAnimales = this->vectorAnimales.begin(); itVectorAnimales != this->vectorAnimales.end(); ++itVectorAnimales) {
        zoologico *pAnimales = *itVectorAnimales;
        cout <<"holaaaa"<<endl;
        if(idAnimal == pAnimales->getIdAnimal()){
            if(accionAnimal == 1 and pAnimales->getTipoAlimentacion() == "carnivoro"){
                cout << "Esta es la comida que puede comer: "<<endl;
                for (itVectordieta = this->vectorCarnivoro.begin(); itVectordieta != this->vectorCarnivoro.end(); ++itVectordieta) {
                    animales *pDieta = *itVectordieta;
                    cout << "Dieta: "<<pDieta->getTipoDieta()<<endl;
                }
                cout << "Que comida le quisieras dar?"<<endl;
                cin>>comida;
                if(comida == getTipoDieta()){
                    cout << "Ya le diste la comida"<<endl;
                }else{
                    cout << "El animal no come ese tipo de comida"<<endl;
                }
            }
        }else{
            cout<< "No hay ningun animal con ese ID"<<endl;
        }
    }


}
