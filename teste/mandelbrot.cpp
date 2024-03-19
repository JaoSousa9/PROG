#include <iostream>
#ifndef __complex_h__
#define __complex_h__

//! Complex number
struct complex {
  int real;  // Real part
  int img;   // Imaginary part
};

#include <iostream> 
using namespace std;

//! Print array of complex numbers.
void print(const complex z[], int n) {
  cout << "[ ";
  for (int i = 0; i < n; i++) {
    if (z[i].real == 0 && z[i].img == 0)
      cout << 0;
    else {
      if (z[i].real != 0)
        cout << z[i].real;
      if (z[i].img > 0)
        cout  << '+' << z[i].img << 'i';
      else if (z[i].img < 0)
        cout  << z[i].img << 'i';
    }
    cout << ' ';
  }
  cout << "]\n";
}

#endif // __complex_h__

complex add(complex a, complex b){

    complex c;
    c.real = a.real + b.real;
    c.img = a.img + b.img;

    return c;
}

complex mult(complex a, complex b){

    complex c;
    c.real = (a.real * b.real) - ( a.img * b.img);
    c.img = (a.real * b.img) + (a.img * b.real);

    return c;
}

void mandel(complex c, int n, complex z[]){
    if(n == 1){
        z[n-1] = {0,0}; 
    }else{
        mandel(c, n-1, z);
        z[n-1] = add(mult(z[n-2], z[n-2]),c);
    }
}
int main(){

    complex c = { 0, 3 };
    const int n = 5;
    complex z[n];
    mandel(c, n, z);
    print(z, n);

    return 0;
}
