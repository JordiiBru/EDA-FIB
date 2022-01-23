#include <iostream>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

static const int INF = numeric_limits<int>::max();

vector<pair<int,int> > dirs = {{0,1},{0,-1},{1,0},{-1,0}};

bool legal(int x,int y,int n){
    if(x < n and x >= 0 and y >= 0 and y < n) return true;
    else return false;
}

int dij(vector<vector<int> >& tablero,int n){
    vector<vector<int> > dist(n,vector<int>(n,INF));
    vector<vector<bool> > visto(n,vector<bool>(n,false));
    priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > pq;
    dist[n/2][n/2] = tablero[n/2][n/2];
    pq.push({dist[n/2][n/2],{n/2,n/2}});

    while(not pq.empty()){
        pair<int,pair<int,int> > actual = pq.top();
        int peso_act = actual.first;
        int x = actual.second.first;
        int y = actual.second.second;
        pq.pop();
        if(x == 0 or x == n-1 or y == 0 or y == n-1) return peso_act;
        if(not visto[x][y]){
            visto[x][y] = true;
            for(auto d : dirs){
                int newx = x + d.first;
                int newy = y + d.second;
                int peso_nuevo = tablero[newx][newy];
                if(legal(newx,newy,n) and not visto[newx][newy] and (dist[newx][newy] > dist[x][y] + peso_nuevo)){
                        dist[newx][newy] = dist[x][y] + peso_nuevo;
                        pq.push({dist[newx][newy],{newx,newy}});
                    
                }
            }
        }
    }
    return -1;
}


int main(){
    int n;
    while(cin >> n){
        vector<vector<int> > tablero(n,vector<int>(n));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin >> tablero[i][j];
            }
        }
        cout << dij(tablero,n) << endl;
    }
}