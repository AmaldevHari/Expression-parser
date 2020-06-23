
#ifndef EXPR_PARSE

#define EXPR_PARSE

#include <iostream>
#include <string>
#include <vector>

#define PLUS '+'
#define MINUS '-'
#define MULTI '*'
#define DIV '/'
#define POWER '^'
#define LBRAC '('
#define RBRAC ')'

using namespace std;

struct toks_and_ops{

	vector<double> toks;
	vector<char> ops;

};

class Parser{

public :


	static	double get_num(string num);

	static	double evaluate(string expr);

	static toks_and_ops tokenize(string expr);


};

#endif
