#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int v[10000];
int parent[10000]; //array de padres
int rango[10000]; //array de rangos o niveles de un nodo

int n;
void init() {
    for(int i=0;  i<= n; i++) {
        parent[i] = i; //hace que cada nodo sea su propio padre
        rango[i] = 0; //hace que el rango de cada nodo sea 0
    }
}

int find(int x) { //indica el padre o raiz de un arbol
    if(x == parent[x]) { //un nodo es raiz cuando este nodo es su propio padre
        return x;
    }
    else { //busqueda y compresion del arbol
        parent[x] = find(parent[x]); //hacemos que un nodo que no es hijo del nodo raiz sea hijo del nodo raiz
        return parent[x];
        //return find(parent[x]) //se usa esta linea para solo encontrar al padre sin comprimir el arbol
    }
}

void unionRango(int x,int y) { //utilizado para unir el rango de dos nodos
    int xRaiz = find(x); 
    int yRaiz = find(y);
    if(rango[xRaiz] > rango[yRaiz]) {
        parent[yRaiz] = xRaiz; //el nodo de rango mayor se vuelve padre del nodo de rango menor; su rango no cambia
    } else {
        parent[xRaiz] = yRaiz; //el nodo de rango mayor se vuelve padre del nodo de rango menor; su rango no cambia
        if(rango[xRaiz] == rango[yRaiz]) { //si el rango de los dos nodos que se desea unir son iguales
            rango[yRaiz]++; //por convencion hacemos que el segundo nodo sea el nuevo padre
        }
    }
}

int main() {
    input;
    cin>>n;
    init();
    int nrounionRangoes; 
    cin>>nrounionRangoes;
    while(nrounionRangoes--) {
        int x,y;
        cin>>x>>y; 
        unionRango(x,y);
    }
    for(int i=0;i<=n;i++){ 
        cout<<"["<<i<<"] ";
    }
    cout<<endl;
    for(int i=0;i<=n;i++){ 
        cout<<"[" <<parent[i]<<"] ";
    }
    cout<<endl;
    for(int i=0;i<=n;i++){ 
        cout<<"[" <<rango[i]<<"] ";
    }
    cout<<endl;


    return 0;
}
