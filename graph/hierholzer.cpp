/// This code could be use to submit on https://cses.fi/problemset/task/1693

#include<bits/stdc++.h>
#define Mino "hierholzer"

#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define DEC(i, a, b) for(int i = a; i >= b; i--)

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const ll oo = 1e17;

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;

int n, m;
int in_degree[N], out_degree[N];

bool used_edge[N];

struct edge {
    int v, id;

    edge(int _v, int _id): v(_v), id(_id) {}
};

vector<edge> adj[N];

void turbo()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if(fopen(Mino".inp", "r")){
        freopen(Mino".inp", "r",stdin);
        freopen(Mino".out", "w",stdout);
    }
}

bool check_euler_path()
{
    if(out_degree[1] != in_degree[1] + 1 ||
       in_degree[n] != out_degree[n] + 1)
        return false;

    FOR(i, 2, n-1)
        if(in_degree[i] != out_degree[i])
            return false;

    return true;
}

list<int> euler_walk(int u) /// Hierholzer algorithm
{
    list<int> ans;
    ans.pb(u);

    while(!adj[u].empty())
    {
        int v = adj[u].back().v;
        int eid = adj[u].back().id;

        adj[u].pop_back();

        if(used_edge[eid]) continue;
        used_edge[eid] = true;

        u = v;
        ans.pb(u);
    }

    for(auto it = ++ans.begin(); it != ans.end(); ++it) if(adj[*it].size() > 0)
    {
        auto cycle = euler_walk(*it);
        cycle.pop_back();
        ans.splice(it, cycle);
    }

    return ans;
}

int main()
{
    turbo();

    cin >> n >> m;

    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(edge(v, i));
        in_degree[v]++;
        out_degree[u]++;
    }

    if(!check_euler_path())
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    adj[n].pb(edge(1, m+1));

    list<int> ans = euler_walk(1);

    if(ans.size() < m+1)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        for(auto u1 = ans.begin(), u2 = ++ans.begin(); u1 != ans.end(), u2 != ans.end(); u1++, u2++)
        {
            if(*u1 == n && *u2 == 1)
            {
                for(auto i = u2; i != ans.end(); i++)
                    cout << *i << ' ';
                for(auto i = ++ans.begin(); i != u2; i++)
                    cout << *i << ' ';
                break;
            }
        }
    }
}
