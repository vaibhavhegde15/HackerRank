#include <iostream>

using namespace std;

int main() {
    int t;

    cin >> t;

    while(t--) {
        int n, a, b, c, d;

        cin >> n >> a >> b >> c >> d;

        int total = 0;

        for(int b1 = 0; b1 <= b &&  2*b1 <= n; ++b1)
            for(int c1 = 0; c1 <= c && 2*b1 + 5*c1 <= n; ++c1)
                for(int d1 = 0; d1 <= d && 2*b1 + 5*c1 + 10*d1 <= n; ++d1) {
                    if(2*b1 + 5*c1 + 10*d1 + a >= n)
                        ++total;
                }

        cout << total << endl;


    }
}
