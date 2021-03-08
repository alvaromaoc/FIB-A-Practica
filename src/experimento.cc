#include "experimento.hh"

void Experimento::experimentoAristasG(int N, int profundidad)
{
    cout << "q,";
    for (double r = 0.0;r < 1.6;r += 0.1){
        cout << r;
        if (r < 1.5) cout << ",";
    }
    cout << endl;
    for (int q = 0;q <= 100;++q){
        for (int i = 0;i < profundidad;++i){
            cout << q << ",";
            for (double r = 0.1;r < 1.6;r += 0.1){
                Grafo G(N,r,q);
                cout << G.getComponentesConexas();
                if (r < 1.5) cout << ",";
            }
            cout << endl;
        }
    }
}

void Experimento::experimentoNxN(int profundidad, int D, bool A, vector<int> lados)
{
    cout << "q,";
    for (int i = 0;i < lados.size();++i){
        cout << lados[i];
        if (i != lados.size() - 1) cout << ",";
    }
    cout << endl;
    for (int q = 0;q <= 100;++q){
        for (int i = 0;i < profundidad;++i){
            cout << q << ",";
            for (int l = 0;l != lados.size();++l){
                Grafo G(lados[l],A,q,D);
                cout << G.getComponentesConexas();
                if (l != lados.size() - 1) cout << ",";
            }
            cout << endl;
        }
    }
}