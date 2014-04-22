#include <iostream>
#define MOD 100000ll

using namespace std;

long long pow(long long a, long long b){
    if(b == 1ll)
        return a;

    if(b == 0ll)
        return 1ll;

    long long p = (pow(a, b >> 1) ) % MOD;

    return (p * p * pow(a, b % 2ll)) % MOD;

}

int main(){
    int t;
    long long a;


    cin >> t;

    while(t--){
        cin >> a;

            cout << (pow(2ll, a) - 1ll + MOD) % MOD << '\n';

    }
}
