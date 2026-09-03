#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    long long K;
    if (!(cin >> N >> M >> K)) return 0;

    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
 
    vector<bool> ate(N, false);
    long long current_window_sum = 0;

    for (int i = 0; i < N; i++) {
        
        if (i >= M && ate[i - M]) {
            current_window_sum -= A[i - M];
        }
 
        if (current_window_sum + A[i] <= K) {
            ate[i] = true;
            current_window_sum += A[i];
            cout << "Yes\n";
        } else {
            ate[i] = false;
            cout << "No\n";
        }
    }

    return 0;
}