#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <climits>

using namespace std;

int n, a[200001];

int getMinimumDiff() {
    int mi = INT_MAX;

    for(int i = 1; i < n; ++i)
        mi = min(mi, abs(a[i-1] - a[i]));

    return mi;
}

int main() {
    cin >> n;

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a, a+n);

    int di = getMinimumDiff();

    for(int i = 1; i < n; ++i)
        if(abs(a[i-1] - a[i]) == di)
            cout << a[i-1] << " " << a[i] << " ";
}
