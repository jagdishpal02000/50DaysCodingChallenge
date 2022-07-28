// a band i subsequence with consecutive numbers
// find the longest band and return it's length.

// the first approch can be to short the element --> NLogN;
// but we use onordered set here ---> O(N);

#include<bits/stdc++.h>
using namespace std;  

int longestBand(vector<int> arr){
int n=arr.size();

//Data structure onordered set
unordered_set<int> s;
int longest = 0;
for(auto i:arr){
    s.insert(i);
}
for(int i=0;i<n;i++){
    int target = arr[i] -1;
    // checking whether parent is present in the set or not
    if(s.find(target) != s.end()){
        continue;
    }

    // no parent present so band will start from here.
    else{
        int c=1;
        int newTarget = arr[i]+1; 
        while(s.find(newTarget) != s.end()){
        c++;
        newTarget++;
        }
        longest = max(longest,c);
    }

}
return longest;




}

int main(){
vector<int> arr{1,9,3,0,18,5,2,4,10,7,12,6};
cout<<longestBand(arr);
}