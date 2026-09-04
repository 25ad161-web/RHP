#include <iostream>
#include <vector>
using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    int r, c;
    cin >> r >> c;

    int sum = 0;
    int adj[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},           {0, 1},
        {1, -1},  {1, 0},  {1, 1}
    };

    for (int k = 0; k < 8; k++) {
        int row = r + adj[k][0];
        int col = c + adj[k][1];
        if (row >= 0 && col >= 0 && row < rows && col < cols) {
            sum += matrix[row][col];
        }
    }

    cout << "Adjacent cells Sum = " << sum << endl;
    return 0;
}