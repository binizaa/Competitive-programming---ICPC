
#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define rep(i,a,b) for(int i=a; i<b; i++)

struct Segtree {
    vector<ll> st, lazy, marked;
    ll n;

    Segtree(ll _n) {
        n = _n;
        st.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        marked.assign(4*n, 0);
    }

    void build(ll p, ll l, ll r, vector<ll>& a) {
         if (l == r) {
            st[p] = a[l];
            return;
        }

        ll m = (l + r) / 2;

        build(2*p, l, m, a);
        build(2*p+1, m + 1, r, a);

        st[p] = st[2*p] + st[2*p+1];
    }
    
    void push(int p, int l, int r) {
        if (!marked[p]) return;

        int m = (l + r) / 2;
        // Actualizo el árbol
        st[2*p] += (m - l + 1) * lazy[p];
        st[2*p+1] += (r - m) * lazy[p];

        // Actualizar lazy
        lazy[2*p] += lazy[p];
        lazy[2*p+1] += lazy[p];
        lazy[p] = 0;

        // Actualizar marked
        marked[2*p] = true;
        marked[2*p+1] = true;
        marked[p] = false;
    }

    void update(ll p, ll l, ll r, ll i, ll j, ll v) {
        if (l > j or r < i) return;
        if (l >= i and r <= j) {
            st[p] += (r - l + 1) * v;
            lazy[p] += v;
            marked[p] = true;
            return;
        }

        push(p, l, r);

        ll m = (l + r) / 2;
        update(2*p, l, m, i, j, v);
        update(2*p+1, m + 1, r, i, j, v);

        st[p] = st[2*p] + st[2*p+1];
    }

    // Query
    ll query(ll p, ll l, ll r, ll i, ll j) {
        if (l > j or r < i) return 0;
        if (l >= i and r <= j) {
            return st[p];
        }

        push(p, l, r);

        ll m = (l + r) / 2;
        ll res =   query(2*p, l, m, i, j) + 
                    query(2*p + 1, m + 1, r, i, j);
        
        return res;
    }

    void build(vector<ll>& a) {
        build(1, 0, n - 1, a);
    }

    void update(ll i, ll j, ll v) {

        update(1, 0, n - 1, i, j, v);
    }

    ll query(ll i, ll j) {
        return query(1, 0, n - 1, i, j);
    }
};

void solve(){
    ll n, q;
    cin >> n >> q;

    Segtree st(n);

    while(q--) {
        ll type;
        cin >> type;

        if (type == 0) {
            
            ll l, r, v;
            cin >> l >> r >> v;

            st.update(l-1, r-1, v);

        }
        else if (type == 1) {
            ll x,y;
            cin >> x>>y;

            cout << st.query(x-1, y-1) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin>>t;
    // int caso = 1; 

    while(t--){
        solve();
    }
}

/*
1
8 6
0 2 4 26
0 4 8 80
0 4 5 20
1 8 8 
0 5 7 14
1 4 8
*/
