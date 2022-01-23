   
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

bool reachable_treasure(vector<vector<char> >& mapa,int x, int y){
    if(mapa[x][y] == 't') return true;
    mapa[x][y] = 'X'; //marquem com a visitat d'aquesta manera per aixi no tornar aun lloc per on ja hem passat
    for(auto& d : dirs){
        //mirar per totes les dirs des de la posicio original (x,y)
        int new_x = x + d.first;
        int new_y = y + d.second;
        //de cada una comprovar si esta dintre del taulell i que no sigui un obstacle
        if(caminable(mapa,new_x,new_y)){
            if(reachable_treasure(mapa,new_x,new_y)) return true;
        }
    }
    return false;
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
    if(reachable_treasure(mapa,x-1,y-1)) cout << "yes";
    else cout << "no";
    cout << endl;
}