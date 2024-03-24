#include "smatrix.h"
#include <iostream>

using namespace std;

void sum(const smatrix& a, const smatrix& b, smatrix& r){

}

int main(){

    smatrix r;
    sum({ {0, 0, 1}, {0, 1, 2}, {5, 10, 20}, {99, 12, 32} },
      { {0, 0, 1}, {0, 1, -2}, {10, 5, 20}, {99, 10, 30}, {99, 11, 31} },
      r);
    print(r);

    return 0;
}