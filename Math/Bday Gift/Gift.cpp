#include <iostream>
#include <cstdio>

using namespace std;

long long sum = 0;

int main(){
    int n;

    cin >> n;

    for(int i = 0; i < n; ++i){
        long long a;
        cin >> a;
        sum += a;
    }

    printf("%.1f\n", sum / 2.0);

}
