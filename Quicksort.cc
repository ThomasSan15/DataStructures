//Desarrollado por Thomas Beltran
#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

/*vector<int>*/ void quicksort(vector<int> *Organizar, int desition) {
  /*  // Inicializar el generador de números aleatorios con una semilla
    random_device rd;  // Dispositivo de entropía aleatoria
    mt19937 gen(rd()); // Generador Mersenne Twister
    // Definir un rango, por ejemplo, entre 1 y 100
    uniform_int_distribution<int> distrib(0, (Organizar.size() - 1));*/
    int pivote;
    int size;
    size = Organizar->size() /2 ;
   // int random = distrib(gen);
    if (desition){
    pivote =  Organizar->at(size);
    //cout <<"Su pivote es ->  " << pivote << " En la posicion ->" << Organizar->size() /2 << endl;
}
    /*else{
     pivote = Organizar.at(random); //Posicion random
    cout <<"Su pivote es ->  " << pivote << " En la posicion ->" << random<< endl;
    }*/
    vector<int> Lowers;
    vector<int> highers; 

  for ( int i = 0 ; i < Organizar->size(); i++ ) {

    if ( (i == size && desition == 1) /*|| (i == random && desition == 0) */) {
        //nothing
    } else {
        if(Organizar->at(i) < pivote){
            Lowers.push_back(Organizar->at(i));
        }
        else if ( Organizar->at(i) >= pivote ){
            highers.push_back(Organizar->at(i));
        }
    }
}

if ( Lowers.size() != 0 ) {
 quicksort(&Lowers, desition);
}

if ( highers.size() != 0 ) {
    quicksort(&highers,desition);
}
vector<int>Organizado;
for ( int i = 0 ; i < Lowers.size(); i++) {
    Organizado.push_back( Lowers.at(i));
}

Organizado.push_back(pivote);

for ( int i = 0 ; i < highers.size()  ; i++) {
    Organizado.push_back( highers.at(i));
}
*Organizar = Organizado;
return;
}

int main () {
    vector<int> aleatorio;
    vector<int> organizar;
    int desition = 0;
    int size = 0;

       random_device rd;  // Dispositivo de entropía aleatoria
       mt19937 gen(rd());
       uniform_int_distribution<int> distrib(0, 10);
     cout << "Digite el tamaño del vector que desee:" << endl;
     cin >> size;

    for(int i = 0; i < size; i++){
        aleatorio.push_back(distrib(gen));
    }
    organizar = aleatorio;
    /*for(int i = 0; i < size; i++){
        cout << " " << organizar[i];
    }*/
    /*do{
    cout << "Digite 0 si desea que el pivote sea aleatorio" << endl;
    cout << "Digite 1 si desea que el pivote sea el del medio" << endl;
    cin >> desition;
    }while(desition != 0 && desition != 1);*/
  cout << endl;
  quicksort(&organizar, 1);
 /* for(int i = 0; i < size; i++){
    cout << " " << organizar[i];
}*/
   cout << "\n\n\n" << organizar.size();
}