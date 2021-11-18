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

using namespace std;

int main(){

    bool continua = true;
    int resp;

    int num_countries = 11;
    Graph g(num_countries);

    g.addEdgeAdjMatrix(0,8);
    g.addEdgeAdjMatrix(0,6);
    g.addEdgeAdjMatrix(0,7);
    g.addEdgeAdjMatrix(0,10);

    g.addEdgeAdjMatrix(1,7);

    g.addEdgeAdjMatrix(2, 7);
    g.addEdgeAdjMatrix(2,6);

    g.addEdgeAdjMatrix(3, 6);
    g.addEdgeAdjMatrix(3, 4);
    g.addEdgeAdjMatrix(3, 5);
    g.addEdgeAdjMatrix(3, 8);

    g.addEdgeAdjMatrix(4, 7);
    g.addEdgeAdjMatrix(4,3);

    g.addEdgeAdjMatrix(5,7);
    g.addEdgeAdjMatrix(5,3);

    g.addEdgeAdjMatrix(6,2);
    g.addEdgeAdjMatrix(6,0);
    g.addEdgeAdjMatrix(6,3);

    g.addEdgeAdjMatrix(7,0);
    g.addEdgeAdjMatrix(7,2);
    g.addEdgeAdjMatrix(7,1);
    g.addEdgeAdjMatrix(7,5);
    g.addEdgeAdjMatrix(7,4);
    g.addEdgeAdjMatrix(7,3);

    g.addEdgeAdjMatrix(8,0);
    g.addEdgeAdjMatrix(8,9);
    g.addEdgeAdjMatrix(8,10);

    g.addEdgeAdjMatrix(9,8);

    g.addEdgeAdjMatrix(10,8);
    g.addEdgeAdjMatrix(10,0);

    while(continua){

        cout<<"\nMENU"<<endl;
        cout<<"=========\n";
        cout<<"1. Ver lista de Vuelos"<<endl;
        cout<<"2. Exit"<<endl;
        cin>>resp;

        if (resp == 1){
            cout<<g.printAdjMat_clean();
        } else if (resp == 2){
            break;
        }
    }


    return 0;
}



 /*
    char text[200];

    fstream file;
    file.open("example.txt", ios::out | ios::in);

    cout<<"Write text to be written: "<<endl;
    cin.getline(text, sizeof(text));
    file<<text<<endl;

    return 0;

}*/

