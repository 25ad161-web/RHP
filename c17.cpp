#include <iostream>
#include <set>
using namespace std;
int main() {
    int N;
    cin>>N;
    set<int> s;
    for(int i=0;i<N;i++){
        int n;
        cin>>n;
        s.insert(n);
        
    }
    cout<<size(s)<<endl;
    for(int v:s){
        cout<<v<<" ";
    }
    return 0;
}