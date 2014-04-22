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

    int value = a[s-1], j;

    for(j = s-2; j >= 0 && a[j] > value; --j){
        a[j+1] = a[j];

        printNumbers();
    }

    a[j+1] = value;
    printNumbers();

}
