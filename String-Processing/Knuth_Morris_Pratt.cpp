#include<bits/stdc++.h>
#define Mino "Knuth_Morris_Pratt"

#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define DEC(i, a, b) for(int i = a; i >= b; i--)

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll oo = 1e17;

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;

int r[N];

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

    /// Input two strings A and B
    /// Count the number of times B appears in A

    int n, m;
    string A, B;
    cin >> A >> B;

    n = A.size();
    m = B.size();
    A = ' ' + A;
    B = ' ' + B;

    int k = 0;
    r[1] = 0;
    FOR(i, 2, m)
    {
        while(k > 0 && B[k+1] != B[i]) k = r[k];
        if(B[k+1] == B[i]) k++;
        r[i] = k;
    }

    k = 0;
    FOR(i, 1, n)
    {
        while(k > 0 && B[k+1] != A[i]) k = r[k];
        if(B[k+1] == A[i]) k++;
        if(k == m)
        {
            cout << i - m + 1 << ' ';
        }
    }
}

