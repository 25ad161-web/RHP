#include<iostream>
#include<vector>
using namespace std;
void solve(){
    int N;
    cin>>N;
    vector<int> a(N);
    for(int i=0;i<N;i++) cin>>a[i];
    int cnt=0;
    for(int i=0;i<N;i++){
        if(a[i]==0) cnt++;
    }
    if(a[0]==0&&a[N-1]==0) {
        cout<<0<<endl; }
    else if(a[0]!=0&&a[N-1]!=0){
        if(cnt>=2) {cout<<2<<endl;}
        else cout<<-1<<endl;
    }
    else {
        if(cnt>=2){ cout<<1<<endl;}
        else cout<<-1<<endl;
    }  
        
    

}
int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++) solve();
}