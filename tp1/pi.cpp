#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double pi(int count){
    double pi = 4;
    double sum = 0;

    for(int i = 0; i <= count; i++){
        sum += pow(-1,i)/(2*i + 1); 
    }
    if(count == 0){
        return pi;
    }
    return pi*sum;
}

int main() {
    int number, precision;
    cin >> number >> precision;
    double approximatedNumber = pi(number);
    cout << fixed << setprecision(precision) << approximatedNumber;
    return 0;
}