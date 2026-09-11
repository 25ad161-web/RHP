#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<int> cmn(26,50);
    for(int i=0;i<N;i++) {
        string s;
        cin>>s;
        vector<int> ans(26,0);
        for(char ch:s){
            ans[(ch-'a')]++;
        }
        for(int i=0;i<26;i++){
            cmn[i]=cmn[i]<=ans[i]?cmn[i]:ans[i];
        }
    }
    for(int i=0;i<26;i++){
        while(cmn[i]--){
            cout<<char('a'+i);
        }
        
    }
}