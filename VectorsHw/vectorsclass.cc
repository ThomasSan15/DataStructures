#include <iostream>
#include <cassert>

using namespace std;

template <typename T>

class Vector{
    private:
    T* storage;
    unsigned int size_;
    unsigned int capacity_;
    
    public:
    Vector(){
        capacity_ = 5;
        storage = new T[capacity_];
        size_ = 0;
    }

    Vector(unsigned int c, T elem){
        capacity_ = c;
        storage = new T[capacity_];
        for(unsigned int i = 0; i < capacity_; i++){
            storage[i] = elem;
        }
        size_ = capacity_;
    }
    Vector(initializer_list<T> list){
        capacity_ = list.size();  // La capacidad es el número de elementos en la lista
        storage = new T[capacity_];
        size_ = list.size();
        unsigned int i = 0;
        for (const T& elem : list) {
            storage[i++] = elem;  // Copiamos cada elemento al array
        }
    }
    
    unsigned int size() const{
        return size_;
    }

    unsigned int capacity()const{
        return capacity_;
    }

   const T& at(unsigned int position) const{
        assert(position >= 0 && position < size_);
        return storage[position];
    }
    
    T& at(unsigned int position){
        assert(position >= 0 && position < size_); // Asegura que la posición sea válida
        return storage[position];
    }
    const T& operator[](unsigned int index) const{
        return storage[index];
    }

    private:
    void resize(){
       // cout << "resize" << endl;
        unsigned int capacity2 = capacity_ * 1.5;
       T* storage2 = new T[capacity2];
       for (unsigned int i = 0; i < size_; i++){
        storage2[i] = storage[i];

       }
       delete[] storage;
       storage = storage2;
       capacity_ = capacity2;
    }
    public:
    void push_back(const T& elem){
        if (size_ == capacity_){
            resize();
        }
        storage[size_] = elem;
        size_++;
    }
    void pop_back(){
        assert(size_ > 0);
        size_--;
    }

    void push_front(const T& elem){
        if (size_  == capacity_){
            resize();
        }
        T* storage2 = new T[capacity_ + 1];

      storage2[0] = elem;
        for(int i = 0; i < size_ ; i++){
        storage2[i +1] = storage[i]; 
    }
    delete[] storage;
       storage = storage2;
       size_++;
}
  
void pop_front(){
    assert(size_ > 0);
    T* storage2 = new T[capacity_];
      for(unsigned int i = 0; i < size_ ; i++){
      storage2[i] = storage[i + 1]; 
  }
  delete[] storage;
     storage = storage2;
     size_--;
}

bool empty(){ return size_ == 0; }

 unsigned int waste(){
  return capacity_ - size_;
 }

 void shrink_to_fit(){;
    T* storage2 = new T[size_];
    for(unsigned int i = 0; i < size_; i++){
        storage2[i] = storage[i];
    }
    delete[] storage;
    capacity_ = size_;
    storage = storage2;
 }

 /*void insert(unsigned int index, const T& elem){  //insert que cambia un valor del vector en X posición
    assert(index >= 0 && index < size_);
    storage[position] = elem;  
 }*/

  void insert(unsigned int index, const T& elem){ //Insert que me agrega un nuevo valor}
     
    assert(index >= 0 && index < size_);
    if (size_  == capacity_){
        resize();
    }
     for(unsigned int i = size_; i > index; i--){
       storage[i] = storage[i - 1];
     }
     storage[index] = elem;    
     size_++;
 }
  void erase(unsigned int index){
     assert(index >= 0 && index < size_);
    for(unsigned int i = index; i < size_; i++){
       storage[i] = storage[i + 1];
    }
    size_--;
  }

    void print(){
        for(unsigned int i = 0; i < size_; i++){
            cout << " " << storage[i];
        }
        cout << endl;
    }

};

template <typename T>
Vector<T> removeDuplicates(const Vector<T>& vector){
    if(!vector.size()){
        return vector;
    }
    Vector<T> result;
     for(unsigned int i = 0; i < vector.size(); i++){
         bool bandera = true;
         for(unsigned int j = 0; j <  result.size(); j++){
             if(vector[i] == result[j]){
            bandera = false;
         }
     } 
     if(bandera){
         result.push_back(vector[i]);
     }
 }
      return result;
    }

    template <typename T>
    class Stack{
    private:
      unsigned int top;
      Vector<T> storage; 
      public:
      Stack(const T elem){
       top = 0;
       storage.push_back(elem); 
      }

      void push(const T elem){
        top++;
        storage.push_back(elem);
        
      }

      T pop(){
        assert(top > 0);
        
        return storage[top--]; 
      }
      
       T peek(){
        return storage.at(top);
      }
   
      bool empty(){
        return storage == 0;
      }
       
    }; 
    
   template <typename T>
   void Mergesort( Vector<T>& organizar){

    if(organizar.size() == 1){
        return;
    }
        Vector<T> leftVector;
        Vector<T> rightVector;
        
     for(int i = 0; i < organizar.size(); i++){
        if(i < (organizar.size() / 2)){
         leftVector.push_back(organizar.at(i));
        }else{
            rightVector.push_back(organizar.at(i));
        }
     }
     Mergesort(leftVector);
     Mergesort(rightVector);

     Vector<int> Organizado;
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
    organizar = Organizado;
}

    template <typename T>
    Vector<T> mergeSortedVectors(Vector<T> vector1, Vector<T> vector2){
      if(!vector1.size()){
        return vector2;
      }
      if(!vector2.size()){
        return vector1;
      }
      if(!vector1.size() && !vector2.size()){
        return Vector<T>();
      }

      Vector<T> result;

      for(unsigned int i = 0; i < vector1.size(); i++){
        result.push_back(vector1[i]);
      }
      for(unsigned int i = 0; i < vector2.size(); i++){
        result.push_back(vector2[i]);
      }
    
        Mergesort(result);

    return result;
    }
    
 int main(){
    /*
    Vector<int> numbers = {1, 2, 2, 3, 4, 4, 5};
    Vector<int> uniqueNumbers = removeDuplicates(numbers);
    
    uniqueNumbers.print(); // Expected: {1, 2, 3, 4, 5}
    
    Vector<int> numbers2 = {1,1,1,1,1,1};
    Vector<int> uniqueNumbers2 = removeDuplicates(numbers2);
    uniqueNumbers2.print(); // Expected: {1}
    
    Vector<int> numbers3 = {};
    Vector<int> uniqueNumbers3 = removeDuplicates(numbers3);
    uniqueNumbers3.print(); // Expected: {}
    
    Vector<int> numbers4 = {1};
    Vector<int> uniqueNumbers4 = removeDuplicates(numbers4);
    uniqueNumbers4.print(); // Expected: {1}
  */
 /*
 Vector<int> vector1 = {1, 1, 2, 4, 20, 9, 3, 5};
Vector<int> vector2 = {2, 4, 6, 10, 2};
Vector<int> mergedVector = mergeSortedVectors(vector1, vector2);

mergedVector.print(); // Expected: {1, 2, 3, 4, 5, 6}

Vector<int> vector3 = {1, 2, 3};
Vector<int> vector4 = {};
Vector<int> mergedVector2 = mergeSortedVectors(vector3, vector4);
mergedVector2.print(); // Expected: {1, 2, 3}

Vector<int> vector5 = {};
Vector<int> vector6 = {4,5,6};
Vector<int> mergedVector3 = mergeSortedVectors(vector5, vector6);
mergedVector3.print(); // Expected: {4, 5, 6}

Vector<int> vector7 = {1,1,1,1};
Vector<int> vector8 = {1,1,1,1};
Vector<int> mergedVector4 = mergeSortedVectors(vector7, vector8);
mergedVector4.print(); // Expected: {1,1,1,1,1,1,1,1}
*/
Stack<int> pila(5);
cout << pila.peek() << endl;
pila.push(20);
cout << pila.peek() << endl;
cout << pila.pop() << endl;
cout << pila.peek() << endl;

    return 0;
 }
