// devide the string with a delimiter.
#include<bits/stdc++.h>
using namespace std;

int main(){
    string input;
    getline(cin,input);
    
    stringstream ss(input);
    vector<string> output;
    string token;
    while(getline(ss,token,' ')){
        output.push_back(token);
    }
    for(auto a: output){
        cout<<a<<",";
    }
}