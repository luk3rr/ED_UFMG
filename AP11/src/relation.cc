/*
* Filename: relation.cc
* Created on: June 26, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#include "relation.h"

Relation::Relation(long x) {
	n = (x > 9) ? x : 10;
	long id = 2;

	while (id * id < x)
        id++;

	p = id;
}

Relation::~Relation() { }

bool Relation::HasRelation(long x, long y) {
	return (x >= 0) and (y >= 0) and ((x % p) == (y % p));
}
