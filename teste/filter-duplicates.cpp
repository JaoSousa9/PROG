#include <iostream>
#ifndef __print_array_h__
#define __print_array_h__

#include <iostream>
using namespace std;

void print_array(const int a[], int n) {
  cout << '[';
  if (n > 0) {
    cout << a[0];
    for (int i = 1; i < n; i++) {
      cout << ',' << a[i];
    }
  }
  cout << "]\n";
}

#endif // __print_array_h__
using namespace std;

int filter_duplicates(const int a[], int n, int b[]){
    int cur = a[0];
    int count = 0;
    for(int i = 1; i<n ; i++){
        if(!(cur == a[i])){
            b[count] = cur;
            count++;
        }
        cur = a[i];
    }
    b[count++] = a[n-1];

    return count;
}


int main(){

    const int n = 11;
    const int a[n] = { 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 33 };
    int b[n] = { 0 };
    int nf = filter_duplicates(a, n, b);
    print_array(b, nf);

    return 0;
}