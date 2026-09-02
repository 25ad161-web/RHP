#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long int 
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<int> arr(N);
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    ll sum=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<N;i++){
        auto lb=lower_bound(arr.begin(),arr.end(),arr[i]);
        auto ub=upper_bound(arr.begin(),arr.end(),arr[i]);
        int g=arr.end()-ub;
        int l=lb-arr.begin();
        sum+=1LL*g*l;
    }
    cout<<sum<<endl;
}