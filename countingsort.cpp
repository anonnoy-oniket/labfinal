#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    vector<int> count(maxVal + 1, 0);
    for (int x : arr) count[x]++;
    int idx = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i]--) arr[idx++] = i;
    }
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    countingSort(arr);

    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
