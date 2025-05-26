#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>


using namespace std;
typedef vector<vector<double>> Matrix;//Definimos matrix como una matriz de double´s
const double m = numeric_limits<double>::max();


void printMatrix(const Matrix& mat) {//Función que imprime la matriz
    for (const auto& row : mat) { //iteramos en cada fila
        for (double val : row) { 
            if (val == m) // si el valor es infinito lo expresamos
                cout << "INF\t";
            else
                cout << val << "\t"; // si no es infinito imprimimos el valor
        }
        cout << endl;
    }
}


// Function to perform matrix multiplication
Matrix multiplyMatrices(
    const Matrix& A,
    const Matrix& B) {
    // Revisar si alguna matriz no tiene fila o columna vacia
    if (A.empty() || B.empty() || A[0].empty() || B[0].empty()) {
        throw invalid_argument("Input matrices cannot be empty."); //Mensaje de error
    }
    // obtener dimensiones de las matriz
    int rowsA = A.size(); //Filas de la matriz A
    int colsA = A[0].size();
    int rowsB = B.size();//Filas de la matriz B
    int colsB = B[0].size();

    // Check if multiplication is possible

    if (colsA != rowsB) {
        throw invalid_argument(
            "Number of columns in the first matrix must be equal to the "
            "number of rows in the second matrix for multiplication.");//Si la multiplicación no es valida mandamos el error
    }

    // Initialize the result matrix C with zeros
    // The dimensions of C will be rowsA x colsB
    Matrix C(rowsA, vector<double>(colsB, m));

    // Perform multiplication
    for (int i = 0; i < rowsA; ++i) {        // Iterate over rows of A
        for (int j = 0; j < colsB; ++j) {    // Iterate over columns of B
            double minim = A[i][j]; //El minimo de una conexion IJ debe ser el valor de la matriz A en IJ , ya que esta es la acumula el camino minimo
            for (int k = 0; k < colsA; ++k) { // Iterate over columns of A / rows of B
                //cout << "(" << i << "," << j << ")" << " k: " << k << " a(i,k) " << A[i][k] << " a(k,j) " << B[k][j] << endl;
                if ( A[i][k] != m && B[k][j] != m ) // si ninguno de los 2 da infinito analizamos la suma
                minim = min(minim,  (A[i][k] + B[k][j])); // devuelve el minimo entre el minimo anterior ( minimu ) y la suma actual.
            }
            if ( i == j ) {
                 C[i][j] = 0; //Si i = j significa que estamos en el mismo nodo, por ende su camino más corto es 0 
            } else C[i][j] = minim;
        }
    }

    return C;//Retornamos la matriz 
}

int main() {
   
       Matrix A = {
        {m, 2, 1, m, 3},
        {m, m, m, 4, m},
        {m, 1, m, m, 1},
        {1, m, 3, m, 5},
        {m, m, m, m, m}
    }; 

    cout << "Graph:" << endl;
    printMatrix(A);
   
    Matrix Ai = A; // Hacemos la operacion el numero de nodos

    for (int i = 1; i < 4; i++) {
        Ai = multiplyMatrices(Ai, A); // Ai va a ser donde se acumula los pasos minimos
        cout << "\nResult of A :-) " << i << ": " << endl; // imprimimos en cada ciclo la matriz
        printMatrix(Ai);
    }

    return 0;
}
