#include <iostream>
using namespace std;

void charTypes(int count){
    int numbers = 0;
    int chars = 0;
    int non = 0;

    for(int i = 1; i <= count; i++){
        char a;
        cin >> a;
        
        if('0'<= a && a <= '9'){
            numbers++;
        }else if(('a' <= a && a <= 'z') || ('A' <= a && a <= 'Z')){
            chars++;
        }else{
            non++;
        }
    }

    cout << chars << " " << numbers << " " <<  non;

}

int main() {
    int count;
    cin >> count;
    charTypes(count);
    return 0;
}