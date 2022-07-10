// question : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
        int store[201]={0};
        // 0 to 99 for -ve
        // 100 to 201 for +ve
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                store[(nums[i]*-1)-1]++;
                
                cout<<nums[i]<<" "<<nums[i]+1<<" ";
            }
            else if(nums[i] == 0){
                store[100]++;
                cout<<nums[i]<<" "<<100<<" ";

            }
            else{
                store[nums[i]+100]++;
                cout<<nums[i]<<" "<<nums[i]+100<<" ";

            }
        }
        int ans=0;
        int k=0;
        for(int i=0;i<201;i++){
            if(store[i] > 0) {
                cout<<i<<" ";
                nums[k]=store[i];
                if(i >= 0 && i <= 99){
                    nums[k]=(i+1)*-1;
                }
               else if(i==100){
                    nums[k]=0;
                }
                else{
                    nums[k]=i-100;
                }
                k++;
                ans++;
            }
            
        }
        for(int i=ans;i<nums.size();i++){
            nums[i]=INT_MAX;
        }
        sort(nums.begin(),nums.end());
        return ans;
    }

int main(){
// vector<int> nums{0,0,1,1,1,2,2,3,3,4};
vector<int> nums{-3,-1,0,0,0,3,3};
auto k = removeDuplicates(nums);
cout<<endl;
for(int i=0;i<k;i++){
    cout<<nums[i]<<" ";
}
}