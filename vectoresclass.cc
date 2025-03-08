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
        cout << "resize" << endl;
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
    index--; //si digita que lo quiere cambiar en la primera posición sería la posición 0
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
    index--; //si digita que lo quiere cambiar en la primera posición sería la posición 0
    assert(index >= 0 && index < size_);
    T* storage2 = new T[capacity_];
    for(unsigned int i = 0, j = 0; i < size_; i++){
        if(index != i){
         storage2[j] = storage[i];
         j++;
        }
    }
    delete[] storage;
    storage = storage2;
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
    Vector<int> result;
     for(unsigned int i = 0 , l = 0; i < vector.size(); i++){
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
    Vector<T> mergeSortedVectors(Vector<T> vector1, Vector<T> vector2){
      if(vector1.size() == 0){
        return vector2;
      }
      if(vector2.size() == 0){
        return vector1;
      }
      if(vector1.size() == 0 && vector2.size() == 0){
        return Vector<T>();
      }
      

    }

 int main(){

    Vector<int> x;
    x.push_back(25);
    x.push_front(50);
    x.push_back(7);
    x.push_front(588);
    x.push_back(90);
    x.push_front(10);
    
    x.erase(5);
    x.insert(5,999);
    x.print();
    return 0;
 }