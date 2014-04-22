#include <cstdio>
#include <algorithm>
#define MAXN 100001

using namespace std;

int n, w[MAXN];

int main() {
    int t;

    scanf("%d%d", &n, &t);

    for(int i = 0; i < n; ++i)
        scanf("%d", &w[i]);

    while(t--) {
        int from, to;
        scanf("%d%d", &from, &to);
        printf("%d\n", *min_element(w + from, w + to + 1));
    }
}
