#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int max(const int a[], int n){
    int result = INT16_MIN;
    for(int i = 0; i < n; i++){
        result = max(result, a[i]);
    }
    return result;
}


int main(){

  const int n = 1;
  const int a[n] = { -123 };
  cout << max(a, n) << '\n'; 

  const int m = 3; 
  const int b[m] = { -3, -2, -1 };
  cout << max(b, m) << '\n'; 

  const int l = 4; 
  const int c[l] = { 4, -2, 3, 1 };
  cout << max(c, l) << '\n'; 

  const int k = 9;
  const int d[k] = { 10, 20, 30, -2, 50, 3, 1, 50, 49 };
  cout << max(d, k) << '\n'; 

	
  return 0;
}