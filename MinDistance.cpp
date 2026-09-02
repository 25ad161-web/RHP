#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<set>
using namespace std;
void solve(){
    int R;cin>>R;
    map<int,vector<pair<int,int>>> g;
    set<int> vis;
    while(R--){
        int src,dest,dist;
        cin>>src>>dest>>dist;
        g[src].push_back(make_pair(dest,dist));
        g[dest].push_back(make_pair(src,dist));

    }
    int st,end;
    cin>>st>>end;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push(make_pair(0,st));
    while(!pq.empty()){
        auto[cd,city]=pq.top();
        pq.pop();
        if(vis.find(city) == vis.end()){
            vis.insert(city);
            if(city==end){
                cout<<cd;
                return ;
            }
            for(auto[oc,ocd]:g[city]){
                if(vis.find(oc) == vis.end()){
                    pq.push(make_pair(cd+ocd,oc));
                }
            }
        }
    }
    cout<<"City"<<end<<" cannot be reached from the City"<<st;

}
int main(){
    solve();
}