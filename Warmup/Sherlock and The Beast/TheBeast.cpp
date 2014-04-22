#include <cstdio>
#include <string>

using namespace std;

int get3Number(int n) {
    for(int t = 0; t <= n; ++t)
        if(t % 5 == 0 && (n-t) % 3 == 0)
            return t;

    return -1;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int timesThree = get3Number(n);

        if(timesThree == -1)
            printf("-1\n");
        else
            printf("%s\n", (string(n-timesThree, '5') + string(timesThree, '3')).c_str());
    }
}
