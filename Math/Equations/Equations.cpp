#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAXP 1003
#define MAXN 1000008
#define MOD 1000007ll

using namespace std;

vector<int> primes;
long long divisors[MAXN];

void generatePrimes() {
    bool sieve[MAXP];

    fill(sieve, sieve + MAXP, true);

    sieve[0] = sieve[1] = false;

    for(int i = 2; i < MAXP; ++i)
        if(sieve[i])
            for(int j = 2; j * i < MAXP; ++j)
                sieve[i * j] = false;

    for(int i = 0; i < MAXP; ++i)
        if(sieve[i])
            primes.push_back(i);
}

void factorize(int number) {
    for(vector<int>::iterator p = primes.begin(); p != primes.end(); ++p)
        while(number > 1 && number % (*p) == 0) {
            ++divisors[*p];
            number /= (*p);
        }

    if(number > 1)
        ++divisors[number];
}

int main() {
    generatePrimes();

    int n;

    cin >> n;

    long long answer = 1;

    for(int i = 2; i <= n; ++i){
        factorize(i);
    }

    for(int i = 0; i < MAXN; ++i)
        answer = (answer * ((2ll* divisors[i] + 1ll)) ) % MOD;

    cout << answer << '\n';

}
