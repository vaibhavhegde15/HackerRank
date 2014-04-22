#include <iostream>
#include <vector>
#include <algorithm>
#define MAXFIB 10000000001ll

using namespace std;

vector<long long> a;

void precompute() {
    long long last1 = a[0], last2 = a[1];
    while(last1 + last2 < MAXFIB) {
        a.push_back(last1 + last2);
        swap(last1, last2);

        last2 = a.back();
    }
}

int main() {
    a.push_back(0);
    a.push_back(1);

    precompute();

    cout << a.size() << endl;

    int t;

    cin >> t;

    while(t--) {
        long long n;
        cin >> n;

        if(binary_search(a.begin(), a.end(),n))
            cout << "IsFibo\n";
        else
            cout << "IsNotFibo\n";

    }
}
