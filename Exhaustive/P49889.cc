#include <iostream>
#include <vector>

using namespace std;


typedef vector<bool> vb;

void backtracking (vector<string> &c, vector<string> &v, string r, int n, vb& vu, vb& cu) {
	if (n == c.size()*2+1) cout << r << endl;
	else {
		string x;
		if(n%2 == 0){
			for (int k = 0; k < v.size(); ++k){
				if(not vu[k]){
					x = r + v[k];
					vu[k] = true;
					backtracking(c, v, x, n+1, vu, cu);
					vu[k] = false;
				}
			}
		}
		else{
			for (int k = 0; k < v.size(); ++k){
				if(not cu[k]){
					x = r + c[k];
					cu[k] = true;
					backtracking(c, v, x, n+1, vu , cu);
					cu[k] = false;
				}
			}
		}
	}
}

int main () {
	int n;
	cin >> n;

	vector<string> voc(n);
	vector<string> cons(n);

	vector<bool> vocused(n, false);
	vector<bool> consused(n, false);

	for (int i = 0; i < n; ++i){
		char x; cin >> x;
		cons[i] = x;
	}
	for (int i = 0; i < n; ++i){
		char x; cin >> x;
		voc[i] = x;
	}

	backtracking(cons, voc, "", 1, vocused, consused);

}