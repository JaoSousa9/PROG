#ifndef __print_string_h__
#define __print_string_h__

#include <string>
#include <vector>
#include <iostream>
using namespace std;

//! Print vector of strings.
void print(const vector<string>& v) {
  cout << "[ ";
  for (size_t i = 0; i < v.size(); i++) {
    cout << '\"' << v[i] << "\" ";
  }
  cout << "]\n";
}

#endif // __print_string_h__

void split(const string& s, vector<string>& v){

    int pos = 0;
    int temp = 0;
    while((temp = s.find(' ', pos)) != -1){
        if(s.substr(pos, temp-pos)!= ""){
            v.push_back(s.substr(pos, temp-pos));
        }
        pos = temp +1;
    }
    if(s.substr(pos, temp-pos)!= ""){
        v.push_back(s.substr(pos));
    }
}
    

int main(){

    string s = "C++ LEIC FCUP FEUP";
    vector<string> v;
    split(s, v);
    print(v);

    return 0;
}