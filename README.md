<h1>CORRECIONES</h1>

El programa ya compila, tiene los archivos correctos para compilar.
El programa implementa lectura y escritura de archivos.

<h1>Sistema de Vuelos Internacionales</h1>

Este proyecto se basa en un sistema en el que se tiene una serie de aeropuertos, se hace uso de grafos para poder mapear de donde a donde es posible viajar. Es decir desde que aeropuerto se puede llegar a que otro aeropueerto. De la misma manera el usuario puede hacer una busqueda para ver dos tipos de rutas a su destino. La Ruta aventurera que le da la mayor cantidad de pais que puede visitar en su viaje. Y la Ruta Rapida, la cual le da el camino mas corto a su destino.
Este proyecto tiene una seccion para un administrador del vuelo, en donde puede ver los pasajeros que han comprado un boleto. El administrador puede ver el nombre de la persona y su numero de pasaporte a traves de una tabla hash.

<h2>Analisis de Complejidad</h2>
<li>Graph(n)</li>
El Analisis de Complejidad de este algoritmo es de O(n^2) ya que se debe de crear la matriz de tamaño nodes*nodes y llenarla al principio con 0. 
<br></br>

<li>addEdgeAdjMat()</li>
El Analisis de Complejidad de este algoritmo es de O(1) si las vertices ya fueron creadas anteriormente en el constructor de Graph(n) donde n es el numero de nodos.
<br></br>

<li>DFS()</li>
Para este algoritmo, el analisis de complejidad se tiene que tomar en cuenta la cantidad de vertices y edges que se visitaran. Es por esto que el analisis de complejidad es de O(v) + O(e) donde v es el numero de vertices y e es el numero de edges.
<br></br>

<li>BFS()</li>
Este algoritmo tiene un Analisis de Complejidad es el mismo al del algoritmo de DFS, ya que se tendra que visitar una cierta cantidad de vertices y edges. Es decir, O(v) + O(a).
<br></br>

<li>printShortestDistance()</li>
El Analisis de Complejidad de este algoritmo seria de O(n) en el peor de los casos, ya que esta funcion solo se encarga de ir imprimiendo lo que hay en el arreglo de distancia y de path.
<br></br>

<li>get()</li>
Para este algoritmo, el analisis de complejidad se tiene que tomar en cuenta que podria llegar a tener que recorrer toda la tabla para encontrar el value de key. Por lo que el analisis de complejidad tendria que ser de O(n) en el peor de los casos.
<br></br>
