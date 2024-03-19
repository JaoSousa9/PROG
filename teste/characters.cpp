#include <iostream>

using namespace std;


int main(){

    char character;
    cin >> character;

    if((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z') ){
        cout << "LETTER" << endl;
    }else if(character >= '0' && character <= '9'){
        cout << "DIGIT" << endl;
    }else{
        cout << "OTHER";
    }

    return 0;
}