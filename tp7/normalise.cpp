#include "print.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void normalise(const string& input_fname, const string& output_fname){

    ifstream ifs;
    ofstream ofs;

    ifs.open(input_fname, ifstream::in);
    ofs.open(output_fname, ofstream::out);

    string line;

    while(getline(ifs, line, '\n')){
        size_t pos = 0;
        if(line.length() > 0){
            while((pos = line.find(' ')) != std::string::npos){
                string w = line.substr(0, pos+1);
                line.erase(0, pos+1);
                if(w != " " && w != ""){
                    for(char &a : w){
                        a = toupper(a);
                    }
                    ofs << w; 
                }
            }
            string w = line.substr(0, pos);
            if(w.length() > 0){
                ofs << w + "\n";                 
            }else{
                ofs << "\n";
            }
        }
    }

    
}

int main(){

    normalise("p3_test1.txt", "p3_test1_out.txt"); 
    print("p3_test1_out.txt");

    normalise("p3_test2.txt", "p3_test2_out.txt"); 
    print("p3_test2_out.txt");

    normalise("p3_test3.txt", "p3_test3_out.txt"); 
    print("p3_test3_out.txt");

    normalise("p3_test4.txt", "p3_test4_out.txt"); 
    print("p3_test4_out.txt");

    return 0;
}