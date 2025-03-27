#include <iostream>
#include <vector>

using namespace std;

 void ReverseMatrix(int matrix[3][3]){
    
  int matrixtemp[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
     for(int i = 0, l = 0; i < 3; i++, l++){
        for(int j = 0, m = 2; j < 3; j++, m-- ){
            matrix[l][m] = matrixtemp[i][j];
        }
     }


    }

int main(){
     // Declaración e inicialización de una matriz 3x3
     int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Mostrar la matriz
    cout << "Matriz 3x3:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    ReverseMatrix(matriz);

    cout << "Matriz 3x3:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}