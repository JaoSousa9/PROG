#include <iostream>

using namespace std;

bool pangram(const char s[], char m[]){
    bool result = 0;
    int counter = 0;
    char temp[27];

    int i = 0;

    while(s[i] != '\0'){
        if(s[i] >= 97 && s[i] <= 122){
            if(temp[s[i] - 97] == s[i]){
            }else{
                temp[s[i]-97] = s[i];
            }
        }else if(s[i] >= 65 && s[i] <= 90){
            if(temp[s[i] - 65] == s[i]){
            }else{
                temp[s[i]-65] = s[i]+32;
            }
        }

        i++;
    }

    for(int j = 0; j < 26; j++){
        if(!(temp[j] == 'a'+j)){
            m[counter] = 'a'+j;
            result = 1;
            counter++;
        }
    }

    if(result == 0){
        m[counter] = 0;
        return true;
    }
    return false;
}

int main(){

char s[] = " abC dEf GhI jKl MnO pQr StU vWx yZ ";
  char m[27] = { -1 };
  bool r = pangram(s, m);
  cout << '\"' << s << "\" " 
       << boolalpha << r << " \"" << m << "\"\n";

    return 0;
}