#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> M;

M add(const M &A, const M &B) {
    int n = A.size();
    M C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

M sub(const M &A, const M &B) {
    int n = A.size();
    M C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

M strassen(const M &A, const M &B) {
    int n = A.size();
    M C(n, vector<int>(n));
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }
    int k = n / 2;
    M A11(k, vector<int>(k)), A12(k, vector<int>(k)), A21(k, vector<int>(k)), A22(k, vector<int>(k));
    M B11(k, vector<int>(k)), B12(k, vector<int>(k)), B21(k, vector<int>(k)), B22(k, vector<int>(k));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }
    M M1 = strassen(add(A11, A22), add(B11, B22));
    M M2 = strassen(add(A21, A22), B11);
    M M3 = strassen(A11, sub(B12, B22));
    M M4 = strassen(A22, sub(B21, B11));
    M M5 = strassen(add(A11, A12), B22);
    M M6 = strassen(sub(A21, A11), add(B11, B12));
    M M7 = strassen(sub(A12, A22), add(B21, B22));
    M C11 = add(sub(add(M1, M4), M5), M7);
    M C12 = add(M3, M5);
    M C21 = add(M2, M4);
    M C22 = add(sub(add(M1, M3), M2), M6);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }
    return C;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    int n;
    cin >> n;
    M A(n, vector<int>(n)), B(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];
    M C = strassen(A, B);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << C[i][j] << " ";
        cout << "\n";
    }
}


