#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string a;
    cin >> a;

    int sq = sqrt(a.size());

    int cols = sq + ((sq * sq != a.size())? 1:0);

    for(int i = 0; i < cols; ++i){
        for(int j = 0; j * cols + i < a.size(); ++j) {
            cout << a[j * cols + i];

        }
        cout << " ";

    }
}
