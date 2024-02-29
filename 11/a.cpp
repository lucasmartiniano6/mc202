#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxn = 100;

vector<int> adj[maxn];
int dist[maxn], vis[maxn];

int bfs(int a, int b){
    memset(dist, 0, sizeof(dist));
    memset(vis, 0, sizeof(dist));
    queue<int> q;
    q.push(a);
    while(!q.empty()){
        int a = q.front(); q.pop();
        vis[a] = 1;

        if(a==b)
            return dist[b];
            
        for(int u: adj[a]){
            if(vis[u]) continue;
            dist[u] = 1+dist[a];
            q.push(u);
        }

    }
    return 0;
}

int main(){
    cout << "GRAFO AMZ CONSTRUIDO!\n";
    int nc, np; cin >> nc >> np;
    int prox = nc + np;
    int q; cin >> q;
    while(q--){
        int a,b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    cin >> q;
    while(q--){
        char op; cin >> op;
        int a,b; cin >> a >> b;
        if(op == 'D'){
            int mx; cin >> mx;
            int dist = bfs(a,b);
            printf("DISTANCIA %d -> %d = %d\n", a, b, dist);
            if(dist > mx){
                printf("%d ADICIONADO E CONECTADO A", prox);
                vector<int> add = {b};
                adj[prox].pb(b);
                for(int u : adj[b]){
                    adj[prox].pb(u);
                    add.pb(u);
                }
                sort(add.begin(), add.end());
                for(int e : add ) cout << " " << e;
                cout << '\n';
                prox++;
            }
        }
        else if(op == 'R'){
            printf("ARESTA %d -> %d REMOVIDO\n", a,b);
            for(int i=0; i<(int)adj[a].size(); i++){
                if(adj[a][i] == b){
                    adj[a].erase(adj[a].begin() + i);
                    break;
                }
            }
            for(int i=0; i<(int) adj[b].size(); i++){
                if(adj[b][i] == a){
                    adj[b].erase(adj[b].begin() + i);
                    break;
                }
            }
        }
    }

    return 0;
}
