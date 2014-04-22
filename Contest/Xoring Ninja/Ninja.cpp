#include <iostream>
#define MAXN 100001
#define MOD 1000000007ll

using namespace std;

int n;
long long a[MAXN];

int main(){
    int t;
    cin >> t;

    while(t--){
        cin >> n;

        a[0] = 0ll;

        for(int i = 1; i <= n; ++i){
            cin >> a[i];
            a[i] ^= a[i-1];
        }

        cout << "Numbers: " << endl;

        for(int i = 0; i <= n; ++i)
            cout << a[i] << endl;

        cout << "--------" << endl;


        long long answer = 0;

        for(int i = 0; i < 40; ++i){
            int c = 0;
            for(int j = 0; j <= n; ++j)
                if(a[j] & (1ll << i))
                    ++c;
            cout << "C = " << c << endl;
            answer = (answer + c * (n-c + 2ll) * (1ll << i)) % MOD;
        }

        cout << answer << endl;
    }
}
