#include<iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    bool found=false;
    int st=1;int end=10;
    for(int ctr=1;ctr<=N;ctr++){
        int curr;
        cin>>curr;
        if(!(curr>=st && curr<=end)){
            cout<<"No"<<endl;
            found=true;
            break;
        }
        if(ctr%10==0){
            st+=10;end+=10;

        }
    }
    if(!found) cout<<"Yes"<<endl;

}