#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

unsigned long bc(unsigned long n, unsigned long k){
    long tempn = 1;
    long tempk = 1;
    for(int i = 0; i < (int)k; i++){
        tempn *= n-i;
        tempk *= k-i;
    }

    return tempn/tempk;
}

unsigned long bell(unsigned long n){
    if(n==0){
        return 1;
    }
    unsigned long result=0;
    for(int i=0; i < (int)n; i++){
        result += bc(n-1, i)* bell(i);
    }
    return result;
}


int main(){

    int a;
    cin >> a;
    cout << bell(a);
    return 0;
}