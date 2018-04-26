#include <bits/stdc++.h>

using namespace std;

int lonelyinteger(vector <int> a) {
	int res = 0;
	for(int i = 0; i < a.size(); i++){
		res = res^a[i];
	}

	return res;
	
	/* VERSION STUPID
	int res;
	for(int i = 0; i < a.size(); i++){
		res = a[i];
		for(int j = i + 1; j < a.size(); j++){
			if(j + 1 == a.size() && res != a[j])
				return res;
			if(res == a[j]){
				a.erase(a.begin() + j);
				break;
			}
		}
	}

	return res;	*/
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    int result = lonelyinteger(a);
    cout << result << endl;
    return 0;
}

