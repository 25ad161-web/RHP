#include<iostream>
#include<map>
using namespace std;
int main(){
    int N;
    cin>>N;
    map<int,int> m;
    for(int i=0;i<N;i++){
        int curr;
        cin>>curr;
        m[curr]++;
    }
    int ans=0;
    for(int i=0;i<N;i++){
        if(m[i]&1){
            ans++;
        }
    }
    cout<<ans<<endl;
}