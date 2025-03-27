#include <iostream>
#include <cassert>
using namespace std;

template<typename T>
class list {
private:
    class Node {
    private:
        T data;
        Node* next;
    public:
        Node() {
            data = new T(); // Se inicializa con un nuevo objeto de tipo T
            next = nullptr;
        }

        Node(const T& dat) {
            data = dat;
            next = nullptr;
        }

        void setnext(Node* nxt) {
            next = nxt;
        }

        Node* getnext() { // Ahora retorna un puntero
            return next;
        }

        T getData() const { 
            return data;
        }
    };

    Node* first;
    Node* last;
    unsigned int size;

public:
    list() {
        first = nullptr;
        size = 0;
        last = nullptr;
    }

    unsigned int getsize() const {
        return size;
    }

    bool empty() const {
        return size == 0;
    }

    void push_front(const T& dat) {
        Node* newnode = new Node(dat);  // Se pasa la dirección de dat
        newnode->setnext(first);
        first = newnode;
        size++;

        if (last == nullptr) { // Se verifica si la lista estaba vacía
            last = newnode;
        }
    }

    void pop_front(){
        if(empty()){
            cout << "está vacia la lista";
            return;
        }
        Node* temporal = first;
        first = first->getnext();
        delete temporal;
        size--;
        if(empty()){
            last = nullptr;
        }
    }

    void push_back(const T& dat){
        Node* newnode = new Node(dat);
        if(last != nullptr){
            last->setnext(newnode);
        }
        else{
            first = newnode;
        }
        last = newnode;
        size++;
    }

    void pop_back(){
        if(empty()){
            cout << "Lista vacia" << endl;
        }
        if(size == 1){
            delete first;
             first = nullptr;
             size--;
             last = nullptr;
        }
        else{
            Node* temp = first;
            while(temp->getnext() != last){
                temp = temp->getnext();
            }
            delete last;
            temp->setnext(nullptr);
            last = temp;
            size--;
        }
    
      

    }

    T at(unsigned int position){
        assert(size > position && position >= 0);
        Node* temporal = first;
        for(int i = 0; i < position; i++){

            temporal = temporal->getnext();
        }
        return temporal->getData();
    }

    unsigned int find(const T& dat){
        assert(!empty());
        Node* temporal = first;
        for(int i = 0; temporal != nullptr; i++){
            if(temporal->getData() == dat){
                return i;
            }
            temporal = temporal->getnext();
        }
        cout << "Elemento: " << dat <<" No está en la lista" << endl; 
     
    }
   
    void print(){
        Node* temporal = first;
        for(int i = 0; i < size; i++){
            cout << temporal->getData() << " ";
            temporal = temporal->getnext();
        }
        cout << "null" << endl;
    }

    void invert(){
       Node* anterior = nullptr;
       Node* posicion = first;
       Node* siguiente = nullptr;

       while(posicion != nullptr){
        siguiente = posicion->getnext();
        posicion->setnext(anterior);
        anterior = posicion;
        posicion = siguiente;
       }
       first = anterior;
    }

    void remove_especific(const T& dat){
         assert(!empty());
         Node* aux = first;
         Node* prev = nullptr;
         Node* next = nullptr;
         while(aux != nullptr){
            next = aux->getnext();
            if(aux->getData() == dat){
            if(prev == nullptr){
                first = next;
            }else{
                prev->setnext(next);
            }
            delete aux;
            aux = next;
            size--;
         }else{
         prev = aux;
         aux = next;
         
        }
    }
    }

    list union_list(list<T> list1, list<T> list2){
        list<int> unionlist;
        int i = 0, j = 0;

    while (i < list1.getsize() || j < list2.getsize()) {
        if (i >= list1.getsize()) {
            // Si ya recorrimos toda list1, agregamos lo que falta de list2
            unionlist.push_back(list2.at(j));
            j++;
        } else if (j >= list2.getsize()) {
            // Si ya recorrimos toda list2, agregamos lo que falta de list1
            unionlist.push_back(list1.at(i));
            i++;
        } else if (list1.at(i) < list2.at(j)) {
            unionlist.push_back(list1.at(i));
            i++;
        } else {
            unionlist.push_back(list2.at(j));
            j++;
        }
    }

        return unionlist;
    }

};



int main() {
    list<int> x;
   
    x.push_front(1);
    x.push_front(2);
    x.push_front(3);
    x.push_front(4);
    x.push_front(5);
    x.push_front(6);
    x.invert();
    x.print();
   
}

