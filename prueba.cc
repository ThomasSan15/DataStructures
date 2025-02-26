#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> prueba[5];
    vector<int> prueba2[6];

   prueba->push_back(4);
//   cout << prueba->at(0) << endl;
   prueba->push_back(25);
  // cout << prueba->at(1) << endl;
  prueba->push_back(299);

   prueba2->push_back(26);
   for(int i = 1; i < prueba->size(); i++){
      prueba2->push_back(prueba->at(i-1));
   }
      cout << prueba2->at(0) << endl;
        cout << prueba2->at(1) << endl;
       cout << prueba2->at(2) << endl;
          cout << prueba2->at(3) << endl;
 
   return 0;
}