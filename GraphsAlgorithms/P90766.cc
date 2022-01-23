#include <iostream>
#include <vector>
using namespace std;


vector<pair<int,int> > dirs = { {0,1}, {0,-1}, {1,0}, {-1,0} };

bool caminable(vector<vector<char> >& mapa,int x, int y){
    if(x >= 0 and x < mapa.size() and y >= 0 and y < mapa[0].size() and mapa[x][y] != 'X'){
        return true;
    }
    else return false;
}

int reachable_treasure(vector<vector<char> >& mapa,int x, int y){
    int total = 0;
    if(mapa[x][y] == 't') total = 1;
    else total = 0;
    mapa[x][y] = 'X'; 
    for(auto& d : dirs){
        int new_x = x + d.first;
        int new_y = y + d.second;
        if(caminable(mapa,new_x,new_y)){
            //if(mapa[new_x][new_y] == 't') return 1 + reachable_treasure(mapa,new_x,new_y);
            //else return reachable_treasure(mapa,new_x,new_y);
            total = total + reachable_treasure(mapa,new_x,new_y);
        }
    }
    return total;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<char> > mapa(n,(vector<char>(m)));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> mapa[i][j];
        }
    }
    int x,y; //posicio on comencem
    cin >> x >> y;
    cout << reachable_treasure(mapa,x-1,y-1) << endl;
}