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

#include "algorithms.h"
#include "hash.h"
#include "reverse_validation.h"

using namespace std;

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
    Graph g;
    g.loadGraphMat("rutas.txt", 10, 10);
    g.loadGraphList("rutas.txt", 10, 10);
    
    HashTable<string, int> hash(20, string("empty"), myHash);

   
    while(continua){
        string nombre;
        string start;
        string destino;
        string ruta;
        int pasaporte;

        cout<<"\nMENU"<<endl;
        cout<<"=========\n";
        cout<<"1. Ver lista de Vuelos"<<endl;
        cout<<"2. Buscar Ruta Aventurera"<<endl;
        cout<<"3. Buscar Ruta Rapida"<<endl;
        cout<<"4. Comprar Boleto"<<endl;
        cout<<"5. Opcion Exclusiva para Administrador"<<endl;
        cout<<"6. Exit"<<endl;
        cin>>resp;

        if (resp == 1){
            cout<<g.printAdjMat_clean();

        } else if (resp == 2){
            cout<<"Ingesa el pais de donde sales (ejemplo: MEX):  "<<endl;
            cin>>start;
            cout<<"Ingresa el pais de destino (ejemplo: ESA): "<<endl;
            cin>>destino;
            cout<<g.DFS(reverse_validation(start), reverse_validation(destino));

        } else if (resp == 3){
            cout<<"Ingesa el pais de donde sales (ejemplo: MEX):  "<<endl;
            cin>>start;
            cout<<"Ingresa el pais de destino (ejemplo: ESA): "<<endl;
            cin>>destino;
            g.printShortestDistance(reverse_validation(start), reverse_validation(destino), 10);

        } else if (resp == 4){
            cout<<"Ingresa el nombre del pasajero: "<<endl;
            cin>>nombre;
            cout<<"Ingesa el pais de donde sales (ejemplo: MEX):  "<<endl;
            cin>>start;
            cout<<"Ingresa el pais de destino (ejemplo: ESA): "<<endl;
            cin>>destino;
            cout<<"Desea la Ruta Rapida (1) o la Ruta Aventurera (2)"<<endl;
            cin>>resp;
            cout<<"Ingresa tu numero de pasaporte: "<<endl;
            cin>>pasaporte;
            hash.put(string(nombre), pasaporte);
            if (resp == 1){
                ruta = "Rapida";
                cout<<"La Ruta de tu viaje sera la siguiente: "<<endl;
                g.printShortestDistance(reverse_validation(start), reverse_validation(destino), 10);
            } else if (resp == 2){
                ruta = "Aventurera";
                cout<<g.DFS(reverse_validation(start), reverse_validation(destino));
            }
            write_to_file(nombre, start, destino, ruta);
            cout<<"\nPasaje Comprado Exitosamente"<<endl;

        } else if (resp == 5){
            cout<<"Para esta opcion debes ser un administrador, ingresa contrasenia de administrador (contrasenia: 123456): "<<endl;
            cin>> resp;
            if (resp == 123456){
                cout<<"\nMenu de Administrador"<<endl;
                cout<<"1. Ver Pasaporte de pasajero"<<endl;
                cout<<"2. Ver Tabla de Pasajeros y sus Pasaportes"<<endl;
                cin>> resp;
                if(resp == 1){
                    cout<<"Ingresa el nombre del pasajero: "<<endl;
                    cin>> nombre;
                    cout<<hash.get(nombre);
                } else if (resp == 2){
                    cout<<hash.toString();
                }
            } else if (resp != 123456){
                cout<<"Contrasenia Incorrecta";
            }
        } else if (resp == 6){
            break;
        }
    }
    

    return 0;
}




