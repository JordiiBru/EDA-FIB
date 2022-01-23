#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> mult(const vector<vector<int>>& A,
			 const vector<vector<int>>& B,
			 int m) {
  return {
    { (A[0][0]*B[0][0] + A[0][1]*B[1][0])%m, (A[0][0]*B[0][1] + A[0][1]*B[1][1])%m},
      { (A[1][0]*B[0][0] + A[1][1]*B[1][0])%m, (A[1][0]*B[0][1] + A[1][1]*B[1][1])%m}};
}

vector<vector<int>> potencia(const vector<vector<int>>& M, int n, int m) {
  if (n == 0) return {{1,0},{0,1}};
  else {
    vector<vector<int>> aux = potencia(M,n/2,m);
    if (n%2 == 0) return mult(aux,aux,m);
    else return mult(mult(aux,aux,m),M,m);
  }
}

int main() {
  vector<vector<int>> M(2,vector<int>(2));
  while (cin >> M[0][0] >> M[0][1] >> M[1][0] >> M[1][1]) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> R = potencia(M,n,m);
    cout << R[0][0]%m << " " << R[0][1]%m << endl;
    cout << R[1][0]%m << " " << R[1][1]%m << endl;
    cout << string(10,'-') << endl;
  }
}