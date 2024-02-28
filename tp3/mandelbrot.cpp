
#ifndef __complex_h__
#define __complex_h__

// Representation of a complex number z = x + y i
struct complex {
  double x; // Real part
  double y; // Imaginary part
};

double norm(const complex& c);
void add(const complex& a, const complex& b, complex& r);
void mul(const complex& a, const complex& b, complex& r);

#include <iostream>
#include <iomanip>
using namespace std;

ostream& operator<<(ostream& out, const complex& c) {
  return out << fixed << setprecision(3) 
             << c.x 
             << (c.y >= 0.0 ? "+" : "")
             << c.y << "i";
}

#endif // __complex_h__

#include <math.h>

void add(const complex& a, const complex& b, complex& r){
    r = {a.x+b.x, a.y+b.y};
}

void mul(const complex& a, const complex& b, complex& r){
    r = {a.x*b.x - a.y*b.y, a.x*b.y + b.x*a.y};
}

double norm(const complex& c){
    return sqrt((c.x*c.x) + (c.y*c.y));
}

void mandelbrot(const complex& c, unsigned int n, complex& z_n){
    if(n==0){
        z_n ={0,0};
    }else{
        mandelbrot(c,n-1,z_n);
        mul(z_n,z_n,z_n);
        add(z_n,c,z_n);
    } 
}

int main(){

    complex z_n;
    mandelbrot({0.1, 3.2}, 4, z_n);
    cout << z_n << '\n';
    return 0;
}