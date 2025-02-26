#include <iostream>

using namespace std;

typedef struct{
    double real;
    double img;

}complexNumber;

complexNumber csum(complexNumber *a, complexNumber *b){
    complexNumber r;
    r.real = a->real + b->real;
    r.img = a->img + b->img;
  return r;
}

int main(){
  complexNumber m;
  m.real = 10.0;
  m.img = 2.0;
  complexNumber n;
  n.real = 100.0;
  n.img = 20.0;
  complexNumber w = csum(&m, &n);

  cout <<"Result : " << w.real << " img: "<< w.img << "i" << endl;
  return 0;
}
