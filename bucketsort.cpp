#include <bits/stdc++.h>
using namespace std;

void bucketSort(vector<float>& arr) {
    int n = arr.size();
    vector<vector<float>> buckets(n);

    for (float x : arr) {
        int idx = n * x; // assuming x in [0,1)
        buckets[idx].push_back(x);
    }

    for (auto &bucket : buckets) sort(bucket.begin(), bucket.end());

    int idx = 0;
    for (auto &bucket : buckets)
        for (float x : bucket)
            arr[idx++] = x;
}

int main() {
    int n; cin >> n;
    vector<float> arr(n);
    for (float &x : arr) cin >> x;

    bucketSort(arr);

    for (float x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
