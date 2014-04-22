#include <cstdio>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        long long n;
        scanf("%lld", &n);

        printf("%lld\n", (n/2ll) * (n - n/2ll));
    }
}
