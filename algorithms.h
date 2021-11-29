/*
	Ricardo Andres Caceres Villbord
	A01706972
	Archivo .h para la Integral B
	Este archivo contiene los algoritmos para crear el grafo, hacer busquedas en el grafo,
	leer y escribir en archivos.
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

#include "validation.h"


using namespace std;

void write_to_file(string name, string start, string destino, string ruta){
	ofstream myFile;
	stringstream aux;
	myFile.open("tickets.txt", ios::app);
	aux<< "Pasajero: "<<name<<endl<<"From: "<<start<<endl<<"To: "<<destino<<endl<<"Tipo de Ruta: "<<ruta<<"\n \n";

	myFile<<aux.str();

	myFile.close();
}

class Graph {
private:
		int edgesList;
		int edgesMat;
		int nodes;
    	vector<int> *adjList;
		int *adjMatrix;
		//vector<Type> *vect = new vector<Type>

public:
		void loadGraphMat(string, int, int);
		void loadGraphList(string, int, int);
		Graph(int);
		Graph();
		void addEdgeAdjMatrix(int, int);
		void addEdgeAdjList(int, int);
		string printAdjMat();
		string printAdjMat_clean();
		bool contains(list<int>, int);
		void sortAdjList();

        string printAdjList();
		string DFS(int, int);
		void dfsHelper(int, int, stack<int>&, list<int>&, vector<vector<int>>&, stringstream&);
		void printPath(vector<vector <int>>&, int, int, stringstream&);
		void printVisited(list<int>, stringstream&);

		void printShortestDistance(int s,
                           int dest, int v);
		
		bool BFS(int src, int dest, int v,
         int pred[], int dist[]);
};

bool Graph::contains(list<int> lista, int node) {
    list<int>::iterator it;
    it = find(lista.begin(), lista.end(), node);
    
    if (it != lista.end()){
		return true;
	} else {
		return false;
	}
}

string Graph::DFS(int inicio, int objetivo){
	stringstream aux;

	stack<int>my_stack;
	list<int> visited;
	vector<vector<int>> paths(nodes, vector<int>(1,-1));
	my_stack.push(inicio);

	dfsHelper(inicio, objetivo, my_stack, visited, paths, aux);
    printPath(paths, inicio, objetivo, aux);
    
    return aux.str();
}

void Graph::dfsHelper(int current, int objetivo, stack<int> &my_stack, list<int> &visited, vector<vector<int>> &paths, stringstream &aux) {
    
    if (current == objetivo) {
        printVisited(visited, aux);
    } else if (my_stack.empty()) {
        aux << "node not found";
    } else {
        current = my_stack.top(); //guardo el nodo en que me encuentro (el que esta de primero en el stack)
        my_stack.pop(); //queda vacio el stack
        visited.push_back(current); //meto el current en lista de visited
        for (int  i = 0; i < adjList[current].size(); i++) {
            if (!contains(visited, adjList[current][i])) {
                my_stack.push(adjList[current][i]);
                paths[ adjList[current][i] ] [0] = current;
            }
        }
        dfsHelper(current, objetivo, my_stack, visited, paths, aux);
    }
}

void Graph::printVisited(list<int>visited, stringstream &aux) {
    aux << "visited: ";
    while (!visited.empty()){
        aux << validation(visited.front()) << " ";
        visited.pop_front();
    }
}

void Graph::printPath(vector<vector <int>> &path, int inicio, int objetivo, stringstream &aux) {
    aux << "\nMostrando Runta Aventurera: ";
    int node = path[objetivo][0];
    
    stack<int> reverse; //stack auxiliar
    reverse.push(objetivo);
    
    while (node != inicio) {
        reverse.push(node);
        node = path[node][0];
    }
    
    reverse.push(inicio);
    while (!reverse.empty()) {
        aux << validation(reverse.top());
        reverse.pop();
        if (!reverse.empty())
            aux << " ";
    }
}


void Graph::loadGraphMat(string name, int a, int b){
	adjMatrix = new int [a*b];
	nodes = a;
	for (int i = 0; i < a*b; i++)
		adjMatrix[i] = 0;
		string line;
		ifstream lee (name);
		int u, v;
		if (lee.is_open()){
			while (getline(lee, line)){
				u = stoi(line.substr(1,1));
				v = stoi(line.substr(4,1));
				addEdgeAdjMatrix(u,v);
			}
			lee.close(); // Closes the file
		} else {
			cout << "Unable to open file";
		}
}

void Graph::loadGraphList(string nom_archivo, int a, int b){
	nodes = a;
	adjList = new vector<int>[nodes];

	string line;
	ifstream archivo (nom_archivo);
	int u, v;
	if (archivo.is_open()){
		while (getline(archivo, line)){
			u = stoi(line.substr(1,1));
			v = stoi(line.substr(4,1));
			addEdgeAdjList(u,v);
		}
		archivo.close();
	} else {
		cout<<"Unable to open file";
	}
}

Graph::Graph() {
	edgesList = edgesMat = 0;
}

Graph::Graph(int n) {
	nodes = n;
	adjList = new vector<int>[nodes];
	adjMatrix = new int [nodes*nodes];
	for (int i = 0; i < nodes*nodes; i++)
		adjMatrix[i] = 0;
	edgesList = edgesMat = 0;
}

void Graph::addEdgeAdjMatrix(int u, int v){
	adjMatrix[u*nodes+v] = 1;
	adjMatrix[v*nodes+u] = 1;
	edgesMat++;
    //cout<<"\n Printing the Connections\n";
}

void Graph::addEdgeAdjList(int u, int v){
	adjList[u].push_back(v);
	adjList[v].push_back(u);
	edgesList++;
}

string Graph::printAdjList(){
	  stringstream aux;
		for (int i = 0; i < nodes; i++){
	        aux << "vertex "
	             << i << " :";
	        for (int j = 0; j < adjList[i].size(); j ++){
							 aux << " " << adjList[i][j];
					}
	        aux << " ";
    }
		return aux.str();

}

string Graph::printAdjMat(){
	stringstream aux;
	for (int i = 0; i < nodes; i++){
	   for (int j = 0; j < nodes; j++){
			 aux << adjMatrix[i*nodes+j] << " ";
		 }
  }
	return aux.str();
}

string Graph::printAdjMat_clean(){
	stringstream aux;
	aux << "\n Fights |";
	for (int i = 0; i < nodes; i++){
			aux << "\t" << validation(i) ;
	}
	aux << "\n";
	for (int i = 0; i < nodes; i++){
			aux << "__________";
	}
	aux << "\n";
	for (int i = 0; i < nodes; i++){
		 aux << validation(i) << "\t|";
	   for (int j = 0; j < nodes; j++){
			 aux << "\t" << adjMatrix[i*nodes+j];
		 }
	   aux << "\n";
  }
	return aux.str();
}


// a modified version of BFS that stores predecessor
// of each vertex in array p
// and its distance from source in array d
bool Graph::BFS(int src, int dest, int v,
         int pred[], int dist[])
{
    // a queue to maintain queue of vertices whose
    // adjacency list is to be scanned as per normal
    // DFS algorithm
    list<int> queue;
 
    // boolean array visited[] which stores the
    // information whether ith vertex is reached
    // at least once in the Breadth first search
    bool visited[v];
 
    // initially all vertices are unvisited
    // so v[i] for all i is false
    // and as no path is yet constructed
    // dist[i] for all i set to infinity
    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT8_MAX;
        pred[i] = -1;
    }
 
    // now source is first to be visited and
    // distance from source to itself should be 0
    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);
 
    // standard BFS algorithm
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adjList[u].size(); i++) {
            if (visited[adjList[u][i]] == false) {
                visited[adjList[u][i]] = true;
                dist[adjList[u][i]] = dist[u] + 1;
                pred[adjList[u][i]] = u;
                queue.push_back(adjList[u][i]);
 
                // We stop BFS when we find
                // destination.
                if (adjList[u][i] == dest)
                    return true;
            }
        }
    }
 
    return false;
}
 
// utility function to print the shortest distance
// between source vertex and destination vertex
void Graph::printShortestDistance(int s,
                           int dest, int v)
{
    // predecessor[i] array stores predecessor of
    // i and distance array stores distance of i
    // from s
    int pred[v], dist[v];
 
    if (BFS(s, dest, v, pred, dist) == false) {
        cout << "Given source and destination"
             << " are not connected";
        return;
    }
 
    // vector path stores the shortest path
    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }
 
    // distance from source is in distance array
    cout << "La Ruta Rapida tiene tan solo: "
         << dist[dest]<<" escalas";
 
    // printing path from source to destination
    cout << "\nLa Ruta es::\n";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
}

