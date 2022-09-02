#include<bits/stdc++.h>
using namespace std;

vector<int> solution(string s1,string s2){
int k=s2.size();
int n=s1.size();
int i=0,j=0;
vector<int>ans;

int mapArr[26];
memset(mapArr,0,sizeof(mapArr));

for(int p=0;p<k;p++){
mapArr[s2[p]-'a']++;
}

while(j<n){
if(j-i+1 == k){
mapArr[s1[j]-'a']--;
int flag=1;
for(int p=0;p<26;p++){
    if(mapArr[p] != 0) flag=0;
}
if(flag){
    // ans++;
    ans.push_back(i);
}
// mapArr[s1[i]-'a']--;
mapArr[s1[i]-'a']++;
j++;
i++;
}
else
mapArr[s1[j++]-'a']--;

}

return ans;
}

int main(){
string s1="abab";
string s2="ab";
auto a=solution(s1,s2);
for(auto b:a){
    cout<<b<<" ";
}
}