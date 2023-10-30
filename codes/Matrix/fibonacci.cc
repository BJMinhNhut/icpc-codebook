int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //F[0] = 0, F[1] = 1, F[n] = F[n - 1] + F[n - 2]
    //[F[n]    ]   [1, 1] * [F[n - 1]]
    //|        | = |    |   |        |
    //[F[n - 1]]   [1, 0] * [F[n - 2]]

    long long n;
    cin >> n;
    Matrix a(2, 2);
    a.val[0][0] = 1;
    a.val[0][1] = 1;
    a.val[1][0] = 1;
    a.val[1][1] = 0;

    if (n == 0) {
        cout << 0 << "\n";
        return 0;
    }

    Matrix b(2, 1);
    b.val[0][0] = 1;
    b.val[1][0] = 0;

    Matrix c = a.matrix_pow(n - 1) * b;

    cout << c.val[0][0];
    return 0;
}