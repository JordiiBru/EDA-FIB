#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> indeg;
vector<int> p;
vector<int> mkd;

void f(int k) {
  if (k == n) {
    cout << p[0];
    for (int i = 1; i < n; ++i) {
      cout << ' ' << p[i];
    }
    cout << endl;
  }
  else {
    for (int v = 0; v < n; ++v) {
      if (indeg[v] == 0) {
        indeg[v] = -1;
        for (int u : g[v]) --indeg[u];
        mkd[v] = true;
        p[k] = v;
        f(k+1);
        mkd[v] = false;
        for (int u : g[v]) ++indeg[u];
        indeg[v] = 0;
      }
    }
  }
}

int main() {
  cin >> n >> m;
  g = vector<vector<int>>(n);
  indeg = vector<int>(n, 0);
  while (m--) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    ++indeg[y];
  }
  p = vector<int>(n);
  mkd = vector<int>(n, false);
  f(0);
}