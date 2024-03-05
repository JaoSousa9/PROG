#include <iostream>
#include <math.h>

using namespace std;

unsigned long hstr_to_integer(const char hstr[]){
    unsigned long result = 0;
    int length = 0;
    int power = 0;
    for(int j = 0; hstr[j] != '\0'; j++){
        length++;
    }

    for(int i = length-1; i >= 0; i--){
        if(hstr[i]>= '0' && hstr[i] <= '9'){
            result += (hstr[i]-48)*pow(16,power);
        }else if(hstr[i]>= 'a' && hstr[i] <= 'f'){
            result += (hstr[i]-87)*pow(16,power);
        }else if(hstr[i]>= 'A' && hstr[i] <= 'F'){
            result += (hstr[i]-55)*pow(16,power);
        }
        power++;
    }

    return result;
}

int main(){

    cout << hstr_to_integer("CafeBabe2022") << "\n";
    cout << hstr_to_integer("0") << "\n";
    cout << hstr_to_integer("A") << "\n";
    cout << hstr_to_integer("19") << "\n";
    cout << hstr_to_integer("a");

    return 0;
}