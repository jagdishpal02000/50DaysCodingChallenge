#include<bits/stdc++.h>

using namespace std;


int perfectSumR(int arr[],int n,int sum){
    if(n==0 && sum==0) return 1;
    if(sum==0) return 1;
    if(n==0) return 0;
    return perfectSumR(arr,n-1,sum-arr[n-1])+perfectSumR(arr,n-1,sum);
}

int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int t[n+1][sum+1];
        int mod=100000007;
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0) t[i][j]=0;
                if(j==0) t[i][j]=1;
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1] <= j){
                    t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];
                }
                else t[i][j] = t[i-1][j];
            }
        }
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                cout<<t[i][j]<<" ";
            }
            cout<<endl;
        }
        
        return t[n][sum]%mod;
	}
	  

int main(){
    int arr[] = {9 ,7 ,0 ,3 ,9 ,8 ,6 ,5 ,7, 6};
    int sum = 31;
    int n=10;
    cout<<perfectSumR(arr, n,sum);
}