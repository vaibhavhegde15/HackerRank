#include<iostream>
#include <algorithm>
using namespace std;
int main() {
    long long price = 0;

    int N, K;
    cin >> N >> K;

    int C[N];

    for(int i = 0; i < N; i++)
        cin >> C[i];

    sort(C, C+N, greater<int>());

    int nr = 0;

    for(int i = 0; nr < N; ++i)
        for(int j = 0; j < K && nr < N; ++j, ++nr)
            price += (i + 1ll) * C[nr];

    cout << price << "\n";
    return 0;
}
