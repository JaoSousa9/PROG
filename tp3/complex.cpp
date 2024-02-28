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


int main(){

    complex a { 2, 0 }, b { 2.5, -3.1}, s, m;
    add(a, b, s); 
    mul(a, b, m);
    cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n';
    return 0;
}