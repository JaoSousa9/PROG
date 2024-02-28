#ifndef __fraction_h__
#define __fraction_h__

struct fraction {
  int num;
  int den;
};

int gcd(int a, int b);
fraction add(fraction a, fraction b);
fraction mul(fraction a, fraction b);

#include <iostream>
using namespace std;

ostream& operator<<(ostream& out, fraction f) {
  if (f.den == 1) 
    out << f.num;
  else
    out << f.num << '/' << f.den;
  return out;
}

#endif // __fraction_h__

using namespace std;

int gcd(int a, int b){
    if(b == 0){
        return a;
    }else {
        return gcd(b,a%b);
    }
}

fraction add(fraction a, fraction b){
    fraction result;
    int num = a.num*b.den + b.num*a.den;
    int den = a.den*b.den;

    int divisor = gcd(num,den);


    result = {num/divisor, den/divisor};

    if(result.den < 0 && result.num > 0){
        result.num *= -1;
        result.den *= -1;
    }

    return result;
}

fraction mul(fraction a, fraction b){
    fraction result;

    int num = a.num * b.num;
    int den = b.den * a.den;

    int divisor = gcd(num,den);

    result = {num/divisor, den/divisor};

    if(result.den < 0 && result.num > 0){
        result.num *= -1;
        result.den *= -1;
    }

    return result;

}


int main(){

    fraction a { -8, 25 }, b { 3, 4 };
    cout << add(a,b) << " " << mul(a,b);
    return 0;
}