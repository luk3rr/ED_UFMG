/*
* Filename: disjoin_set.h
* Created on: June 26, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#ifndef DISJOIN_SET_H_
#define DISJOIN_SET_H_

#include "vector.h"

class DisjoinSet {
	private:
        Vector<long> parent;

	public:
		DisjoinSet();

		~DisjoinSet();

		void MakeSet(long x);

		void UnionSet(long x, long y);

		long FindSet(long x);
};

#endif // DISJOIN_SET_H_
