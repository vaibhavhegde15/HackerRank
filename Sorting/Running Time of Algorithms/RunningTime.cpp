#include <iostream>
#define MAXS 1002

using namespace std;

int s, n, a[MAXS];

int getIndex(){
    for(int i = 0; i < n; ++i)
        if(a[i] == s)
            return i;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s >> n;

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    cout << getIndex() << endl;

}
