#include <iostream>
#include <algorithm>
#define MAXN 100001

using namespace std;

int n, k, answer = 0, a[MAXN];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a, a+n);

    for(int i = 0; i < n && a[i] <= k; ++i, ++answer){
        k -= a[i];
    }

    cout << answer << endl;
}
