#include <iostream>
#include <cstdio>

using namespace std;

int compute(long long n1) {
    int d = 0;

    for(long long number = n1; number; number /= 10ll)
        if(number % 10ll != 0ll && n1 % (number % 10ll) == 0ll)
            ++d;

    return d;

}

int main() {
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;

    while(t--) {
        long long a;

        cin >>a ;
        cout << compute(a) << "\n";
    }
}
