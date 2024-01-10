= Grafos I

Resumen:

Definición de grafo: Un concepto matemático que incluye nodos y conexiones entre nodos, llamadas aristas. Los grafos se utilizan para representar relaciones entre objetos, como amistades entre personas, carreteras entre ciudades o comunicación entre individuos que hablan el mismo idioma.
Representación en la Computadora:

*Lista de Adyacencia*: Representación preferida. Cada nodo tiene un vector que almacena sus vecinos.

== Búsqueda en Amplitud (BFS):

BFS se utiliza para calcular la distancia mínima entre nodos y determinar si se puede llegar de un nodo a otro.
\ Algoritmo:
Mantener una lista de adyacencia en el vector G. \
Usar una cola Q para procesar nodos. \
Inicializar el nodo de partida s y el vector de distancias D. \

===  Realizar BFS:

```cpp
Q = queue<int>();
int s = nodo_inicial;
vector<int> D(N, oo);
D[s] = 0;
Q.push(s);
while (!Q.empty()) {
   int u = Q.front();
   Q.pop();
   for (int v : G[u]) {
      if (D[v] == oo) {
         D[v] = D[u] + 1;
         Q.push(v);
      }
   }
}
```

Complejidad: O(n+m) \
Opcionalmente, usar un vector de padres para rastrear los caminos. \

== Búsqueda en Profundidad (DFS):

DFS explora lo más profundo posible a lo largo de cada rama antes de retroceder. \
Algoritmo:
```cpp
vector<int> P(N, -1);
void dfs(int u) {
   for (int v : G[u]) {
      if (P[v] == -1) {
         P[v] = u;
         dfs(v);
      }
   }
}
```
Complejidad: O(n+m) \
\ \ 
== Algoritmo de Dijkstra:

Se utiliza cuando las aristas tienen pesos asociados. \
Algoritmo: \
Crear una cola de prioridad PQ con pares `(-distancia, id)`.
```cpp
priority_queue<pii, vector<pii>, greater<pii>> PQ;
```
Inicializar el vector de distancias D e insertar el nodo de partida.
\
```cpp
vector<int> D(N, INF);
D[s] = 0;
PQ.emplace(0, s);
```

Realizar Dijkstra:
```cpp
while (!PQ.empty()) {
   pii p = PQ.top();
   PQ.pop();
   int d = p.first;
   int u = p.second;
   if (d != D[u]) continue;
   for (pii e : G[u]) {
      int v = e.first, w = e.second;
      if (D[v] > D[u] + w) {
         D[v] = D[u] + w;
         PQ.emplace(D[v], v);
      }
   }
}
```
Complejidad: O((n+m) log(n+m)) \

== Notas:

BFS para distancias mínimas, DFS para exploración y Dijkstra para grafos ponderados.
Las colas de prioridad implican una complejidad logarítmica para la inserción y eliminación.
Dijkstra funciona con pesos de arista no negativos.



