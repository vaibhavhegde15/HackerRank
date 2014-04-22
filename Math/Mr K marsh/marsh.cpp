#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 505

using namespace std;

int my, mx, answer = -1;
string g[MAXN];


bool isValid(int x1, int y1, int x2, int y2){
    for(int i = x1; i <= x2; ++i)
        if(g[y1][i] != '.' || g[y2][i] != '.')
            return false;

    for(int i = y1; i <= y2; ++i)
        if(g[i][x1] != '.' || g[i][x2] != '.')
            return false;

    return true;


}

int main() {

    cin >> my >> mx;

    for(int i = 0; i < my; ++i)
        cin >> g[i];

    for(int y = 0; y < my; ++y)
        for(int x = 0; x < mx; ++x) {
            if(g[y][x] == '.')
                for(int dy = 1; y + dy < my && g[y + dy][x] == '.'; ++dy)
                    for(int dx = 1; x + dx < mx && g[y + dy][x + dx] == '.' && g[y][x + dx] == '.'; ++dx) {
                        if(isValid(x, y, x + dx, y + dy))
                            answer = max(answer, 2 * (dy +dx));
                    }
        }

    if(answer == -1)
        cout << "impossible\n";
    else
        cout << answer << '\n';
}
