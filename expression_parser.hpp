
#ifndef EXPR_PARSE

#define EXPR_PARSE

#include <iostream>
#include <string>

#define PLUS '+'
#define MINUS '-'
#define MULTI '*'
#define DIV '/'
#define POWER '^'
#define LBRAC '('
#define RBRAC ')'

using namespace std;

class Parser{

public:
		double get_num(string num);

};

#endif
