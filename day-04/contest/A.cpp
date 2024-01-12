#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define allr(a) a.rbegin(), a.rend()
#define sz(x) (int)(x).size()
#define loop(i, a, b) for(int i = a; i < b; i++)
#define ff first
#define ss second
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vpii = vector<pair<int, int>>;
using vvpii = vector<vector<pair<int, int>>>;
using vb = vector<bool>;

const int MOD = (int)1e9 + 7;
const int maxN = 2e5;
const int INF = INT_MAX;

vvpii g;

struct DSU {
	vi p, rank;
	DSU(int n){
		for(int i = 0; i < n; i++){
			p.pb(i);
			rank.pb(0);
		}
	}
	int find(int x){
		if(p[x] != x)
			return parent[x] = find(parent[x]);
		else return x;
	}

	void union(int x, int y){
		x = find(x); y = find(y);
		if(x == y) return;
		if(rank[x] < rank[y]) 
			swap(x, y);
		parent[y] = x;
		if(rank[x] == rank[y]) rank[x]++;
	}
}

int kruskal()

int main(){
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		int a, b, w;
		cin >> a >> b >> w;
		a--;
		b--;
		g.pb({w, {a, b}});
		g.pb({w, {b, a}});
		lines.pb({a, b, w});
	}
	for(auto i : lines){
		
	}
}