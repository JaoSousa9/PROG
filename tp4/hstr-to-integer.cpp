#include <iostream>

using namespace std;

unsigned long hstr_to_integer(const char hstr[]){
    unsigned long result = 0;
    int length = 0;
    unsigned long power = 1;
    for(int j = 0; hstr[j] != '\0'; j++){
        length++;
    }

    for(int i = length-1; i >= 0; i--){
        if(hstr[i]>= '0' && hstr[i] <= '9'){
            result += (hstr[i]-48)*power;
        }else if(hstr[i]>= 'a' && hstr[i] <= 'f'){
            result += (hstr[i]-87)*power;
        }else if(hstr[i]>= 'A' && hstr[i] <= 'F'){
            result += (hstr[i]-55)*power;
        }
        power = power *  16;
    }

    return result;
}

int main(){

    cout << hstr_to_integer("cafebabe2022") << "\n";
    cout << hstr_to_integer("0") << "\n";
    cout << hstr_to_integer("A") << "\n";
    cout << hstr_to_integer("19") << "\n";
    cout << hstr_to_integer("fF");

    return 0;
}