#include <iostream>
#include <random>
#include <vector>

using namespace std;


vector<int> Mergesort( vector<int> organizar){

    if(organizar.size() == 1){
        return organizar;
    }
        vector<int> leftVector;
        vector<int> rightVector;
        
     for(int i = 0; i < organizar.size(); i++){
        if(i < (organizar.size() / 2)){
         leftVector.push_back(organizar.at(i));
        }else{
            rightVector.push_back(organizar.at(i));
        }
     }
     leftVector = Mergesort(leftVector);
     rightVector = Mergesort(rightVector);

     vector<int> Organizado;
     for(int i = 0, r = 0, l = 0; i < organizar.size(); i++){
        if(leftVector.size() == l){
            Organizado.push_back(rightVector.at(r));
            r++;
        } else if(rightVector.size() == r ){
            Organizado.push_back(leftVector.at(l));
            l++;
        }else if(leftVector.at(l) < rightVector.at(r)){
            Organizado.push_back(leftVector.at(l));
            l++;
        }
        else{
            Organizado.push_back(rightVector.at(r));
            r++;
        }
    }

   return Organizado;
}


int main(){
random_device rd;  // Dispositivo de entropC-a aleatoria
	mt19937 gen(rd()); // Generador Mersenne Twister
	// Definir un rango, por ejemplo, entre 1 y 100
	uniform_int_distribution<int> distrib(0,10);
	vector<int>prueba;
	cout <<" Ingrese el tamaño: " << endl;
	int size;
	cin >> size ;
	for ( int i = 0 ; i < size ; i++) {
		int valor = distrib(gen);
		prueba.push_back(valor);
	}
	for ( int i = 0 ; i < size ; i++) {
		cout << " " << prueba.at(i);
	}
	cout << "" << endl;
	vector<int>prueba2 = Mergesort(prueba);
	for ( int i = 0 ; i < size ; i++) {
		cout << " " << prueba2.at(i);
	}

	return 0;
}