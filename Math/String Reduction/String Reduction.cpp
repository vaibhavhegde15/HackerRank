#include <bits/stdtr1c++.h>

using namespace std;

map<string, int> w;

int compute(string a){
    if(w.find(a) != w.end())
        return w[a];

    int minimum = a.size();

    for(int i = 0; i < a.size() - 1; ++i){
        string s = a.substr(i, 2);
        if(s == "ab" || s == "ba")
            minimum = min(minimum, compute(a.substr(0, i) + "c" + a.substr(i + 2)));
        else if(s == "ac" || s == "ca")
             minimum = min(minimum, compute(a.substr(0, i) + "b" + a.substr(i + 2)));
        else if(s == "bc" || s == "cb")
             minimum = min(minimum, compute(a.substr(0, i) + "a" + a.substr(i + 2)));
    }

    return (w[a] = minimum);

}

int main() {
    freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(0);cin.tie(0);

	int t;
	cin >> t;

	while(t--){
        w.clear();
        string a;
        cin >> a;

        cout << compute(a) << endl;
	}

}
