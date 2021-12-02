<h1>CORRECIONES</h1>
<li>SICT0302B Toma descisiones</li><br>
El programa ya compila, tiene los archivos correctos para compilar. <br>
-> Y hace uso de grafos para el analisis de información. (Para ver conexiones de vuelos).<br>
-> Y usa un algoritmo de búsqueda en grafos para resolver un problema. (Para buscar la ruta que el usuario desea tomar).
<br></br>
<li>SICT0303B Implementa acciones cientificas</li><br>
-> El programa implementa lectura y escritura de archivos.
<br></br>
<h1>Sistema de Vuelos Internacionales</h1>

Este proyecto se basa en un sistema en el que se tiene una serie de aeropuertos, se hace uso de grafos para poder mapear de donde a donde es posible viajar. Es decir desde que aeropuerto se puede llegar a que otro aeropueerto. De la misma manera el usuario puede hacer una busqueda para ver dos tipos de rutas a su destino. La Ruta aventurera que le da la mayor cantidad de pais que puede visitar en su viaje. Y la Ruta Rapida, la cual le da el camino mas corto a su destino.<br>
El usuario puede hacer la compra de un boleto, al hacer la compra su ticket se escribe en el archivo titulado como "tickets.h". Este proyecto tiene una seccion para un administrador del vuelo, en donde puede ver los pasajeros que han comprado un boleto. El administrador puede ver el nombre de la persona y su numero de pasaporte a traves de una tabla hash. De la misma manera el usuario al comprar un boleto puede seleccionar el asiento que desea ocupar durante el vuelo. Los asientos disponibles estan siendo manejados a traves de la estructura de sets. En donde al comprar un boleto, se hace la operacion de erase() en el set para borrar ese asiento de la lista de asientos disponibles. 

<h2>SEG0702A Tecnologias de Vanguardia </h2>
Se hace uso de la estructura de Sets, la cual no se vio durante el curso. <br>
El usuario al comprar un boleto puede seleccionar el asiento que desea ocupar durante el vuelo. Los asientos disponibles estan siendo manejados a traves de la estructura de sets. Al principio del programa se hace uso de la funcion de insert() para poder insertar en el set los asientos que estan disponibles. Luego a traves de un iterador, se le muestra a el usuario los asientos disponibles que estan en el set. Luego el usuario elige el asiento que desea comprar, y se hace la operacion de erase() en el set para borrar ese asiento de la lista de asientos disponibles. Asi cuando se quiera comprar otro boleto, el set de asientos disponibles ya no va a tener ese asiento disponible, porque fue borrado del set. A continuacion se muestra un ejemplo de esta operacion.<br>
![image](https://user-images.githubusercontent.com/83652905/144356187-cb178e3c-9fbb-4b35-8931-de3c2d5ecb15.png)
Ahora al querer comprar otro boleto, el asiento 17 ya no esta en el set. 
![image](https://user-images.githubusercontent.com/83652905/144356100-fd9c8130-86f7-4504-919a-2f052237859b.png)


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

<li>put()</li>
El Analisis de Complejidad de este algoritmo seria de O(n) en el peor de los casos, ya que se podrian encontrar varias colisiones. Entonces se tendria que tomar en cuenta el tamanio de la lista.
<br></br>

<li>set.insert()</li>
El Analisis de Complejidad de este algoritmo seria de O(log n) en el peor de los casos, esto se debe a que el set esta implementado en la libreria de c++ como un balaced tree, es por eso que se permite tener un ordern entre los elementos.
<br></br>

<li>set.erase()</li>
El Analisis de Complejidad de este algoritmo es constante cuando se le pasa a la funcion erase() el elemento que se desea borrar del set.
