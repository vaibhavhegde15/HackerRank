#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#define MAXN 103

using namespace std;

int w[MAXN], snakes[MAXN], ladder[MAXN];

struct Cord {
    int moves, index;

    Cord() {

    }

    Cord(int moves, int index) {
        this->moves = moves;
        this->index = index;
    }

    const bool operator < (const Cord &c) const {
        if(moves != c.moves)
            return moves > c.moves;
        else
            index > c.index;
    }
};

bool visited[MAXN];



priority_queue<Cord> q;

void insertIntoQueue(int moves, int index) {
    if(!visited[index])
        q.push(Cord(moves, index));

   // visited[index] = true;
}

int main() {
    int t;

    scanf("%d", &t);

    while(t--) {
        int s, l;
        for(int i = 0; i < MAXN; ++i){
            w[i] = snakes[i] = ladder[i] = -1;
            visited[i] = false;
        }

        for(; !q.empty(); q.pop());

        scanf("%d,%d", &s, &l);

        for(int i = 0; i < s; ++i) {
            int s1, s2;

            scanf("%d,%d", &s1, &s2);
            snakes[s1] = s2;
        }

        for(int i = 0; i < l; ++i) {
            int l1, l2;

            scanf("%d,%d", &l1, &l2);
            ladder[l1] = l2;
        }

        q.push(Cord(0, 1));

        w[1] = 0;

        while(!q.empty()) {
            Cord cur = q.top();

            q.pop();

            if(visited[cur.index])
                continue;

            visited[cur.index] = true;

            if(ladder[cur.index] != -1) {
                insertIntoQueue(cur.moves, ladder[cur.index]);
                continue;
            }

            if(snakes[cur.index] != -1) {
                insertIntoQueue(cur.moves, snakes[cur.index]);
                continue;
            }

            for(int i = 1; i <= 6; ++i) {
                int index = cur.index + i;
                if(index <= 100 && (w[index] == -1  || w[index] > cur.moves + 1)) {
                    w[index] = cur.moves + 1;
                    insertIntoQueue(cur.moves + 1, cur.index + i);
                }
            }
        }

        cout << w[100] << '\n';


    }
}
