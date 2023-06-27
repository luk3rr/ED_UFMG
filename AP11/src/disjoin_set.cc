/*
* Filename: disjoin_set.cc
* Created on: June 26, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#include "disjoin_set.h"

DisjoinSet::DisjoinSet() { }

DisjoinSet::~DisjoinSet() { }

void DisjoinSet::MakeSet(long x) {
    this->parent.PushBack(x);
}

void DisjoinSet::UnionSet(long x, long y) {
    int px = FindSet(x);
    int py = FindSet(y);
    if (px != py) {
        parent[px] = py;
    }
}

long DisjoinSet::FindSet(long x) {
    long root = x;

    while (root != parent[root]) {
        root = parent[root];
    }

    while (x != root) {
        long newx = parent[x];
        parent[x] = root;
        x = newx;
    }

    return root;
}
