// replace all the strings with %20 in string.
#include<bits/stdc++.h>

using namespace std;

void space20(char *str){
    int cnt_spaces = 0;
    for (int i = 0;  str[i] != '\0'; i++) {
        if(str[i] == ' ') cnt_spaces++;
        }
    int index = strlen(str) + 2*cnt_spaces;
    str[index] = '\0';
    for(int i=strlen(str)-1;i>=0;i--){
        if(str[i] == ' ') {
            str[index -1]='0';
            str[index-2]='2';
            str[index-3]='%';
            index-=3;
        }
        else{
            str[index-1]=str[i];
            index--;
        }
    }
}

int main(){
char input[1000];
cin.getline(input,1000);
space20(input);
cout<<input;
}