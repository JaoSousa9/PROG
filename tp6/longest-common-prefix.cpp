#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longest_prefix(const vector<string>& v){

    int i, j, k;
    int size = (int)v.size();
    string smallestWord = v[0];
    for(i = 1; i < size ; i++){
        if(v[i].size() < smallestWord.size()){
            smallestWord = v[i];
        }
    }

    int prefixSize = smallestWord.size();
    string result = "";
    for(j = 1; j < prefixSize; j++){
        for(k = 0; k < size ; k++){
            if(!(v[k].substr(0, j) == smallestWord.substr(0,j))){
                return result;
            }
        }
        result = smallestWord.substr(0,j);
    }

    return result;

}

int main(){

    cout << "\"" << longest_prefix({ "geezer", "geeksforgeeks", "geeks", "geek",  }) << "\"\n";

    return 0;
}