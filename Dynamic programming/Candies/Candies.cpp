#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define MAXN 100002

using namespace std;

const int INF = 10055225;

int n, a[MAXN], c[MAXN];
long long total = 0ll;

struct Comp {
    const bool operator ()(const int &i1, const int &i2) const {
        return a[i1] > a[i2];
    }
};

priority_queue<int, vector<int>, Comp> q;

int getMinimum(int index){

    if(index == 0){
        if(a[index] <= a[index + 1])
            return 1;

        return c[index + 1] + 1;
    }

    if(index == n - 1){
        if(a[index] <= a[index - 1])
            return 1;

        return c[index - 1] + 1;
    }


    if(a[index] == a[index - 1] && a[index] == a[index + 1])
        return 1;

    int amin = a[index - 1];
    int minPos = index - 1;
    if(amin > a[index + 1]){
        amin = a[index + 1];
        minPos = index + 1;
    }

    int amax = a[index - 1];
    int maxPos = index - 1;

    if(amax < a[index + 1]){
        amax = a[index + 1];
        maxPos = index + 1;
    }

    if(amin >= a[index] && amax >= a[index])
        return 1;

    if(amin < a[index] && amax >= a[index])
        return c[minPos] + 1;

    return max(c[index - 1], c[index + 1]) + 1;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> a[i];
        q.push(i);
    }

    fill(c, c+n, INF);



    for(;!q.empty(); q.pop()){
        int index = q.top();
        c[index] = getMinimum(index);

        total += ((long long)c[index]);
    }

    cout << total << endl;
}
