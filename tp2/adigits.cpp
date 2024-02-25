#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int adigits(int a, int b, int c){

    int result = 0;
    for(int i = 100; i > 0; i = i/10){
        if(a >= b && a >= c){
            result += a*i;
            a=0;
        }else if(b >= a && b >= c){
            result += b*i;
            b=0;
        }else{
            result += c*i;
            c=0;
        }
    }

    return result;
}

int main(){

    int a,b,c;
    cin >> a >> b >> c;
    adigits(a,b,c);
    return 0;
}