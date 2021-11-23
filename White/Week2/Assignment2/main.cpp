#include <iostream>
#include <string>
using namespace std;

bool IsPalindrom(string w){
   
    bool result = true;
    for (int i = 0; i < w.size()/2; i++) {
        if(w[i] != w[w.size() - 1 -i]){
        result = false;
        break;
        }
    }
    return result;
}

int main(){

    return 0;
}