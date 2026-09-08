#include<iostream>
#include<vector>
using namespace std;
void solve(){
    int N,M;
    cin>>N>>M;
    vector<int> cnt(M+1,0);
    for(int ctr=1;ctr<=N;ctr++){
        int curr;
        cin>>curr;
        cnt[curr]++;
    }
    vector<int> psum(M+1,0);
    for(int i=1;i<=M;i++){
        psum[i]=psum[i-1]+cnt[i];

    }
    int ans=0;
    for(int a=1;a<=M;a++){
        int carrotcnt=psum[M]-psum[a-1];
        if(2*a<=M){
            carrotcnt+=cnt[2*a];
        }
        ans=max(ans,carrotcnt);
    }
    cout<<ans<<endl;
    
}
int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        solve();
    }
}