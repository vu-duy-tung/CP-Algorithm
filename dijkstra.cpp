#include<bits/stdc++.h>
#define Mino "dijkstra"

#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define DEC(i, a, b) for(int i = a; i >= b; i--)

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
const ll oo = 1e17;

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;

int n, m;
ll Distance[N];
vector<pii> edge[N];

struct node {
    int vertice;
    ll dis;
    bool operator < (const node &other) const {
        return dis > other.dis;
    }
};

priority_queue <node> Queue;

void turbo()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if(fopen(Mino".inp", "r")){
        freopen(Mino".inp", "r",stdin);
        freopen(Mino".out", "w",stdout);
    }
}

int main()
{
    turbo();

    /// Input a directed graph
    /// Find the shortest path from ver 1 to ver i with i from 1 to n

    cin >> n >> m;

    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].pb(mp(v, w));
    }

    Distance[1] = 0;
    FOR(i, 2, n) Distance[i] = oo;

    Queue.push({1, 0});
    while(Queue.size())
    {
        node x = Queue.top();
        Queue.pop();
        if(x.dis > Distance[x.vertice]) continue;

        for(pii adj : edge[x.vertice])
        {
            int nxt = adj.fi;
            int weight = adj.se;
            if(Distance[nxt] > Distance[x.vertice] + weight)
            {
                Distance[nxt] = Distance[x.vertice] + weight;
                Queue.push({nxt, Distance[nxt]});
            }
        }
    }

    FOR(i, 1, n) cout << Distance[i] << ' ';
}
