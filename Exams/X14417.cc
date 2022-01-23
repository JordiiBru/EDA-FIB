#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m;
vector<pair<int,int> > dirs = {{0,1},{1,0},{0,-1},{-1,0}};

bool poslegal(vector<vector<string> >& tablero, int x, int y){
    if(x < n and x >= 0 and y < m and y >= 0 and tablero[x][y] != "*") return true;
    else return false;
}


int bfs(vector<vector<string> >& tablero, pair<int,int>& orig, pair<int,int>& dest){
    queue<pair<int,int> > cua;
    vector<vector<int> > dist(n,vector<int>(m,-1));
    cua.push({orig.first,orig.second});
    dist[orig.first][orig.second] = 0;
    while(not cua.empty()){
        pair<int,int> pos_act = cua.front();
        cua.pop();
        if(pos_act == dest) return dist[pos_act.first][pos_act.second];
        for(auto d : dirs){
            int newx = pos_act.first + d.first;
            int newy = pos_act.second + d.second;
            if(poslegal(tablero,newx,newy) and dist[newx][newy] == -1){
                dist[newx][newy] = dist[pos_act.first][pos_act.second] + 1;
                cua.push({newx,newy});
            }
        }
    }
    return -1;
}

pair<int,int> busca_posicion(vector<vector<string> >& tablero, string casella){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(tablero[i][j] == casella) return {i,j};
        }
    }
    return {-1,-1};
}

int main(){
    while(cin >> n >> m){
        bool trobat = true;
        vector<vector<string> > tablero(n,vector<string>(m));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j) cin >> tablero[i][j];           
        }
        int tam;
        cin >> tam;
        vector<string> casillas(tam);
        vector<pair<int,int> > posiciones(tam);
        for(int i = 0; i < tam; ++i) {
            cin >> casillas[i];
            posiciones[i] = busca_posicion(tablero,casillas[i]);
            if(posiciones[i].first == -1 and posiciones[i].second == -1) trobat = false;
        }
        int movs = 0;
        
        for(int i = 0; i < tam and trobat; ++i){
            if(i==0) {
                pair<int,int> orig = {0,0};
                int d = bfs(tablero,orig,posiciones[i]);
                if(d != -1) movs = movs + d;
                else  trobat = false;
                
            }
            else { 
                int d = bfs(tablero,posiciones[i-1],posiciones[i]);
                if(d != -1) movs = movs + d;
                else  trobat = false;               
            }
        }
        if(trobat) cout << movs+tam << endl;
        else cout << "impossible" << endl;
    }
}