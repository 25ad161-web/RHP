#include<iostream>
using namespace std;
int main(){
  int N,M;
  cin>>N>>M;
  int arr[N+2];
  for(int i=0;i<N+2;i++){
      arr[i]=0;
  }
  for(int i=0;i<M;i++){
    int l,r;
    cin>>l>>r;
      arr[l]+=1;
      arr[r+1]-=1;
    
  }
 int  minv=200005;
  for(int i=1;i<=N;i++){
    arr[i+1]+=arr[i];
    minv=min(minv,arr[i]);
  
}
cout<<minv<<endl;
    
}