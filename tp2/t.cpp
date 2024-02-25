#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int f(int x, int& c){
    c++;
    if(x <= 1) return x;
    else return f(x-1, c) + f(x-2,c);
}

int f(int x){
    int c = 0;
    int r = f(x,c);
    return r +c;
}

int main(){

    cout <<  f(3);
    return 0;
}