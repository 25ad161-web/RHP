#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#define ll long long int
#define INF 2e9
using namespace std;

void solve(){
	string a,b;
    cin>>a>>b;
    int R=a.length(),C=b.length();
    vector<int> pa(R+1,0),pb(C+1,0);

    for(int i=0;i<=R;i++){
        pa[i]=(pa[i-1]+(a[i-1]-'0'))%10;

    }
    for(int i=0;i<=C;i++){
        pb[i]=(pa[i-1]+(a[i-1]-'0'))%10;

    }
    if(pa[R]!=pb[C]){
        cout<<"-1"<<endl; 
        return;

    }
	vector<vector<int>> dp(R+1,vector<int>(C+1,0));
    for(int i=1;i<=R;i++){
        for(int j =1;j<=C;j++){
            if(pa[i]==pb[j]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[R][C] <<endl;
	
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc=1;
	while(tc--) solve();
}