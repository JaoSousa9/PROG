#include <iostream>

using namespace std;

int common_letters(const char a[], const char b[], char out[]){
    int i = 0;
    bool check[27];
    int count = 0;

    for(int i = 0 ; i < 27; i++ ){
        check[i] = false;
    }

    while(a[i] != '\0'){
        if(a[i] >= 'a' && a[i]<= 'z'){
            check[a[i]-97] = true;
        }else if (a[i] >= 'A' && a[i]<= 'Z'){
            check[a[i]-65] = true;
        }
        i++;
    }

    int j = 0;
    while(b[j] != '\0'){
        if(b[j] >= 'a' && b[j] <= 'z'){
            if(check[b[j]-97] == true){
                out[count] = b[j];
                check[b[j]-97] = false;
                count ++;
            }
        }
        if (b[j] >= 'A' && b[j]<= 'Z'){
            if(check[b[j]-65] == true){
                out[count] = b[j]+32;
                check[b[j]-65] = false;
                count++;            
            }
        }
        j++;
    }

    return count;
}

int main(){

    char out[26+1];
    int n = common_letters("abcdefgh 12345 JKLMNOPQRSTUVWXyz abcdefgh JKLMNOPQRSTUVWXyz", "zzzz abcdefghi JKLMNOPQRSTUVWXz", out);
    cout << n << " \"" << out << "\"\n";

    return 0;
}