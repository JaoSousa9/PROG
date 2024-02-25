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

int main(){

    int a,b;
    cin >> a >> b;
    cout << bc(a,b);
    return 0;
}