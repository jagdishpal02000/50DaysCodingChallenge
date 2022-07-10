//Refer to this question : https://leetcode.com/problems/longest-mountain-in-array/

#include<bits/stdc++.h>
using namespace std;    
 
int longestMountain(vector<int> arr){
  int n=arr.size(); 
  int longest=0;
  for(int i=1; i<=n-2;){  

    //check whether element is is peak or not
    if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
        int cnt=1;
        int j=i;
        while(j>=1 && arr[j]>arr[j-1]){
            j--;
            cnt++;
        }
        while(i<=n-2 && arr[i]>arr[i+1]){
            i++;
            cnt++;
        }
        longest=max(longest,cnt);

    }
    else{
        i++;
    }



  } 
  return longest;
}

int main(){
vector<int> arr{5,6,1,2,3,4,5,4,3,2,0,123,-2,4};

cout<<longestMountain(arr)<<endl;

}