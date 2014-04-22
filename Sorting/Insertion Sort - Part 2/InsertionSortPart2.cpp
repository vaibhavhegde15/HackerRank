#include <iostream>
#define MAXS 1002

using namespace std;

int s;
int a[MAXS];

void printNumbers(){
    for(int i = 0; i < s; ++i)
        cout << a[i] << " ";
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;

    for(int i = 0; i < s; ++i)
        cin >> a[i];

    for(int i = 1; i < s; ++i){
        for(int j = i-1; j >= 0 && a[j] > a[j+1]; --j)
            swap(a[j], a[j+1]);

        printNumbers();
    }

}
