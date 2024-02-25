#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int solve_eq(int a, int b, int c, double& x1, double& x2){
    double delta = pow(b,2) - (4*a*c);
    if(delta < 0){
        x1=NAN;
        x2=NAN;
        return 0;
    }else if(delta == 0){
        x1 = (b*(-1))/(2*a);
        x2=NAN;
        return 1;
    }else{
        x1 = ((b*(-1))-sqrt(delta))/(2*a);
        x2 = ((b*(-1))+sqrt(delta))/(2*a);
        return 2;
    }
}

int main(){

    int a,b,c;
    double x1, x2;
    cin >> a >> b >> c;
    solve_eq(a,b,c,x1,x2);
    cout << x1 << " " << x2;
    return 0;
}