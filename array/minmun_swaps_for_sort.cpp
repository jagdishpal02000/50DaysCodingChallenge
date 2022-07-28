// minimun swaps required to sort the given array

#include <iostream>
using namespace std;

int minSwap(vector<int> arr){
    // know the actual position of the element in the array
    // store the current index.
    int n=arr.size();
    pair<int,int>ap[n];
    for(int i=0; i<n; i++){
        ap[i].first = arr[i];
        ap[i].second = i;
    }
    sort(ap,ap+n);
    vector<bool> visited(n,false);
    for(int i=0; i<n; i++){
        // if element is visited or element is in right position
        int old_pos = ap[i].second;
        if(visited[i] == true || old_pos == i){ 
            continue;
        }
        // if visit first time.
        int node = i;
        int cycle=0;
        while(visited[i] == false){
            visited[node] = true;
            int next_node= ap[node].second;
            node=next_node;
            cycle++;
        }
        ans+=cycle-1;
    }
    return ans;
}

int main(){

}