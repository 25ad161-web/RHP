#include<iostream>
#include<set>
using namespace std;
int main(){
    int L,Q;
    cin>>L>>Q;
    set<int> s;
    s.insert(0);
    s.insert(L);
    while(Q--){
        int c,x;
        cin>>c>>x;
        if(c==1){
            s.insert(x);
        }
        else{
            auto it=s.upper_bound(x);
            cout<<*it-*(prev(it))<<endl;
        }
    }
}