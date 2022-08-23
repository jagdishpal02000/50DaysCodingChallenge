#include<iostream>
using namespace std;

int main(){
    int arr[]={3,4,1,5,-2,-1,4,3};
    int n=sizeof(arr)/sizeof(arr[0]); 
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}