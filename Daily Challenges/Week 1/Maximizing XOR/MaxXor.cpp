#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int l,r, maximum = 0;
    cin >> l >> r;

    for(int i = l; i <= r; ++i)
        for(int j = i + 1; j <= r; ++j)
            maximum = max(maximum, i ^ j);

    cout << maximum << endl;
}
