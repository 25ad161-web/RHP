#include<iostream>
using namespace std;
void solve(){
    int N;
    cin>>N;
    int odd=0,eoq=0,eeq=0;
    for(int ctr=0;ctr<N;ctr++){
        int curr;
        cin>>curr;
        if(curr&1) odd++;
        else{
            int q=curr/2;
            if(q&1) eoq++;
            else eeq++;
        }
    }
    cout<<max(odd,max(eoq,eeq))<<endl;
}
int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        solve();
    }
}