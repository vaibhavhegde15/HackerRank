#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iterator>
#define MAXN 43

using namespace std;

long long was[MAXN];
vector<int> primes;

void sieve(long long upTo) {
    bool p[upTo + 1];

    fill(p, p + upTo + 1, true);

    p[0] = p[1] = false;

    for(long long i = 2; i <= upTo; ++i) {
        if(p[i])
            for(long long j = 2; j * i <= upTo; ++j)
                p[i * j] = false;
    }

    for(int i = 0; i <= upTo; ++i)
        if(p[i])
            primes.push_back(i);

/*
    cout << "Primes:" << endl;

    for(int i = 0; i < 10; ++i)
        cout << primes[i] << endl;

    cout << "First " << *primes.begin() << endl;
*/}

long long compute(int d) {
    if(d < 4)
        return 1ll;

    if(was[d] != -1ll)
        return was[d];


    return (was[d] = compute(d - 1) + ((d >= 4)?compute(d - 4):0ll));
}

int main() {
    sieve(217286ll);

    fill(was, was + MAXN, -1ll);

    was[0] = 0ll;
    was[1] = was[2] = was[3] = 1ll;

    compute(41);

    int t;
    cin >> t;





    while(t--) {
        int n;
        cin >> n;


        cout << distance(primes.begin(), --upper_bound(primes.begin(), primes.end(), was[n])) + 1 << '\n';
    }
}
