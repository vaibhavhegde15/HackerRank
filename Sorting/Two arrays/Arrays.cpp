#include <iostream>
#include <algorithm>
#define MAXS 1003

using namespace std;

int n,k, a[MAXS], b[MAXS];

bool isGood() {
    for(int i = 0; i < n; ++i)
        if(a[i] + b[i] < k)
            return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin >> t;

    while(t--) {
        cin >> n >> k;
        for(int i = 0; i < n; ++i)
            cin >> a[i];

        for(int i = 0; i < n; ++i)
            cin >> b[i];

        sort(a, a+n);
        sort(b, b + n, greater<int>());

        if(isGood())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
