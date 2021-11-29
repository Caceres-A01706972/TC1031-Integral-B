/*
    Ricardo Andres Caceres Villibord
    A01706972
    Archivo de la Integral B para hacer validacion de numero a pais.
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


string validation(int code){
    stringstream aux;

    if(code == 0){
        aux << "MEX";
        return aux.str();

    } else if (code == 1){
        aux << "BEL";
        return aux.str();

    } else if (code == 2){
        aux << "GUA";
        return aux.str();

    } else if (code == 3){
        aux << "ESA";
        return aux.str();

    } else if (code == 4){
        aux << "HON";
        return aux.str();

    } else if (code == 5){
        aux << "NIC";
        return aux.str();

    } else if (code == 6){
        aux << "CRC";
        return aux.str();

    } else if (code == 7){
        aux << "PAN";
        return aux.str();

    } else if (code == 8){
        aux << "COL";
        return aux.str();

    } else if (code == 9){
        aux << "VEN";
        return aux.str();

    } else if (code == 10){
        aux << "ECU";
        return aux.str();

    }

}






/*

(0, 8)
(0, 6)
(0, 7)
(0, 10)

(1, 7)

(2, 7)
(2, 6)

(3, 6)
(3, 4)
(3, 5)
(3, 8)

(4, 7)
(4, 3)

(5, 7)
(5, 3)

(6, 2)
(6, 0)
(6, 3)

(7, 0)
(7, 2)
(7, 1)
(7, 5)
(7, 4)
(7, 3)

(8, 0)
(8, 9)
(8, 10)

(9, 8)

(10, 8)
(10, 0)
*/