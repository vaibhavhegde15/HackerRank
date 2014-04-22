#include <iostream>
#include <cstdio>
#define MAXN 101

using namespace std;

int n, times[MAXN];

int main(){
ios_base::sync_with_stdio(false);

cin.tie(0);

cin >> n;

for(int i = 0; i < n; ++i){
    int x;
    cin >> x;
    ++times[x];
}

for(int i = 0; i <= 99; ++i)
    printf("%d ", times[i]);
}
