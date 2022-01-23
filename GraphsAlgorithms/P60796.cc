#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

static const int UNDEF = -1;

vector<pair<int,int> > dirs = { {0,1}, {0,-1}, {1,0}, {-1,0} };

bool existeix_vei (const vector<vector<char> >& M, int i, int j) {
  return i >= 0 and j >= 0 and i < M.size() and j < M[0].size() and M[i][j] != 'X';
}

// Retorna el cami de orig cap a dest
vector<pair<int,int>> calcula_cami(const vector<vector<pair<int,int> > >& prev, const pair<int,int>& orig, const pair<int,int>& dest) {
  stack<pair<int,int> > S;
  pair<int,int> actual = dest;
  while (actual != orig) {
    S.push(actual);
    actual = prev[actual.first][actual.second];
  }
  S.push(actual);

  vector<pair<int,int> > resultat;
  while (not S.empty()) {
    resultat.push_back(S.top());
    S.pop();
  }
  
  return resultat;
  
}

pair<int,vector<pair<int,int> > > distance_treasure (vector<vector<char>>& M, int orig_i, int orig_j) {

  vector<vector<int> > dist(M.size(),vector<int>(M[0].size(),UNDEF));
  vector<vector<pair<int,int> > > prev(M.size(),vector<pair<int,int>>(M[0].size()));
  
  dist[orig_i][orig_j] = 0;
  queue<pair<int,int> > Q;
  Q.push({orig_i,orig_j});

  while (not Q.empty()) {
    pair<int,int> p = Q.front(); Q.pop();
    int v_i = p.first;
    int v_j = p.second;
    for (auto& d : dirs) {
      int n_i = v_i + d.first;
      int n_j = v_j + d.second;
      if (existeix_vei(M,n_i,n_j) and dist[n_i][n_j] == UNDEF){
	dist[n_i][n_j] = 1 + dist[v_i][v_j];
	prev[n_i][n_j] = {v_i,v_j};
	Q.push({n_i,n_j});
	if (M[n_i][n_j] == 't') {
	  vector<pair<int,int> > cami = calcula_cami(prev,{orig_i,orig_j},{n_i,n_j});
	  return {dist[n_i][n_j],cami}; 
	}
      }
    }    
  }
  return {-1,vector<pair<int,int> >()};  
}

int main() {
  int f, c;
  cin >> f >> c;
  vector<vector<char> > M(f,vector<char>(c));
  for (int i = 0; i < f; ++i)
    for (int j = 0; j < c; ++j)
      cin >> M[i][j];
  int orig_i, orig_j;
  cin >> orig_i >> orig_j;

  pair<int,vector<pair<int,int> > > res = distance_treasure(M,orig_i - 1,orig_j - 1);
  if (res.first == -1)  cout << "no treasure can be reached" << endl;
  else {
    cout << "minimum distance: " << res.first << endl;
    //cout << "Cami: ";
    //for (auto& x : res.second) cout << "(" << x.first+1 << "," << x.second+1 << ") ";
    //cout << endl;
  }
}