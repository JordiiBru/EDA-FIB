#include <iostream>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

static const int INF = numeric_limits<int>::max();

int dij(vector<vector<pair<int,int> > >& grafo, int orig, int dest){
    int n = grafo.size();

    priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > pq;
    vector<int> dist(n,INF);
    vector<bool> visitat(n,false);

    dist[orig] = 0;
    pq.push({0,orig});
    
    while(not pq.empty()){
        pair<int,int> actual = pq.top();
        pq.pop();
        int node_act = actual.second;
        if(node_act == dest) return actual.first;
        if(not visitat[node_act]){
            visitat[node_act] = true;
            for(int i = 0; i < grafo[node_act].size(); ++i){
                int new_node = grafo[node_act][i].second;
                int new_pes = grafo[node_act][i].first;
                int maximum = max(dist[node_act],new_pes);
                if(maximum < dist[new_node]){
                    dist[new_node] = maximum;
                    pq.push({maximum,new_node});
                }
            }
        }

    }
    return -1;
}


int main(){
    int n,m;
    while(cin >> n >> m){
        vector<vector<pair<int,int> > > grafo(n);
        for(int i = 0; i < m; ++i){
            int x,y,l;
            cin >> x >> y >> l;
            grafo[x].push_back({l,y});
        }
        cout << dij(grafo,0,1) << endl;
    }
}