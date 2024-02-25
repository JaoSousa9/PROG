#include <iostream>
using namespace std;

bool checkPrime(int number){
    for(int i = 2; i <= number/2; i++){
        if(number%i == 0){
            return false;
        }
    }
    return true;
}


void primes(int number){

    for(int i = 2; i <= number; i++){
        if(checkPrime(i)){
            cout << i << " ";
        }
    }    
}

int main() {
    int number;
    cin >> number;
    primes(number);
    return 0;
}