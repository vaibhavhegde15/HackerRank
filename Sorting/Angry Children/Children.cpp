#include <iostream>
#include <algorithm>
#include <climits>
#define MAXS 100001

using namespace std;

int n, k, a[MAXS], unhappines = INT_MAX;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


        cin >> n >> k;
        for(int i = 0; i < n; ++i)
            cin >> a[i];

        sort(a, a+n);

        for(int i = 0; i + k <= n; ++i)
            unhappines = min(unhappines, a[i+k-1] - a[i]);

        cout << unhappines << endl;



}
