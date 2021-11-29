/*
    Ricardo Andres Caceres Villibord
    A01706972
    Archivo de la Integral B para hacer validacion de pais a numero
*/

#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

int reverse_validation(string country){
    int aux;

    if(country == "MEX"){
        aux = 0;
        return aux;

    } else if (country == "BEL"){
        aux = 1;
        return aux;

    } else if (country == "GUA"){
        aux = 2;
        return aux;

    } else if (country == "ESA"){
        aux = 3;
        return aux;

    } else if (country == "HON"){
        aux = 4;
        return aux;

    } else if (country == "NIC"){
        aux = 5;
        return aux;

    } else if (country == "CRC"){
        aux = 6;
        return aux;

    } else if (country == "PAN"){
        aux = 7;
        return aux;

    } else if (country == "COL"){
        aux = 8;
        return aux;

    } else if (country == "VEN"){
        aux = 9;
        return aux;

    } 

}
