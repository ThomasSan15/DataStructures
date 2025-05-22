#include <iostream>
#include <vector>

using namespace std;

using Matrix = vector<vector<int>>;//Una matriz de enteros

Matrix transpose(const Matrix &A) {//Función que nos da la transpuesta de una matriz
    int rows = A.size(), cols = A[0].size();
    Matrix T(cols, vector<int>(rows));//Hacemos una matriz T donde almacenaremos la transpuesta de A
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            T[j][i] = A[i][j];//cambiamos las filas por columnas 
    return T;
}

Matrix multiply(const Matrix &A, const Matrix &B) {//Multiplica la matriz A por el vector B
    int n = A.size(), m = B[0].size(), p = B.size();
     int a_cols = A[0].size();
    Matrix R(n, vector<int>(m, 0));
     if ( a_cols != p) { //El número p (filas en B), debe ser igual a las columnas de A
        cerr << "Error: dimensiones incompatibles para multiplicación de matrices." << endl;//Si no es igual lanzamos un error
        exit(EXIT_FAILURE); 
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < p; ++k)
                R[i][j] += A[i][k] * B[k][j];//Multiplicamos la matriz por el vector
    return R;
}


void print_matrix(const Matrix &M, const string &label) {//Imprime la matriz
    cout << "\nMatriz " << label << ":\n";
    for (const auto& row : M) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }
}

int main() {
   
    Matrix A = {
        {0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 1, 0, 1, 0, 0},
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0}
    };

    Matrix B = {//Vector por el cual multiplicaremos
        {0},
        {0},
        {0},
        {1},
        {0},
        {0}
    };

    Matrix T = transpose(A);//Le hacemos la transpuesta a la matriz A y la almacenamos en la matriz T
    Matrix TB = multiply(T, B);//Multiplicamos T por el vector B

    print_matrix(A, "A");
    print_matrix(T, "A Transpuesta");
    print_matrix(B, "B");
    print_matrix(TB, "T * B");
    
    return 0;
}
