// https://www.spoj.com/problems/CNTPRIME/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define rep(i,a,b) for(int i=a; i<b; i++)

const int LIMITE = 10000000;
vector<bool> es_primo_arr(LIMITE + 1, true);

void criba() {
    es_primo_arr[0] = es_primo_arr[1] = false;
    for (int p = 2; (long long)p * p <= LIMITE; p++) {
        if (es_primo_arr[p])
            for (int i = p * p; i <= LIMITE; i += p)
                es_primo_arr[i] = false;
    }
}

// ICPC
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
            if(es_primo_arr[a[l]]) st[p] = 1;
            else st[p] = 0;
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
        st[2*p] = (m - l + 1) * lazy[p];
        st[2*p+1] = (r - m) * lazy[p];

        lazy[2*p] = lazy[2*p+1] = lazy[p];
        marked[2*p] = marked[2*p+1] = true;

        lazy[p] = 0;
        marked[p] = false;
    }

    void update(ll p, ll l, ll r, ll i, ll j, ll v) {
        if (l > j or r < i) return;
        if (l >= i and r <= j) {
            st[p] = (r - l + 1) * v;
            //lazy[p] += v;
            lazy[p] = v;
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
        int value = 0;

        if(es_primo_arr[v]) value = 1;
        update(1, 0, n - 1, i, j, value);
    }

    ll query(ll i, ll j) {
        return query(1, 0, n - 1, i, j);
    }
};

void solve(){
    ll n, q;
    cin >> n >> q;

    Segtree st(n);

    vector<ll> arr(n);
    rep(i,0,n) cin>>arr[i];
    st.build(arr);

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

    criba();

    int t; cin>>t;
    int caso = 1; 

    while(t--){
        cout << "Case " << caso++ << ":\n";
        solve();
    }
}

/*
1
5 3
78 2 13 12 3
1 1 2
0 4 4 5
1 1 5
*/