#include <iostream>

using namespace std;

const char* longest(const char* pa[]){
    int c = 0;
    int maxSize = 0;
    int k = 0;

    while(pa[c] != nullptr){
        int size = 0;
        
        for(int i = 0; pa[c][i] != '\0'; i++){
            size++;
        }
        if(maxSize <= size){
            maxSize = size;
            k = c;
        }
        c++;
    }

    return pa[k];
}

int main(){

const char* pa[] = { "C++", nullptr };
  cout << "\"" << longest(pa) << "\"\n";

    return 0;
}