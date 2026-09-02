#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
const int diff[5]={0,1,0,-1,0};
void dfs(int r,int c,int i,int j,vector<string>& g)
{
    g[i][j]='#';
    for(int k=0;k<4;k++)
    {
        int ni=i+diff[k];
        int nj=j+diff[k+1];
        if(ni>=0 && ni<r && nj>=0 && nj<c && g[ni][nj]=='.')
        {
            dfs(r,c,ni,nj,g);
        }
    }
}
int main(){
    int r,c;
    int cnt=0;
    cin>>r>>c;
    vector<string> g(r);
    for(int i=0;i<r;i++)
    {
        cin>>g[i];
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(g[i][j]=='.'){
                cnt++;
                dfs(r,c,i,j,g);
            }
        }
        
    }
    cout<<cnt;
}