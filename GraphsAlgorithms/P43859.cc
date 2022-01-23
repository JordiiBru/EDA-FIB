#include <iostream>
#include <vector>
#include <limits>
#include <queue>
using namespace std;

static const int INF = numeric_limits<int>::max();

int dij(vector<vector<pair<int,int> > >& graph, int orig, int desti){
    int n = graph.size();
    vector<int> dist(n,INF);
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > cua;
    //vector<int> prev(n);
    vector<bool> vist(n,false);
    dist[orig] = 0;
    cua.push({0,orig});                 //cua: first: dist, second:vertex
    while(not cua.empty()){
        pair<int,int> p = cua.top();
        cua.pop();
        if(p.second == desti) return dist[p.second];
        if(not vist[p.second]){
            vist[p.second] = true;
            for(auto& q : graph[p.second]){
                int newvertex = q.second;
                int newdist = q.first;
                if(dist[p.second] + newdist < dist[newvertex]){
                    dist[newvertex] = dist[p.second] + newdist;
                    cua.push({dist[newvertex],newvertex});
                }
            }
           

        }
    }
    return -1;
}



int main(){
    int n,m;
    while(cin >> n >> m){
        vector<vector<pair<int,int> > > graph(n);
        for(int i = 0; i < m; ++i){
            int u,v,c;
            cin >> u >> v >> c;
            graph[u].push_back({c,v});
        }
        int x,y;
        cin >> x >> y;
        int result = dij(graph,x,y);
        if(result == -1) cout << "no path from " << x << " to " << y << endl;
        else cout << result << endl;
    }
}