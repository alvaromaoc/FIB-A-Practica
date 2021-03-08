#include "grafo.hh"

Grafo::Grafo(int N, bool A, int q, int D)
{
    int nodos = pot(N,D);
    this->id = vector<int>(nodos); // Inicializamos el vector de nodos padre, cada uno es su propio padre inicialmente
    for (int i = 0;i < nodos;++i) id[i] = i;
    this->sz = vector<int>(nodos,1); // Inicializamos el vector de profundidad, cada uno tiene profundidad 1 inicialmente
    this->componentesConexas = nodos; // Inicializamos las componentes conexas al numero de nodos total
    
    if (!A){ // Comprobamos si es percolación de nodos o aristas
        // Por nodos
        vector<int> activos(nodos,-1); // Nos indicara para cada nodo si ya lo hemos tratado y si lo hemos hecho saber si ha fallado
        for (int i = 0;i < nodos;++i){ // Para cada nodo comprovaremos sus vecinos
            if (activos[i] == -1) activos[i] = rand()%100 > q; // Si no hemos tratado el nodo lo tratamos
            if (activos[i]){ // Comprovamos si el nodo en tratamiento es un nodo que ha fallado
                if (i%N != 0){ // Comprovamos el de su izquierda, si tiene
                    if (activos[i-1] == -1) activos[i-1] = rand()%100 > q; // Si no hemos tratado el nodo lo tratamos
                    if (activos[i-1] && rand()%100 > q) gUnion(i,i-1); // Si no ha fallado los unimos
                }
                if (i%N != N-1){ // Comprovamos el de su derecha, si tiene
                    if (activos[i+1] == -1) activos[i+1] = rand()%100 > q; // Si no hemos tratado el nodo lo tratamos
                    if (activos[i+1] && rand()%100 > q) gUnion(i,i+1); // Si no ha fallado los unimos
                }
                for (int d = 1;d < D;++d){
                    if (i/pot(N,d)%N != 0){ // Comprovamos el contiguo dimensional superior, si tiene
                        if (activos[i-pot(N,d)] == -1) activos[i-pot(N,d)] = rand()%100 > q; // Si no hemos tratado el nodo lo tratamos
                        if (activos[i-pot(N,d)] && rand()%100 > q) gUnion(i,i-pot(N,d)); // Si no ha fallado los unimos
                    }
                    if (i/pot(N,d)%N != N-1){ // Comprovamos el contiguo dimensional inferior, si tiene
                        if (activos[i+pot(N,d)] == -1) activos[i+pot(N,d)] = rand()%100 > q; // Si no hemos tratado el nodo lo tratamos
                        if (activos[i+pot(N,d)] && rand()%100 > q) gUnion(i,i+pot(N,d)); // Si no ha fallado los unimos
                    }
                }
            }else --componentesConexas; // Si es un nodo que ha fallado, es una componente conexa menos
        }
    }else{
        // Por aristas
        for (int i = 0;i < nodos;++i){ // Para cada nodo comprovaremos sus vecinos
            if (i%N != 0 && rand()%100 > q) gUnion(i,i-1); // Si no falla la arista lo unimos con el de su izquierda si tiene
            if (i%N != N-1 && rand()%100 > q) gUnion(i,i+1); // Si no falla la arista lo unimos con el de su derecha si tiene
            for (int d = 1;d < D;++d){
                if (i/pot(N,d)%N != 0 && rand()%100 > q) gUnion(i,i-pot(N,d)); // Si no falla la arista lo unimos con el superior dimensional si tiene
                if (i/pot(N,d)%N != N-1 && rand()%100 > q) gUnion(i,i+pot(N,d)); // Si no falla la arista lo unimos con el inferior dimensional si tiene
            }
        }
    }
}

Grafo::Grafo(int N, double r, int q)
{
    this->id = vector<int>(N); // Inicializamos el vector de nodos padre, cada uno es su propio padre inicialmente
    for (int i = 0;i < N;++i) id[i] = i;
    this->sz = vector<int>(N,1); // Inicializamos el vector de profundidad, cada uno tiene profundidad 1 inicialmente
    this->componentesConexas = N; // Inicializamos las componentes conexas al numero de nodos total
    this->tabla = vector< pair<double,double> >(N); // Inicializamos la estructura de datos que nos servira de tablero de posiciones
    for (int i = 0;i < N;++i){ // Asignamos una posicion aleatoria dentro del tablero a cada nodo
        double h = rand()%101/100;
        double v = rand()%101/100;
        tabla[i] = make_pair(h,v);
    }
    for (int i = 0;i < N;++i){ // Tratamos cada par de nodos
        for (int j = i + 1;j < N;++j){
            if (sonVecinos(i,j,r)){ // Si estan a la distancia mínima
                if (rand()%100 > q) gUnion(i,j); // Miramos si falla la arista, en caso contrario los unimos
            }
        }
    }
}

int Grafo::getComponentesConexas()
{
    return componentesConexas;
}

bool Grafo::sonVecinos(double i, double j, double r)
{
    double distanciaH = tabla[i].first - tabla[j].first;
    double distanciaV = tabla[j].second - tabla[j].second;
    return sqrt(pow(distanciaH,2) + pow(distanciaV,2)) <= r;
}

int Grafo::gFind(int i)
{
    while (i != id[i]){
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

void Grafo::gUnion(int p, int q)
{
    int i = gFind(p);
    int j = gFind(q);
    if (i == j) return;
    if (sz[i] < sz[j]){
        id[i] = j;
        sz[j] += sz[i];
    }
    else{
        id[j] = i;
        sz[i] += sz[j];
    }
    --componentesConexas;
}

bool Grafo::gConnected(int p, int q)
{
    return gFind(p) == gFind(q);
}

int Grafo::pot(int b, int e){
    if (e == 0) return 1;
    else return b*pot(b,e-1);
}
