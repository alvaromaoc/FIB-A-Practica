#include "experimento.hh"

using namespace std;

void usage(string name){
    cout << "Para realizar un experimento usa:" << endl;
    cout << "Con grafos en cuadricula:\n\t" << name << " N [N | A] [P] [D] [L1 ... LN]" << endl;
    cout << "Con grafos geometricos:\n\t" << name << " G [K] [P]" << endl;
    cout << "Donde:\n\t";
    cout << "N -> Percolacion por nodos | A -> Percolacion por aristas\n\t";
    cout << "P -> Profundidad: (Ejemplo: 100)\n\t";
    cout << "D -> Dimensiones: (Ejemplo: 3)\n\t";
    cout << "K -> Numero de nodos: (Ejemplo: 25)\n\t";
    cout << "L1 ... LN -> Sucesion de numeros de nodos de lado: (Ejemplo: 10 25 50 100 ...)" << endl;
}

main(int argc, char *argv[]){
    if (argc == 1){
        usage(argv[0]);
        return 0;
    }
    string tipo = argv[1];
    if (tipo == "G"){
        if (argc != 4){
            usage(argv[0]);
            return 0;
        }
        int nodos = stoi(argv[2]);
        int profundidad = stoi(argv[3]);
        Experimento::experimentoAristasG(nodos,profundidad);
    }else if (tipo == "N"){
        if (argc < 5){
            usage(argv[0]);
            return 0;
        }
        string A = argv[2];
        int profundidad = stoi(argv[3]);
        int dim = stoi(argv[4]);
        vector<int> lados;
        for (int i = 5;i < argc;++i){
            lados.push_back(stoi(argv[i]));
        }
        if (A == "A") Experimento::experimentoNxN(profundidad,dim,true,lados);
        else if (A == "N") Experimento::experimentoNxN(profundidad,dim,false,lados);
    }
}