#include <iostream>
#define MAXX 100

using namespace std;

int times[MAXX];

int main(){
    int n, x;

    cin >> n;

    while(n--){
        string s;
        cin >> x >> s;
        ++times[x];
    }

    int sum = 0;

    for(int i = 0; i < MAXX; ++i){
        sum += times[i];

        cout << sum << " ";
    }
}
