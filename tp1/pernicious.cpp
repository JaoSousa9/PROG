#include <iostream>
#include <math.h>
using namespace std;

bool checkPrime(int number){
    for(int i = 2; i <= number/2; i++){
        if(number%i == 0){
            return false;
        }
    }

    if(number == 1){
        return false;
    }    

    return true;
}


int binary(int number){
    int result = 0;
    int b = sqrt(number);

    for(int i = b; i >= 0; i--){
        if(pow(2,i) <= number){
            number -= pow(2,i);
            result ++;
        }
    }

    return result;
}

void pernicious(int number){

    int end;
    cin >> end;
    for(int i = number; i <= end; i++){
        if(checkPrime(i)){
            if(checkPrime(binary(i))){
                cout << i << " ";
            }
        }
    }    
}

int main() {
    int number;
    cin >> number;
    pernicious(number);
    return 0;
}