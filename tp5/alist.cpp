#ifndef __alist_h__
#define __alist_h__

#include <iostream>
#include <cstdarg>
using namespace std;

//! Array list.
struct alist {
  int size;       // Number of elements.
  int* elements;  // List elements.
};

//! Build an empty list.
alist* empty() {
  return new alist { 0, nullptr };
}

//! Build array list.
alist* build(int n, int v[]) {
  alist* al = new alist;
  al->size = n;
  if (n == 0) {
    al->elements = nullptr;
  } else {
    al->elements = new int[n];
    for (int i = 0; i < n; i++) {
      al->elements[i] = v[i];
    }
  }
  return al;
}

//! Destroy array list
void destroy(const alist* al) {
  delete [] al->elements;
  delete al;
}

void print(const alist* al) {
  cout << '[';
  for (int i = 0; i < al->size; i++) { 
    cout << ' ' << al->elements[i];
  }
  cout << " ]\n";
}

//! Append function (declaration only, must be implemented).
void append(alist* a, const alist* b);

#endif // __alist_h__

#include <iostream>

using namespace std;

void append(alist* a, const alist* b){

    int size = a->size + b->size;
    int* elements = new int[size];
    for(int i = 0; i < size; i++){
        if(i < a->size){
            elements[i] = a->elements[i];
        }else if( i >= a->size){
            elements[i] = b->elements[i - a->size];
        }
    }

    a = build(size, elements);

}

int main(){

const int nA = 2;
  int eA[nA] = { 1, 2 };
  alist* a = build(nA, eA);
  const int nB = 3;
  int eB[nB] = { 3, 4, 5 };
  const alist* b = build(nB, eB);
  append(a, b);
  print(a);
  destroy(a);
  destroy(b);

    return 0;
}