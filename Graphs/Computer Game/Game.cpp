#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
#define MAXP 31630

using namespace std;

vector<int> primes;

void generatePrimes() {
    bool isPrime[MAXP];

    fill(isPrime + 2, isPrime + MAXP, true);

    for(int i = 2; i < MAXP; ++i) {
        if(!isPrime[i])
            continue;

        for(int j = 2; j * i < MAXP; ++j)
            isPrime[i*j] = false;
    }

    for(int i = 2; i < MAXP; ++i)
        if(isPrime[i])
            primes.push_back(i);
}


int main() {
    generatePrimes();
}
