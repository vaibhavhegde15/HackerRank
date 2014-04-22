#include <iostream>
#include <string>
#include <algorithm>
#define MAXN 5003

using namespace std;

int t[MAXN][MAXN];

int compute(string a, string b){
    for(int i = 1; i <= a.size(); ++i)
        for(int j = 0; j <= b.size(); ++j)
            if(a[i-1] == b[j-1])
                t[i][j] = t[i-1][j-1] + 1;
            else
                t[i][j] = max(t[i-1][j], t[i][j-1]);

    return t[a.size()][b.size()];
}

int main(){
    string a, b;

    cin >> a >> b;
    cout << compute(a, b) << endl;
}
