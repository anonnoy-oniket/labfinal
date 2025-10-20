#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    int n, W;
    cin >> n >> W;
    vector<int> wt(n), v(n);
    for (int i = 0; i < n; i++) cin >> wt[i];
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w)
                dp[i][w] = max(v[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    cout << "Maximum value: " << dp[n][W] << "\n";


    int i = n, w = W;
    vector<int> chosen;
    while (i > 0 && w > 0) {
        if (dp[i][w] != dp[i - 1][w]) {
            chosen.push_back(i - 1);  
            w -= wt[i - 1];
        }
        i--;
    }
    reverse(chosen.begin(), chosen.end());

    cout << "Items to be taken (0-indexed): ";
    for (int idx : chosen) cout << idx << " ";
    cout << "\n";

    cout << "DP Table:\n";
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            cout << dp[i][w] << " ";
        }
        cout << "\n";
    }

    return 0;
}
