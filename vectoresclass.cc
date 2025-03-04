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
    unsigned int size(){
        return size_;
    }

    T& at(unsigned int position){
        assert(position >= 0 && position < size_);
        return storage[position];
    }
  
   const T& at(unsigned int position) const{
        assert(position >= 0 && position < size_);
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
       capacity_++;
}
  
void pop_front(){
    T* storage2 = new T[capacity_];
      for(int i = 0; i < size_ ; i++){
      storage2[i] = storage[i + 1]; 
  }
  delete[] storage;
     storage = storage2;
    
}

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
    void print(){
        for(unsigned int i = 0; i < size_; i++){
            cout << " " << storage[i];
        }
        cout << endl;
    }

};

class  complex{
    private:
    double real;
    double img;
    public:
    complex(){
        real = 0.0;
        img = 0.0;
        }
        friend ostream& operator<<(ostream& os, const complex& c);
};

 ostream& operator<<(ostream& os, const complex& c){
    os << "(" << c.real << "," << c.img << "i)";
    return os;
 }

 int main(){
    Vector<int> x(10,0);
    x.print();
    x.push_front(5);
    x.push_front(25);
    x.push_front(55);
    x.print();
    cout << x.waste() << endl;
    x.shrink_to_fit();
    cout << x.waste() << endl;
    
    return 0;
 }