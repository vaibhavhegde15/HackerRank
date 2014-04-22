#include <iostream>
#include <cstdio>
#define MAXN 'z'-'a' + 3

using namespace std;

int a[MAXN];

bool isPolynomial(string s) {
    for(char i: s)
        ++a[i-'a'];

    bool poly = true;

    for(int i: a)
        if(i & 1) {
            if(!poly)
                return false;

            poly = false;
        }


    return true;
}

int main() {
    string s;

    cin >> s;

    cout << ((isPolynomial(s))?"YES":"NO") << endl;
}
