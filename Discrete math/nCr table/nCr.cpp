#include <iostream>
#include <algorithm>
#define MAXN 1004
#define MOD 1000000000ll

using namespace std;

long long c[MAXN][MAXN];

void generateC(){
    fill(&c[0][0], &c[MAXN-1][MAXN-1], 1ll);

    c[0][0] = 1ll;
    for(int i = 1; i < MAXN; ++i)
        for(int j = 1; j < i; ++j)
            c[i][j] = (c[i-1][j-1] + c[i-1][j]) % MOD;
}

int main(){
    generateC();

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        for(int i = 0; i <= n; ++i)
            cout << c[n][i] << " ";
        cout << '\n';

    }
}
