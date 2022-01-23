#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main(){
    int n,m;
    while(cin >> n >> m){
        vector<vector<int> > g(n); //Graf adjacencies
        vector<int> control(n,0); //per comptar els cops que estan apuntats
        for(int i = 0; i < m; ++i){
            int x,y;
            cin >> x >> y;
            g[x].push_back(y);
            control[y]++;
        }
        priority_queue<int, vector<int>, greater<int> > pq; //pq per posar els que estan a 0 del control
        for(int i = 0; i < n; ++i){
            if(control[i] == 0) pq.push(i);
        }
        
        bool first = true;
        while(not pq.empty()){ //treiem el top de la pq i tmb li restem un als nodes del graf que rebien del top.
            int act = pq.top();
            pq.pop();
            if(first) first = false;
            else cout << ' ';
            cout << act;
            for (int y : g[act]) {
                --control[y];
                if(control[y] == 0) pq.push(y);
            }
        }
        cout << endl;
    }
}