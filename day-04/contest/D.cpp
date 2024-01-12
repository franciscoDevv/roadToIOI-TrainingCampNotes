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

	struct Dsu {
	    vector<int> parent, rank, size;
	    Dsu(int N) {
	        parent.resize(N);
	        rank.resize(N);
	        size.resize(N, 1);
	        for (int i = 0; i < N; i++){
	            parent[i] = i;
	        }
	    }
	    bool isSameSet(int i, int j){
	        return findSet(i) == findSet(j);
	    }
	    int findSet(int i) { 
	        if(parent[i] == i){
	            return i;
	        }else{
	            return parent[i] = findSet(parent[i]);
	        } 
	    }
	    void unionSet(int i, int j){
	        int x = findSet(i);
	        int y = findSet(j);
	        if (x != y){
	            if (rank[x] > rank[y]){
	                parent[y] = x;
	                size[x] += size[y];
	            }else if(rank[x] < rank[y]){
	                parent[x] = y;
	                size[y] += size[x];
	            }else{
	                parent[x] = y;
	                size[y] += size[x];
	                rank[y]++;
	            }
	        }
	    }

	    int getSize(int i){
	        return size[findSet(i)];
	    }
	};



	int main(){
		ll n;
		cin >> n;
		vector<pair<ll, ll>>allNodes;
		vector<pair<long double, pair<int, int>>>nodes;
		for(int i = 0; i < n; i++){
			ll a, b;
			cin >> a >> b;
			allNodes.pb({a, b});
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i == j) continue;
				ll lado1 = abs(max(allNodes[i].first, allNodes[j].first)-min(allNodes[i].first, allNodes[j].first));
				ll lado2 = abs(max(allNodes[j].second, allNodes[i].second)-min(allNodes[j].second, allNodes[i].second));
				long double w = sqrt(((lado1)*(lado1))+((lado2)*(lado2)));
				nodes.pb({w, {i, j}});
			}
		}
		sort(all(nodes));
		Dsu dsu(n);
		long double costo_total = 0;
	    for(int i = 0; i < nodes.size(); i++){
	        long double w = nodes[i].first;
	        ll a = nodes[i].second.first;
	        ll b = nodes[i].second.second;
	        if(!dsu.isSameSet(a, b)){   
	            dsu.unionSet(a, b);    
	            costo_total = w;
	        }
	    }

	    cout << fixed << setprecision(9) << costo_total/2.0 << "\n";

	}	