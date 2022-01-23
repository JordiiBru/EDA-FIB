#include <iostream>
#include <vector>

using namespace std;

int fix_point (const vector<int>& S, int a, int esq, int dre) {
  if (esq > dre) return -1;
  else {
    int m = (esq+dre)/2;
    if (a+S[m] < m) return fix_point(S,a,m+1,dre);
    else if (a+S[m] > m) return fix_point(S,a,esq,m-1);
    else if (m-1 < esq or a+S[m-1] != m-1) return m;
    else return fix_point(S,a,esq,m-1);
  }
}

int fix_point (const vector<int>& S, int a) {
  return fix_point(S,a,1,S.size()-1);
}

int main() {
  int n;
  int seq = 0;
  while (cin >> n) {
    ++seq;
    cout << "Sequence #" << seq << endl;
    vector<int> S(n+1);
    for (int i =1; i <= n; ++i) cin >> S[i];
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i){
      int a;
      cin >> a;
      int p = fix_point(S,a);
      if (p == -1) cout << "no fixed point for " << a << endl;
      else cout << "fixed point for " << a << ": " << p << endl;
    }
    cout << endl;
  }
}