#include <iostream>
#include<vector>
#include<algorithm>
#define ll long long int 
using namespace std;

int find(vector<int>& ldr, int node){
    if(ldr[node]!= node){
        ldr[node]=find(ldr,ldr[node]);
    }
    return ldr[node];
}

void join(vector<int>& ldr, int rt,int lt){
    ldr[find(ldr,rt)]=find(ldr,lt);
}

int main() {
    int N, E; cin>>N>>E;
    vector<pair<int,pair<int,int>>> edges;
    vector<int> ldr(N+1);
    for (int node=1;node<=N;node++) ldr[node]=node;

    while(E--){
        int a,b,c; cin>>a>>b>>c;
        if(c<=0){
            join(ldr,a,b);
        }
        else{
            edges.push_back(make_pair(c,make_pair(a,b)));
        }
    }

    ll reward=0;
    sort(edges.begin(),edges.end());
    for(auto[c,p]:edges){
        int a=p.first,b=p.second;
        if(find(ldr,a)!=find(ldr,b)){
            join(ldr,a,b);
        }
        else{
            reward+=c;
        }

    }
    cout<<reward<<endl;
}
