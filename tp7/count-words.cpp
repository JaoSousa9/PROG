#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void trimString(string w, const string word, int &count){

    int length = word.length();
    int l = w.length();
    string c;

    int flag = 0;
    if(length == l){
        for(auto &x : w){
            if(isupper(word.at(flag))){
                c += toupper(x);
            }else{
                c += tolower(x);
            }
            flag++;
        }
    }

    if(c == word){
        count++;
    }

}

int count(const string & fname, const string& word){
    ifstream ifs;
    int count  = 0;
    ifs.open(fname, ifstream::in);

    string line;
    

    while(getline(ifs, line, '\n')){
        size_t pos = 0;
        
        while((pos = line.find(' ')) != std::string::npos){
            string w = line.substr(0, pos);
            
            trimString(w, word, count);   
            
            line.erase(0, pos + 1);
        }

        string w = line.substr(0, pos);

        trimString(w, word, count);   
    }

    return count;

}

int main(){

    cout << count("p1_test_a.txt", "The") << '\n';
    cout << count("p1_test_b.txt", "you") << '\n';
    cout << count("p1_test_b.txt", "Collider") << '\n';

    return 0;
}