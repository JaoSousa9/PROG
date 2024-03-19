#include <iostream>
#include <algorithm>

using namespace std;

int median(const int a[], int n){
    int* temp = new int[n];
    int result;
    for(int i = 0; i < n; i++){
        temp[i] = a[i];
    }
    sort(temp, temp + n);

    if(n % 2 == 0){
        result = (temp[n/2 -1] + temp[n/2]) / 2;
    }else{
        result = temp[n/2]; 
    }

    delete [] temp;
    return result;
}

int main(){

     const int n = 5; 
     int a[n] { 10, -10, 0, 12, 11 };
     cout << median(a, n) << '\n';
     return 0;
}