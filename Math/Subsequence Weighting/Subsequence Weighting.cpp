#include <bits/stdc++.h>
#define MAXN 150005

using namespace std;

int n;
pair<int, long long> a[MAXN];

long long computeMaximumWeigh() {

    multimap<int, long long> w;

    w.insert(make_pair(0, 0ll));

    for(int i = 0; i < n; ++i) {
        multimap<int, long long>::iterator mit = --w.upper_bound(a[i].first-1);
            w.insert(make_pair(a[i].first, mit->second + a[i].second));
    }

    long long maximum = 0ll;

    for(auto l: w)
        maximum = max(maximum, l.second);


    return maximum;

}

int main() {
     freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    while(t--) {
        cin >> n;

        for(int i = 0; i < n; ++i)
            cin >> a[i].first;


        for(int i = 0; i < n; ++i)
            cin >> a[i].second;


        cout << computeMaximumWeigh() << '\n';
    }


}
