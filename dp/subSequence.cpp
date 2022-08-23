#include <bits/stdc++.h>
using namespace std;

void printSubSequ(int i, vector<int> &ds, vector<int> arr, int n)
{
    if (i >= n)
    {
        if (ds.size() == 0)
        {
            cout << "{}" << endl;
            return;
        }
        for (auto it : ds)
            cout << it << " ";
        cout << endl;
        return;
    }
    ds.push_back(arr[i]);
    printSubSequ(i + 1, ds, arr, n);
    ds.pop_back();
    printSubSequ(i + 1, ds, arr, n);
}

void printSubSequTarget(int i, vector<int> &ds, vector<int> arr, int n, int target, int sum)
{
    if (i >= n)
    {
        if (sum == target)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
        }
        return;
    }
    ds.push_back(arr[i]);
    sum += arr[i];
    printSubSequTarget(i + 1, ds, arr, n, target, sum);
    ds.pop_back();
    sum -= arr[i];
    printSubSequTarget(i + 1, ds, arr, n, target, sum);
}

bool printSubSequTargetOne(int i, vector<int> &ds, vector<int> arr, int n, int target, int sum)
{
    if (i >= n)
    {
        if (sum == target)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
            return true;
        }
        return false;
    }
    ds.push_back(arr[i]);
    sum += arr[i];
    if (printSubSequTargetOne(i + 1, ds, arr, n, target, sum))
        return true;
    ds.pop_back();
    sum -= arr[i];
    if (printSubSequTargetOne(i + 1, ds, arr, n, target, sum))
        return true;
    return false;
}

int countTargetSubSequ(int i, vector<int> &ds, vector<int> arr, int n,int target,int sum)
{
    if (i >= n)
    {
        if(target == sum) return 1;
        return 0;
    }
    ds.push_back(arr[i]);
    sum+= arr[i];
    int l = countTargetSubSequ(i + 1, ds, arr, n,target,sum);
    ds.pop_back();
    sum-= arr[i];
    int r = countTargetSubSequ(i + 1, ds, arr, n,target,sum);
    return l+r;
}
int main()
{
    vector<int> arr = {1, 2, 1};
    int n = arr.size();
    int target = 2;
    vector<int> ds;
    cout<<countTargetSubSequ(0, ds, arr, n, target, 0);
}