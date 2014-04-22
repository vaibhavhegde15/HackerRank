#include <iostream>
#include <cmath>

using namespace std;

int countSquares(long long from, long long to){
    int c = 0;

    for(long long i = sqrt(from); i*i <= to; ++i)
        if(i*i >= from && i*i <= to)
            ++c;

    return c;
}

int main(){

    int t;
    long long a, b;

    cin >> t;

    while(t--){
        cin >> a >> b;
        cout << countSquares(a, b) << endl;
    }

}
