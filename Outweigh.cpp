#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
void solve(){
    int N;
    cin>>N;
    vector<int> A(N);
    vector<int> B(N);
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<N;i++) cin>>B[i];
    ll am=0,bm=0;
    for(int i=0; i<N;i++){
        if(A[i]>B[i]) am+=A[i]-B[i];
        else if(B[i]>A[i]) bm+=B[i]-A[i];
    }
    if(am==0){
        cout<<"No"<<endl;
        return;
    }
    ll amweight=(bm/am)+2;
    vector<ll> ans;
    for(int i=0;i<N;i++){
        if(A[i]<=B[i]) ans.push_back(1LL);
        else ans.push_back(amweight);
    }
    cout<<"Yes"<<endl;
    for(ll wt: ans) cout<<wt<<" ";
    cout<<endl;
}
int main(){
    solve();
}