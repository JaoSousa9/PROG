#include "print_vector.h"
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void normalise(vector<T>& v, const T& min, const T& max){

    int size = (int)v.size();

    for(int i = 0; i < size; i++){
        if(v[i] < min){
            v[i]= min;
        }else if(v[i] > max){
            v[i] = max;
        }
    }
}

int main(){

    vector<double> v { -1.2, 2.2, -3.5, 4.3, 5.2 }; 
    normalise(v, 0.5, 5.1); print(v);

    return 0;
}