#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

int main(){
    cout << "vector example" << endl;
    vector<int> a;
    cout << "Size" <<endl;
    cout << a.size() << endl;
    
    a.push_back(42);
    cout << a.at(0) << endl;

    return 0;
}