#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int main(){
	int R,C,K;
	cin >> R >> C >> K;
	
	vector<vector<char>> g(R,vector<char>(C));
	
	for(int i = 0;i<R;i++){
		for(int j = 0;j<C;j++){
			cin >> g[i][j];
		}
	}
	
	vector<bool> br(R,false);
	vector<bool> bc(C,false);
	
	for(int i = 0;i<R;i++){
		for(int j = 0;j<C;j++){
			if(g[i][j] == '#'){
				br[i] = true;
				bc[j] = true;
			}
		}
	}
	
	vector<vector<bool>> vis(R,vector<bool>(C,false));
	queue<pair<int,int>> q;
	
	for(int i = 0;i<R;i++){
		for(int j = 0;j<C;j++){
			if(!br[i] && !bc[j]){
				q.push(make_pair(i,j));
				vis[i][j] = true;
			}
			
		}
	}
	
	int hpos = 0;
	int cellcnt = 0;
	const int dir[] = {0,1,0,-1,0};
	
	while(!q.empty() && hpos <= K){
		hpos++;
		int qsize = q.size();
		cellcnt += qsize;
		
		while(qsize--){
			int row = q.front().first;
			int col = q.front().second;
			q.pop();
			
			for(int i = 0;i<4;i++){
				int nr = row+dir[i];
				int nc = col+dir[i+1];
				
				if(nr >= 0 && nr < R && nc >= 0 && nc < C ){
					if(g[nr][nc] == '.' && !vis[nr][nc]){
						q.push(make_pair(nr,nc));
						vis[nr][nc] = true;
					}
				}
			}
		}
		
	}
	cout << cellcnt << endl;
}