#include <iostream>
#include<algorithm>
#include<vector>
#include<array>
using namespace std;
using combo = array<int,10>;
vector<combo> ans;
void dfs(int slot,int bal,combo arr){
    if(slot==1){
        arr[slot-1]=bal;
        ans.push_back(arr);
        return;
    }
    arr[slot-1]=0;
    while(bal>=0){
        dfs(slot-1,bal,arr);
        arr[slot-1]++;
        bal-=slot;

    }
}
int main() {
    int N,K; cin>>N>>K;
    combo arr{};
    dfs (N,K,arr);
    sort(ans.begin(),ans.end());
    for(combo c:ans){
        for(int i=0;i<N;i++){
            cout<<c[i]<<(i+1==N?"\n":" ");
        }
    }


    return 0;
}