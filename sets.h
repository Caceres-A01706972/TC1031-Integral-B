/*
    Ricardo Andres Caceres Villibord
    A01706972
    Archivo .h para Integral B
    Este archivo contiene una estructura que ni vimos en el curso. 
    La estructura es la de sets.
*/

#include <iostream>
#include <iterator>
#include <set>

using namespace std;
/*
void create_default_seats(set<int, greater<int> > const &seats){
    seats_disponibles.insert(12);
    seats_disponibles.insert(2);
    seats_disponibles.insert(19);
    seats_disponibles.insert(9);
    seats_disponibles.insert(23);
    seats_disponibles.insert(21);
    seats_disponibles.insert(17);
    seats_disponibles.insert(24);
    seats_disponibles.insert(8);
    seats_disponibles.insert(15);

}*/

void create_seats(set<int, greater<int> > &seats_disponibles){
    seats_disponibles.insert(2);
    seats_disponibles.insert(19);
    seats_disponibles.insert(9);
    seats_disponibles.insert(23);
    seats_disponibles.insert(21);
    seats_disponibles.insert(17);
    seats_disponibles.insert(24);
    seats_disponibles.insert(8);
    seats_disponibles.insert(15);
}

void print_asientos(set<int, greater<int> > const &seats){
    set<int, greater<int> >::iterator itr;
    cout << "\n Asientos Disponibles : \n";
    cout<<"---------------------------- Cockpit"<<endl;
    for (itr = seats.begin(); itr != seats.end(); itr++) {
        cout << *itr << " ";
    }
    cout<<"\n---------------------------- Cockpit"<<endl;
    cout << endl;
}

void ocupa_asiento(set<int, greater<int> > &seats_disponibles, int asiento){
    seats_disponibles.erase(asiento);
    cout<<"Se reservo tu asiento correctamente, el asiento ya no estara disponible para otro pasajero.\n"<<endl;
}

