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

//void animales::accionDelAnimal(int idAnimal, int accionAnimal) {
//    vector<zoologico*>::iterator itVectorAnimal;
//    vector<animales*>::iterator itVectordieta;
//    string comida;
//    for (itVectorAnimal = this->vectorAnimales.begin(); itVectorAnimal != this->vectorAnimales.end(); ++itVectorAnimal) {
//        zoologico *pAnimales = *itVectorAnimal;
//        if (idAnimal == pAnimales->getIdAnimal()) {
//            if (accionAnimal == 1 and pAnimales->getTipoAlimentacion() == "carnivoro") {
//                cout << "Esta es la comida que puede comer: " << endl;
//                for (itVectordieta = this->vectorCarnivoro.begin();
//                     itVectordieta != this->vectorCarnivoro.end(); ++itVectordieta) {
//                    animales *pDieta = *itVectordieta;
//                    cout << "Dieta: " << pDieta->getTipoDieta() << endl << endl;
//                    cout << "Que comida le quisieras dar?" << endl;
//                    cin >> comida;
//                    if (comida == pDieta->getTipoDieta()) {
//                        cout << "Ya le diste " << comida << endl;
//                    } else {
//                        cout << "El animal no come ese tipo de comida" << endl;
//                    }
//                }
//            }
//        } else {
//            cout << "No hay ningun animal con ese ID" << endl;
//        }
//    }
//}
