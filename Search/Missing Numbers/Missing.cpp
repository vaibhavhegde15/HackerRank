#include <iostream>
#include <cstdio>
#include <cstdlib>
#define MAXX 10000

using namespace std;

int a[2*MAXX + 15];

int main() {
    int n, b;

    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> b;
        --a[b + MAXX];
    }

    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> b;
        ++a[b + MAXX];
    }

    for(int i = 0; i < 2*MAXX + 15; ++i)
        if(a[i] > 0)
            printf("%d ", i - MAXX);
}
