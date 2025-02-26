#include <iostream>
#include <cassert>

using namespace std;
 template <typename T>

class Lista{
private:
class Node{
 private:
  T data_;
  Node* next_;
  public:
  Node(){
    data_ = T();
    next_ = nullptr;
  }
  Node(const T& d){
    data_ = d;
    next_ = nullptr;
  }
  void set_next(Node* nxt){
    next_ = nxt;
  }
  T& get_data(){
    return data_;
  }
  Node* getNext(){
    return next_;
}
};

Node* first_;
Node* last_;
unsigned int size_;
public:
Lista(){
    first_ = nullptr;
    size_ = 0;
    last_ = nullptr;
}
unsigned int size() const{
    return size_;
}
bool empty() const{
    return !size_;
}

void push_front(const T& elem){

    Node* n = new Node(elem);
   n->set_next(first_);
    first_ = n;
    size_++;
    if(empty()){
        last_ = n;
    }
  }
    /*void push_back(const T& elem){
        Node* n = new Node(elem);
        n->set_next(last_);
        last_ = n;
        if(!empty()){
          first_ = n;
        }
        size_++;
    }*/
  
void push_back(const T& elem) {
  Node *newNode = new Node(elem);
  if (last_) { 
      last_->set_next(newNode); // El último nodo debe apuntar al nuevo nodo
  } else {  
      first_ = newNode; // Si la lista está vacía, también es el primer nodo
  }
  last_ = newNode; // Ahora last_ apunta al nuevo nodo
  size_++;
}

   int find(const T& elem) const{
    assert(size_ != 0);
    Node* p = first_;
    unsigned int position;
    int b = 0;
    while (p->get_data() != elem) {
        p = p->getNext();
        position++;
    }
    if(p->getNext == nullptr){
      return -1;
    }
    return position;
   }

   /*void remove(unsigned int position){
   
    if (size_ == 0) return;

    if (size_ == 1 && position == 1) {
        delete first_;
        first_ = nullptr;
        last_ = nullptr;
    } 

      Node* p = first_; 
      Node* temp; 
      for(int i = 0; i < position; i++){
        p = p->getNext();
        temp = p->getNext();
    }
    if(temp->getNext == ) 
   }*/

    const T& at(unsigned int position){
      assert(position >= 0 && position < size_);
      Node* p = first_;  
      for(int i = 0; i < position; i++){
        p = p->getNext();
    }
    return p->get_data();
    }

    void pop_back() {
      if (size_ == 0) return;

      if (size_ == 1) {
          delete first_;
          first_ = nullptr;
          last_ = nullptr;
      } else {
          Node* p = first_;
          while (p->getNext() != last_) {
              p = p->getNext();
          }
          delete last_;
          last_ = p;
          last_->set_next(nullptr);
      }
      size_--;
  }

  void print(){
    Node* p = first_;  
      for(int i = 0; i < size_; i++){
        cout << " " << p->get_data();
        p = p->getNext();
    }
  }
};

int main(){
   Lista<int> x;
    x.push_back(5);
    x.push_back(65);
    x.push_back(75);
    x.push_front(95);
    x.print();
    return 0;
}