#include <iostream>
#include <vector>
#include <random>
#include <math.h>
#include <chrono>
#include <unistd.h>
#include <fstream>

using namespace std;

void PrintVector(vector<int> *vector){
    for(int l = 0; l < vector->size(); l++){
        cout << " " << vector->at(l);
    }
    cout << endl;
}

void QuickSort(vector<int> *vector, int start, int end, int chose){
    if (start >= end) return;

    int l = 0, r = 0;
    int pivote = 0;

    if(chose == 1){
        pivote = vector->at(start);
    } else if(chose == 2){
        pivote = vector->at((start + end) / 2);
    } else if(chose == 3){
        pivote = vector->at(end);
    }
    l = start;
    r = end;

    do {
        while (vector->at(l) < pivote) l++;
        while (vector->at(r) > pivote) r--;
        if (l <= r) {
            swap(vector->at(l), vector->at(r));
            l++;
            r--;
        }
    } while (l <= r);

    if (start < r){
        QuickSort(vector, start, r, chose);
    }
    if (l < end){
        QuickSort(vector, l, end, chose);
    }
    return;
}


int main(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 1000000);

    int quantity = 0, pivot = 0;
    vector<int> variables;
    vector<int> aleatorio;
    ofstream tiempos("tiemposprueba.dat");
    quantity = pow(10, 7);
    if (!tiempos)
    {
      cout << "Error al abrir ejemplo.dat\n";
      exit(EXIT_FAILURE);
    }
    
    //cout << "Pivote en la mitad o aleatorio (1: start, 2:medio, 3: final)"; //cin >> pivot;
    for(int potencia = 2; potencia <= 9; potencia++){
        quantity = pow(10, potencia);
        aleatorio.clear();
        tiempos << "POTENCIA 10^" <<potencia << endl;
    for(int l = 0; l < quantity; l++){
        aleatorio.push_back(dist(gen));
    }
    for (int pivot = 1; pivot <= 3 ; pivot++){
        tiempos << "Pivote " << pivot << endl; 
    for (int times = 0; times < 10; times++) {
        variables = aleatorio;
        auto inicio = chrono::high_resolution_clock::now();
        
        QuickSort(&variables, 0, variables.size() - 1, pivot);
        
        auto fin = chrono::high_resolution_clock::now();

        auto duracion = chrono::duration_cast<chrono::nanoseconds>(fin - inicio);

        tiempos << duracion.count() << endl;
        
    }}}
    
    //PrintVector(&variables);

    //PrintVector(&variables);
    return 0;
}