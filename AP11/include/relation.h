/*
* Filename: relation.h
* Created on: June 26, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#ifndef RELATION_H_
#define RELATION_H_

class Relation{
	private:
		long n;
		long p;

	public:
		Relation(long n);

		~Relation();

		bool HasRelation(long x, long y);
};

#endif // RELATION_H_
