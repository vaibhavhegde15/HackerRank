#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

multiset<long long> a;
multiset<long long>::iterator middle = a.end();


void add(long long number) {
    if(a.empty()) {
        a.insert(number);
        middle= a.begin();
    } else {

        if(number < *middle) {
            a.insert(number);
            if(a.size() % 2ll == 0ll)
                --middle;
        } else {
            a.insert(number);
            if(a.size() % 2ll == 1ll)
                ++middle;
        }
    }
}

bool removeElement(long long number) {
    multiset<long long>::iterator it1 = a.find(number);

    if(a.empty() || it1 == a.end())
        return false;

    if(*middle == number) {
        if(a.size()%2 != 0)
            middle++;
        else {
            multiset<long long>::iterator temp = middle;
            temp--;

            if(*temp != number)
                middle--;
        }
        a.erase(it1);

    } else if(number > *middle) {
        a.erase(it1);

        if(a.size() % 2 == 0)
            --middle;
    } else {
        a.erase(it1);

        if(a.size() % 2 == 1)
            --middle;
    }

    return true;
}

void getMedian() {
    if(a.empty() || middle == a.end()) {
        printf("Wrong!\n");
        return;
    }

    if(a.size() % 2) {
        printf("%lld\n", *middle);
        return;
    }

    multiset<long long>::iterator m2 = middle;
    ++m2;

    if((*middle + *m2) % 2ll)
        printf("%.1f\n", (*middle + *m2) / 2.0);
    else
        printf("%.0f\n", (*middle + *m2) / 2.0);
}

int main() {
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    //cin.tie(0);

    long long n, v;

    cin >> n;

    while(n--) {
        char op;

        cin >> op >> v;

        switch(op) {
        case 'a':
            add(v);
            getMedian();
            break;
        case 'r':
            if(removeElement(v))
                getMedian();
            else
                printf("Wrong!\n");
            break;
        }
    }
}
