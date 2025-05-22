#include <iostream>
#include <vector>

using namespace std;

const int N = 8; // Tamaño máximo del grafo

using Matrix = vector<vector<bool>>;//Matriz con 0 y 1 (matriz de adyacencia)

Matrix identity(int n) { //Función que nos dá la matriz identidad
    Matrix I(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) I[i][i] = true; //Coloca un 1 en las diagonales 
    return I;
}

Matrix boolean_or(const Matrix &A, const Matrix &B) {//Función que realiza la suma lógica OR entre las matrices
    int n = A.size();
    Matrix R(n, vector<bool>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            R[i][j] = A[i][j] || B[i][j];
    return R;
}

Matrix boolean_and(const Matrix &A, const Matrix &B) {//Funcion que realiza el operador and entre las dos matrices
    int n = A.size();
    Matrix R(n, vector<bool>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            R[i][j] = A[i][j] && B[i][j];
    return R;
}

Matrix transpose(const Matrix &A) {//Nos dá la transpuesta de la matriz
    int n = A.size();
    Matrix T(n, vector<bool>(n)); //Crea una matriz T que va a ser la transpuesta
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            T[j][i] = A[i][j];
    return T;//Retornamos la transpuesta
}

Matrix boolean_multiply(const Matrix &A, const Matrix &B) {/* En vez de sumar y multiplicar como en álgebra lineal normal, 
                                                            aquí se usa OR en vez de suma y AND en vez de multiplicación.*/
    int n = A.size();
    Matrix R(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                R[i][j] = R[i][j] || (A[i][k] && B[k][j]);
    return R;
}

// C = I ∨ A ∨ A^2 ∨ ... ∨ A^(n-1)
Matrix compute_reachability(const Matrix &A) { //Esta función calcula la matriz de alcanzabilidad C de un grafo
    int n = A.size();
    Matrix C = identity(n);//Primero decimos que C va a ser una matriz identidad nxn
    Matrix P = A; //P va a ser una copia de la matriz A para hacer luego A ∨ A^2 ∨ ... ∨ A^n
    for (int i = 0; i < n; ++i) {
        C = boolean_or(C, P);
        P = boolean_multiply(P, A); // P = A^i
    }
    return C;
}

void print_components(const Matrix &SCC) {//Imprime los componentes de la matriz
    int n = SCC.size();
    vector<bool> visited(n, false); 
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            cout << "Componente: ";
            for (int j = 0; j < n; ++j) {
                if (SCC[i][j]) {
                    cout << j << " ";
                    visited[j] = true;
                }
            }
            cout << endl;
        }
    }
}

void print_matrix(const Matrix &M, const string &name) {//Imprime la matriz 
    cout << "\nMatriz " << name << ":\n";
    for (const auto& row : M) {
        for (bool val : row)
            cout << val << " ";//Imprimimos los 1 y 0
        cout << endl;
    }
}

int main() {

   Matrix A = { //Matriz de ejemplo con 8 nodos
    {0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 1, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 1}
};


    Matrix C = compute_reachability(A);//La matriz de alcanzabilidad
    Matrix Ct = transpose(C);//La matriz transpuesta de C
    Matrix SCC = boolean_and(C, Ct); // SCC = C ∧ Cᵗ
    print_matrix(SCC, "SCC (Componentes Fuertemente Conexas)");

    print_components(SCC);


    return 0;
}
