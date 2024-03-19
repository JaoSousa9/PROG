#ifndef __cdata_h__
#define __cdata_h__

struct cdata {
  int count;
  int value;
};

int* expand_cdata(const cdata a[], int n);

#include <iostream>
using namespace std;

void print_array(const int a[], int n) {
  cout << '[' << a[0];
  for (int i = 1; i < n; i++) {
    cout << ',' << a[i];
  }
  cout << "]\n";
}

#endif // __cdata_h__

#include <iostream>

using namespace std;

int* expand_cdata(const cdata a[], int n){
    int pos = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < a[i].count; j++){
            pos++; 
        }
    }
    int* result = new int[pos];
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < a[i].count; j++){
            result[count] = a[i].value;
            count ++;   
        }
    }

    return result;
}

int main(){

    const int n = 2;
  const cdata a[] { { 20, 1 }, { 17, 2} };
  int* r = expand_cdata(a, n);
  print_array(r, 37);
  delete [] r;

    return 0;
}