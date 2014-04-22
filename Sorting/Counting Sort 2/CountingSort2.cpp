#include <cstdio>
#define MAXN 101

using namespace std;

int n, times[MAXN];

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        ++times[x];
    }

    for(int i = 0; i <= 99; ++i){
        for(int j = 0; j < times[i]; ++j)
            printf("%d ", i);
    }
}
