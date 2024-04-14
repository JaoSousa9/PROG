#include "smatrix.h"
#include <iostream>
#include <vector>

using namespace std;

void sum(const smatrix& a, const smatrix& b, smatrix& r){

    for(auto pos :  a){
        for(auto posb : b){
            if(pos.row == posb.row && pos.col == posb.col){
                if(pos.value + posb.value != 0){
                    r.push_back({pos.row, pos.col, pos.value + posb.value});
                }
            }else{
                bool existsa = false;
                bool existsb = false;
                for(auto posr : r){
                    if(posr.col == pos.col && posr.row == pos.row){
                        existsa = true;
                    }
                    if(posr.col == posb.col && posr.row == posb.row){
                        existsb = true;
                    }
                }

                if(!existsa){
                    r.push_back({pos.row, pos.col, pos.value});                    
                }
                if(!existsb){
                    r.push_back({posb.row, posb.col, posb.value});                    
                }
            }
        }
    }
}

int main(){

    smatrix r;
    sum({ {0, 0, 1}, {0, 1, 2}, {5, 10, 20}, {99, 12, 32} },
      { {0, 0, 1}, {0, 1, -2}, {10, 5, 20}, {99, 10, 30}, {99, 11, 31} },
      r);
    print(r);

    return 0;
}