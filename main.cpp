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
#include <iterator>
#include <set>

#include "algorithms.h"
#include "hash.h"
#include "reverse_validation.h"
#include "sets.h"

using namespace std;

//Mi funcion hash 
unsigned int myHash(const string s) {
	unsigned int acum = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		acum += (int) s[i];
	}
	return acum;
}

int main(){

    bool continua = true;
    int resp;
    int asiento;
    Graph g;
    g.loadGraphMat("rutas.txt", 10, 10);
    g.loadGraphList("rutas.txt", 10, 10);
    
    HashTable<string, int> hash(20, string("empty"), myHash);
    set<int, greater<int> > seats_disponibles;
    create_seats(seats_disponibles);
    /*
    seats_disponibles.insert(2);
    seats_disponibles.insert(19);
    seats_disponibles.insert(9);
    seats_disponibles.insert(23);
    seats_disponibles.insert(21);
    seats_disponibles.insert(17);
    seats_disponibles.insert(24);
    seats_disponibles.insert(8);
    seats_disponibles.insert(15);
*/
   
    while(continua){
        string nombre;
        string start;
        string destino;
        string ruta;
        int pasaporte;

        std::cout<<"\nMENU"<<endl;
        std::cout<<"=========\n";
        std::cout<<"1. Ver lista de Vuelos"<<endl;
        std::cout<<"2. Buscar Ruta Aventurera"<<endl;
        std::cout<<"3. Buscar Ruta Rapida"<<endl;
        std::cout<<"4. Comprar Boleto"<<endl;
        std::cout<<"5. Opcion Exclusiva para Administrador"<<endl;
        std::cout<<"6. Exit"<<endl;
        cin>>resp;

        if (resp == 1){
            std::cout<<g.printAdjMat_clean();

        } else if (resp == 2){
            std::cout<<"Ingesa el pais de donde sales (ejemplo: MEX):  "<<endl;
            cin>>start;
            std::cout<<"Ingresa el pais de destino (ejemplo: ESA): "<<endl;
            cin>>destino;
            std::cout<<g.DFS(reverse_validation(start), reverse_validation(destino));

        } else if (resp == 3){
            std::cout<<"Ingesa el pais de donde sales (ejemplo: MEX):  "<<endl;
            cin>>start;
            std::cout<<"Ingresa el pais de destino (ejemplo: ESA): "<<endl;
            cin>>destino;
            g.printShortestDistance(reverse_validation(start), reverse_validation(destino), 10);

        } else if (resp == 4){
            std::cout<<"Ingresa el nombre del pasajero: "<<endl;
            cin>>nombre;
            std::cout<<"Ingesa el pais de donde sales (ejemplo: MEX):  "<<endl;
            cin>>start;
            std::cout<<"Ingresa el pais de destino (ejemplo: ESA): "<<endl;
            cin>>destino;
            std::cout<<"Elige el asiento que deseas comprar: "<<endl;
            print_asientos(seats_disponibles);
            cin>>asiento;
            ocupa_asiento(seats_disponibles, asiento);
            std::cout<<"Ingresa tu numero de pasaporte: "<<endl;
            cin>>pasaporte;
            std::cout<<"Desea la Ruta Rapida (1) o la Ruta Aventurera (2)"<<endl;
            cin>>resp;
            hash.put(string(nombre), pasaporte);
            if (resp == 1){
                ruta = "Rapida";
                std::cout<<"La Ruta de tu viaje sera la siguiente: "<<endl;
                g.printShortestDistance(reverse_validation(start), reverse_validation(destino), 10);
            } else if (resp == 2){
                ruta = "Aventurera";
                std::cout<<g.DFS(reverse_validation(start), reverse_validation(destino));
            }
            write_to_file(nombre, start, destino, ruta);
            std::cout<<"\nPasaje Comprado Exitosamente"<<endl;

        } else if (resp == 5){
            std::cout<<"Para esta opcion debes ser un administrador, ingresa contrasenia de administrador (contrasenia: 123456): "<<endl;
            cin>> resp;
            if (resp == 123456){
                std::cout<<"\nMenu de Administrador"<<endl;
                std::cout<<"1. Ver Pasaporte de pasajero"<<endl;
                std::cout<<"2. Ver Tabla de Pasajeros y sus Pasaportes"<<endl;
                cin>> resp;
                if(resp == 1){
                    std::cout<<"Ingresa el nombre del pasajero: "<<endl;
                    cin>> nombre;
                    std::cout<<hash.get(nombre);
                } else if (resp == 2){
                    std::cout<<hash.toString();
                }
            } else if (resp != 123456){
                std::cout<<"Contrasenia Incorrecta";
            }
        } else if (resp == 6){
            break;
        }
    }
    

    return 0;
}




