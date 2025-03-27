#include <iostream>

using namespace std;

template<typename T>
class arbolito{
    private:
 class Node{
   private:
   Node* menor;
   Node* mayor;
   T data;
   public:

   Node(){
    mayor = nullptr;
    menor = nullptr;
    data = T();
   }
  
   Node* getmenor(){
    return menor;
   }

   Node* getmayor(){
    return mayor;
   }

   void setmenor(Node* newmin){
    menor = newmin;
   }
  
    void setmayor(Node* newmax){
        mayor = newmax;
    }

 };
 Node* raiz;
 unsigned int size;
  
  public:

  arbolito(){
    raiz = nullptr;
    
  }
};