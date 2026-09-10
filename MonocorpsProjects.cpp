#include<iostream>
#define ll long long int
using namespace std;
void solve(){
    ll x,y,k,i;cin>>x>>y>>k;
    ll total=0;
    for( i=0;i<k;i++){
    ll a=x+i;
    ll b=y+i;
    if(b%a==y-x) {break;}
    total+=b%a;
}
    if(k>i) total+=(k-i)*(y-x);
    cout<<total<<endl;
}
int main(){
    int T;cin>>T;
    for(int i=0;i<T;i++){
        solve();
    }
}