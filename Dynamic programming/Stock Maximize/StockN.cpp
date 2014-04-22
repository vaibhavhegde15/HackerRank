#include <iostream>
#include <algorithm>
#include <utility>
#define MAXN 50004

using namespace std;


int n;
long long p[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin >> t;

    while(t--) {
        cin >> n;

        long long profit = 0ll, maximum = 0ll;

        for(int i = 0; i < n; ++i)
            cin >> p[i];


        for(int i = n-1; i >= 0; --i){
            maximum = max(maximum, p[i]);

            if(p[i] < maximum)
                profit += maximum - p[i];
        }


            cout << profit << '\n';
    }

}


