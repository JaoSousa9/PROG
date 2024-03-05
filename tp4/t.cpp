#include <iostream>
using namespace std;


struct dataaa{
    long a;
    int b[3];
    char c[12];
};

int main(){
    char s[] = "C/C++ is fun!";
    int i = 0;

    while(s[i] != '\n' && s[i] != ' ') i++;
    s[i] = '\0';
    cout << i << " " << s;

    dataaa v[4];

    cout << sizeof(v);
    return 0;    
}