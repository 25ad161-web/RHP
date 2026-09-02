#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

// Direction vectors: Left, Right, Up, Down
const int dr[4] = {0, 0, -1, 1};
const int dc[4] = {-1, 1, 0, 0};
const char dir[4] = {'L', 'R', 'U', 'D'};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    if (!(cin >> r >> c)) return 0;

    vector<string> g(r);
    int start_r = -1, start_c = -1;
    int end_r = -1, end_c = -1;

    for (int i = 0; i < r; i++) {
        cin >> g[i];
        for (int j = 0; j < c; j++) {
            if (g[i][j] == 'A') {
                start_r = i;
                start_c = j;
            } else if (g[i][j] == 'B') {
                end_r = i;
                end_c = j;
            }
        }
    }

    // Stores parent direction move used to reach cell (i, j)
    vector<vector<char>> path(r, vector<char>(c, 0));
    // Stores parent cell index for backtracking
    vector<vector<pair<int, int>>> parent(r, vector<pair<int, int>>(c, {-1, -1}));

    queue<pair<int, int>> q;
    q.push({start_r, start_c});
    
    // Mark start as visited by modifying the grid
    g[start_r][start_c] = '#';

    bool found = false;

    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        if (row == end_r && col == end_c) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nr < r && nc >= 0 && nc < c && g[nr][nc] != '#') {
                g[nr][nc] = '#'; // Mark visited
                path[nr][nc] = dir[i];
                parent[nr][nc] = {row, col};
                q.push({nr, nc});
            }
        }
    }

    if (!found) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        
        string steps = "";
        int curr_r = end_r, curr_c = end_c;

        // Backtrack path from B to A
        while (curr_r != start_r || curr_c != start_c) {
            steps.push_back(path[curr_r][curr_c]);
            auto [pr, pc] = parent[curr_r][curr_c];
            curr_r = pr;
            curr_c = pc;
        }

        reverse(steps.begin(), steps.end());

        cout << steps.length() << "\n";
        cout << steps << "\n";
    }

    return 0;
}