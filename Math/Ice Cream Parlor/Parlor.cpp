#include <iostream>
#include <algorithm>
#include <cstdio>
#define MAXN 10001

using namespace std;

int n, m;

struct Flavor {
    int a, index;

    Flavor(){

    }

    Flavor(int a){
        this->a = a;
        this->index = -1;
    }

    bool operator < (const Flavor &f) const {
        return (a < f.a);
    }
}fl[MAXN];

pair<int, int> getAnswer(){
    for(int i = 0; i < n-1 && fl[i].a < m; ++i){
        int index = lower_bound(fl + i + 1, fl + n, Flavor(m - fl[i].a)) - fl;

        if(index < n && fl[index].a + fl[i].a == m){
            int index1 = fl[i].index, index2 = fl[index].index;

            if(index1 > index2)
                swap(index1, index2);

            return make_pair(index1, index2);
        }

    }
}

int main() {
    //freopen("input.txt", "r", stdin);

    int t;

    cin >> t;

    while(t--){
        cin >> m >> n;

        for(int i = 0; i < n; ++i){
            int a;
            cin >> a;
            fl[i].index = i;
            fl[i].a = a;
        }

        sort(fl, fl + n);

        pair<int, int> answer = getAnswer();

        cout << answer.first + 1 <<  " " << answer.second + 1 << '\n';
    }
}
