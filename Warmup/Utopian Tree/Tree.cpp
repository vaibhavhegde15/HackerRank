#include <cstdio>

using namespace std;

int main(){
    int t, n;

    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);

        long long answer = 0ll;

        for(int i = 0; i <= n+1; ++i){
            if(i % 2 == 0)
                answer *= 2ll;
            else
                answer += 1ll;
            //printf("Height %d = %d\n", i, answer);
        }

        printf("%lld\n", answer);
    }
}
