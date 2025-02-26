#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Conjunto {
private:
    vector<int> elementos;

public:
    void agregar(int elemento) {
        if (find(elementos.begin(), elementos.end(), elemento) == elementos.end()) {
            elementos.push_back(elemento);
        }
    }

    bool pertenece(int elemento) const {
        return find(elementos.begin(), elementos.end(), elemento) != elementos.end();
    }

    Conjunto unionConjuntos(const Conjunto &otro) const {
        Conjunto resultado = *this;
        for (int elem : otro.elementos) {
            resultado.agregar(elem);
        }
        return resultado;
    }

    Conjunto interseccion(const Conjunto &otro) const {
        Conjunto resultado;
        for (int elem : elementos) {
            if (otro.pertenece(elem)) {
                resultado.agregar(elem);
            }
        }
        return resultado;
    }

    bool esSubconjunto(const Conjunto &otro) const {
        for (int elem : elementos) {
            if (!otro.pertenece(elem)) {
                return false;
            }
        }
        return true;
    }

    void imprimir() const {
        cout << "{";
        for (size_t i = 0; i < elementos.size(); i++) {
            cout << elementos[i];
            if (i < elementos.size() - 1) {
                cout << ", ";
            }
        }
        cout << "}" << endl;
    }
};

int main() {
    Conjunto a, b, resultado;
    //a.agregar(6);
    a.agregar(4);
    a.agregar(5);
    b.agregar(3);
    b.agregar(4);
    b.agregar(5);

    cout << "Conjunto A: ";
    a.imprimir();
    cout << "Conjunto B: ";
    b.imprimir();

    resultado = a.unionConjuntos(b);
    cout << "Union: ";
    resultado.imprimir();

    resultado = a.interseccion(b);
    cout << "Interseccion: ";
    resultado.imprimir();

    cout << "A es subconjunto de B? " << (a.esSubconjunto(b) ? "Si" : "No") << endl;

    return 0;
}
