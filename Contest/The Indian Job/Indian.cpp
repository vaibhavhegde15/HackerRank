#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 101

using namespace std;

bool a[2][MAXN * MAXN];
int n, g, nums[MAXN];


int sumOfAll() {
    int s = 0;

    for(int i = 0; i < n; ++i)
        s += nums[i];

    return s;
}

int getMaximum(int upTo) {
    int m = 0;

    for(int i = 0; i <= upTo; ++i)
        if(a[0][i])
            m = i;

    return m;
}


int main() {
    int t;

    cin >> t;

    while(t--) {
        fill(&a[0][0], &a[1][MAXN*MAXN - 1], false);

        cin >> n >> g;

        for(int i = 0; i < n; ++i)
            cin >> nums[i];

        sort(nums, nums + n);

        int sum = sumOfAll();

        for(int i = 0; i < n; ++i) {
            a[0][nums[i]] = true;

            for(int j = 0; j + nums[i] <= sum / 2; ++j)
                if(a[1][j])
                    a[0][j + nums[i]] = true;

            copy(&a[0][0], &a[0][MAXN*MAXN - 1], &a[1][0]);
        }

        int maximum = getMaximum(sum/2);

        if(max(maximum, sum - maximum) <= g)
            printf("YES\n");
        else
            printf("NO\n");

    }
}
