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

int main(){
	int n;
	cin >> n;
	vi a(n);
	vi b(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	int ans = 0;
	int aux = 1;
	for(int i = 0; i < n; i++){
		vi maxAndMinDif(n);
		for(int j = i; j < aux; j++){
			int maximum = INT_MIN;
			int minimum = INT_MAX;
			for(int k = 0; k < n; k++){
				if(a[k] > maximum) {
					maximum = a[k];
				}
				if(b[k] < minimum){
					minimum = b[k];
				}
				maxAndMinDif[k] = maximum - minimum;
			}
			int lAns = 0;
			int l1 = 0;
			int r1 = aux-1;
			while(l1 < r1){
				int m = (l1 + r1) / 2;
				if(maxAndMinDif[m] == 0){
					r1 = m;
				} else {
					l1 = m+1;
				}
			}
			lAns = l1;
			int rAns = 0;
			int l2 = 0;
			int r2 = aux-1;
			while(l2 < r2){
				int m = (l2 + r2 + 1) / 2;
				if(maxAndMinDif[m] == 0){
					l2 = m;
				} else {
					r2 = m - 1;
				}
			}
			rAns = l2;
			cout << "PARA RANGO DE I A J: (" << i << ", " << j << ")\n";
			for(int z = 0; z < j; z++) cout << maxAndMinDif[z] << " ";
			cout << "n rAns - lAns: " << (rAns-lAns) << "\n";
			ans += (rAns-lAns);
		}

		aux++;
	}

	cout << ans << "\n";
}