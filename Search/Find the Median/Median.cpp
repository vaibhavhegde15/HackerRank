#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, a[1000001];

int main() {
    cin >> n;

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a, a+ n);

    cout << a[n/2] << endl;

    return 0;
}
