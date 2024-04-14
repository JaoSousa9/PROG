#include "wc.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;



void count(const string & fname, int &words, int &lines){
    ifstream ifs;
    ifs.open(fname, ifstream::in);

    string line;
    

    while(getline(ifs, line, '\n')){
        size_t pos = 0;
        
        while((pos = line.find(' ')) != std::string::npos){
            string w = line.substr(0, pos);
            line.erase(0, pos + 1);
            if(w.length() > 0){
                words ++;
            }

        }
        string w = line.substr(0, pos);
        if(w.length() > 0){
                words ++;
            }
        lines++;
    }

}

wcresult wc(const string& filename){

    ifstream ifs;
    int lines = 0, words = 0, bytes = 0;

    ifs.open(filename, ios::binary);

    char byte;
    while (ifs.get(byte)) {
        bytes++;
    }
    count(filename, words, lines);

    wcresult ret;
    ret.bytes = bytes;
    ret.lines = lines;
    ret.words = words;

    return ret;
}

int main(){

    wcresult r = wc("p2_test1.txt"); 
    cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n';

    r = wc("p2_test2.txt"); 
    cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n';

    r = wc("p2_test3.txt"); 
  cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; 


    return 0;
}