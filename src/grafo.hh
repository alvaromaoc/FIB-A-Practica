#ifndef GRAFO_HH
#define GRAFO_HH

#include <vector>
#include <random>
#include <iostream>

using namespace std;
class Grafo
{

    private:

        /** Tabla de posiciones cartesianas */
        vector< pair<double,double> > tabla;

        /** Identifica para cada grafo a que componente conexa pertenece */
        vector<int> id;

        /** Identifica para cada grafo a que profundidad esta en la componente conexa */
        vector<int> sz;

        /** Contador de componentes conexas */
        int componentesConexas;

        /** Nos indica si dos nodos estan a una distancia menor o igual a la indicada
         * @param i Primer nodo
         * @param j Segundo nodo
         * @param r Distancia máxima
         * 
         * @pre Los dos nodos son nodos que pertenecen al grafo
         * @return Si los dos nodos estan distancia menor o igual a @p r
        */
        bool sonVecinos(double i, double j, double r);

        /** Une dos nodos
         * @param p Primer nodo
         * @param q Segundo nodo
         * 
         * @pre Los dos nodos son nodos que pertenecen al grafo
         * @post Si no lo eran, ahora los grafos pertenecen a la misma componente conexa
        */
        void gUnion(int p, int q);

        /** Devuelve el nodo padre de la componente conexa
         * @param p Nodo a buscar
         * 
         * @pre El nodo pertenece al grafo
         * @return El identificador del nodo padre de la componente conexa
        */
        int gFind(int p);

        /** Indica si dos nodos pertenecen a la misma componente conexa comparando sus padres
         * @param p Primer nodo
         * @param q Segundo nodo
         * 
         * @pre Los dos nodos pertenecen al grafo
         * @return Si pertenecen a la misma componente conexa
        */
        bool gConnected(int p, int q);

        /** Función de potencia de enteros
         * @param b Base
         * @param q Exponente
         * 
         * @return b elevado a e
        */
        int pot(int b, int e);

    public:

        /** Genera un grafo de @p D dimensiones y aplica percolació de aristas o nodos con indice de probabilidad q
         * @param N Cantidad de nodos de lado del grafo
         * @param A Indica si se aplica percolación de aristas (aristas == true) o de nodos (aristas = false)
         * @param q Probabilidad de que una arista o nodo falle en la percolación
         * @param D Dimensiones del grafo
        */
        Grafo(int N, bool A, int q, int D);

        /** Genera un grafo geométrico de N nodos y aplica percolación de aristas con una distancia máxima r y un indice de probabilidad q
         * @param N Cantidad de nodos del grafo
         * @param r Distancia máxima a la que un nodo puede conectarse a otro nodo
         * @param q Probabilidad de que una arista falle en la percolación
        */
        Grafo(int N, double r, int q);

        /** Devuelve el numero de componentes conexas
         * 
         * @return El numero de componentes conexas del grafo
        */
        int getComponentesConexas();

};

#endif