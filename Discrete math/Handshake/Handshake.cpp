#include <cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    long long a;
    while(t--) {
        scanf("%lld", &a);
        printf("%lld\n", (a * (a-1ll))>>1);
    }
}
