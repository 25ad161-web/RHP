#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int;
using namespace std;
int main(){
    int N;cin>>N;
    vector<pair<int,int>> arr(N);
    for(int i=0;i<N;i++){
        int H,L;
        cin>>H>>L;
        arr[i]=make_pair(H,L);

    }
    sort(arr.begin(),arr.end(),greater<>());
    vector<int> LtArr;
    vector<int> HmaxArr;
    int prev=0;
    for(auto[H,L]:arr){
        if(L>prev){
            prev=L;
            HmaxArr.push_back(H);
            LtArr.push_back(L);

        }
    }
    int Q;cin>>Q;
    while(Q--){
        int t;
        cin>>t;
        auto it=upper_bound(LtArr.begin(),LtArr.end(),t);
        int index=it-LtArr.begin();
        cout<<HmaxArr[index]<<endl;
    }
    
}