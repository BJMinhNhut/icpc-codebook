#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}
template <typename H, typename... T> void read(vector<H> &h, T&... t) { for (auto &i : h) read(i); read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

void add(vector<int> &sol, int b, int e, int val) {
  int n = sol.size();
  for (int i = b; i != e ; i = (i + 1) % n) {
    sol[i] += val;
  }
}

void solve() {
  int n; cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  read(a);

  vector<int> sol(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      add(sol, i, j, a[i][j]);
    }
  }

  cout << (*max_element(sol.begin(), sol.end())) << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  //int tc; cin >> tc;
  //while (tc--)
    solve();
  return 0;
}

