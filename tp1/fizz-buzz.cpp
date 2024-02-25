#include <iostream>
using namespace std;

void fizzBuzz(int n){
    for(int i = 1; i<=n; i++){
        if(i%15==0) continue;
        if(i%5 == 0){
            cout << "Buzz ";
        }else if(i%3==0){
            cout << "Fizz ";
        }else{
            cout << i << " ";
        }
    }
}
int main() {
    int value;
    cin >> value;
    fizzBuzz(value);
    return 0;


}