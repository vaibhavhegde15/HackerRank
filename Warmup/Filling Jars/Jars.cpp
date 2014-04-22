#include <iostream>

using namespace std;

int main(){
    int n, m;
    double avg = 0.0;

    cin >> n >> m;

    while(m--){
        int a, b, k;
        cin >> a >> b >> k;

        avg += (double) (b-a+1ll) * k;
    }

    cout << ((long long) (avg/n)) << endl;
}
