#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n,m;
    while(cin >> n >> m){
        vector<vector<int> > grafo(n);
        vector<int> ge(n,0);
        for(int i = 0; i < m; ++i){
            int a,b;
            cin >> a >> b;
            grafo[a].push_back(b);
            ++ge[b];
        }
        queue<int> cua;
        for(int i = 0; i < n; ++i){
            if(ge[i] == 0) cua.push(i);
        }
        while(not cua.empty()){
            int act = cua.front();
            cua.pop();
            --n;
            for(int i = 0; i < grafo[act].size(); ++i){
                --ge[grafo[act][i]];
                if(ge[grafo[act][i]] == 0) cua.push(grafo[act][i]);
            }
        }
        if(n!=0) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}