#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> CombinationSum(int i,int target, vector<int> &ds,vector<int> can,int n){
if(target == )


}

int main(){
int target=7;
vector<int> ds;
vector<int> can ={2,3,6,7};
int n=can.size();

auto it = CombinationSum(0,target,ds,can,n);
for(auto a : it){
    for(auto b:a){
        cout<<b<<" ";
    }
    cout<<endl;
}

}