#ifndef EXPERIMENTO_HH
#define EXPERIMENTO_HH

#include "grafo.hh"

using namespace std;
class Experimento
{

    public:
        
        Experimento();

        /** Realiza el experimento de percolación de Aristas o Nodos para grafos en cuadrícula
         * @param profundidad Nos indica cuantas veces vamos a repetir el experimento para cada indice de probabilidad
         * @param D Las dimensiones del grafo
         * @param A Indica si es percolación de aristas (true) o de nodos (false)
         * @param nodos Lista de valores que indican de cuantos nodos de lado vamos a realizar el experimento
        */
        static void experimentoNxN(int profundidad, int D, bool A, vector<int> nodos);

        /** Realiza el experimento de percolación de Aristas para grafos geométricos
         * @param N Se estudiaran grafos de N nodos
         * @param profundidad Nos indica cuantas veces vamos a repetir el experimento para cada indice de probabilidad
        */
        static void experimentoAristasG(int N, int profundidad);

};

#endif