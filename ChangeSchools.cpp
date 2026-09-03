#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int N,K; cin>>N>>K;
    vector<int> cnt(K+1,0);
    for(int s=1;s<=N;s++){
        int cl;cin>>cl;
        cnt[cl]++;
    }
    int maxi=*max_element(cnt.begin(),cnt.end());
    int ans=0;
    for(int cl=1;cl<=K;cl++){
        if(cnt[cl]>=maxi-1){
            ans++;
        }
    }

    cout<<ans<<endl;
}