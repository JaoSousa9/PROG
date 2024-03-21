#include <iostream>
#include <string>

using namespace std;

bool pangram(const string& s, string& m){
    bool result = 0;
    char temp[27];

    for(char c : s){
        if(c >= 97 && c <= 122){
            if(temp[c - 97] == c){
            }else{
                temp[c-97] = c;
            }
        }else if(c >= 65 && c <= 90){
            if(temp[c - 65] == c){
            }else{
                temp[c-65] = c+32;
            }
        }
    }

    for(int j = 0; j < 26; j++){
        if(!(temp[j] == 'a'+j)){
            m.push_back('a'+j);
            result = 1;
        }
    }

    if(result == 0){
        return true;
    }
    return false;
}

int main(){

string s = "A quick brown fox jumps over a classy dog";
  string m = "";
  bool r = pangram(s, m);
  cout << '\"' << s << "\" " 
       << boolalpha << r << " \"" << m << "\"\n";

    return 0;
}