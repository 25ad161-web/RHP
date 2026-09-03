class Solution {
    public int orangesRotting(int[][] g) {
     int m=g.length;
        int n=g[0].length;
        Queue<int[]> q=new LinkedList<>();
        int fresh =0;
        int days= 0;
        for (int row= 0;row< m;row++) {
            for (int col= 0;col< n;col++) {
                if (g[row][col]==2) {
                    q.add(new int[]{row, col});
                }
                if (g[row][col]==1) {
                    fresh++;
                }
            }
        }
        int[] diff={0,-1, 0, 1, 0};
        while (!q.isEmpty() && fresh >0) {
            int size=q.size();
            for (int i=0;i<size;i++) {
                int[] current=q.poll();
                int r=current[0];
                int c=current[1];
                for (int d =0;d<4;d++) {
                    int nr=r+diff[d];
                    int nc=c+diff[d+1];
                    if (nr>=0 && nr<m && nc>= 0 && nc<n && g[nr][nc] == 1) {
                        g[nr][nc]=2;
                        fresh--;
                        q.add(new int[]{nr, nc});
                    }
                }
            }
            days++;
        }

        if (fresh == 0)
            return days;

        return -1;
    }
    }    
    