#include <bits/stdc++.h>

using namespace std;

const int N  = 1030;
const int mod = 998244353;

struct Matrix {
    int numRow, numCol;
    vector <vector <int>> val;

    Matrix (int numRow, int numCol): numRow(numRow), numCol(numCol) {
        val.resize(numRow);
        for (int i = 0; i < numRow; ++i) {
            val[i].resize(numCol, 0);
        }
    }

    void print() {
        for (int i = 0; i < numRow; ++i) {
            for (int j = 0; j < numCol; ++j) {
                cout << val[i][j] << " ";
            }
            cout << "\n";
        }
    }

    Matrix operator * (const Matrix &other) const {
        assert(numCol == other.numRow);
        Matrix res(numRow, other.numCol);
        for (int i = 0; i < numRow; ++i) {
            for (int j = 0; j < other.numCol; ++j) {
                for (int k = 0; k < numCol; ++k) {
                    res.val[i][j] = (res.val[i][j] + 1LL * val[i][k] * other.val[k][j]) % mod;
                }
            }
        }
        return res;
    }

    Matrix & operator *= (const Matrix &o) {
        *this = *this * o;
        return *this;
    }

    Matrix matrix_pow(long long e) {
        Matrix res(numRow, numCol);
        Matrix tmp = *this;
        for (int i = 0; i < numRow; ++i) {
            res.val[i][i] = 1;
        }
        if (e == 0) return res;
        while (true) {
            if (e & 1) res *= tmp;
            if ((e >>= 1) == 0) break;
            tmp *= tmp;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    Matrix a(n, m), b(m, k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++ j) {
            cin >> a.val[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++ j) {
            cin >> b.val[i][j];
        }
    }

    Matrix c = a * b;

    c.print();
    return 0;
}