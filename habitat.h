//
// Created by sebat on 4/04/2023.
//

#ifndef ZOOLOGICO_HABITAT_H
#define ZOOLOGICO_HABITAT_H
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "zoologico.h"

using std::cout;
using std::string;
using std::endl;
using std::iterator;
using std::cin;
using std::unordered_map;
using std::make_pair;
using std::vector;

class habitat: public zoologico {
public:
    habitat() = default;
    habitat(string tipoHabitat);



};


#endif //ZOOLOGICO_HABITAT_H
