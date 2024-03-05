#ifndef __print_array_h__
#define __print_array_h__

#include <iostream>
using namespace std;

void print_array(const int a[], int n){
  cout << '[' << a[0];
  for (int i = 1; i < n; i++) {
    cout << ',' << a[i];
  }
  cout << "]\n";
}

#endif // __print_array_h__

void my_sort(int a[], int size){
    for(int i = 0; i < size; i++){
        int lookOut = a[i];
        for(int j = i+1; j < size; j++){
            if (lookOut > a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                lookOut = a[i];
            }
        }
    }
}
int* merge_arrays(const int a[], int na, const int b[], int nb){
    int* c = new int[na+nb];
    for(int i = 0 ; i < na; i++){
        c[i] = a[i];
    }
    for(int j = na; j < nb+na; j++){
        c[j] = b[j-na];
    }
    my_sort(c, nb+na);

    return c;
}

int main(){
  const int NA = 15, NB = 15;
  int a[NA] = { 0, 1, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8, 8, 9, 9 };
  int b[NB] = { 0, 0, 1, 2, 3, 3, 4, 5, 5, 5, 6, 7, 7, 8, 9 };
  int* c = merge_arrays(a, NA, b, NB);
  print_array(c,  NA+NB);
  delete [] c;

  return 0;
}
