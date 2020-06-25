/*
 * function.hpp
 *
 *  Created on: Jun. 24, 2020
 *      Author: amaldev
 */

#ifndef FUNCTION_FUNCTION_HPP_
#define FUNCTION_FUNCTION_HPP_

#include "../src/expression_parser.hpp"


namespace function{

using namespace parser;

struct token;

class function{

private:
	vector<token> func;
	void get_toks(vector<token>& func, string function);

public:
	function(string function);


};

struct token{

	char var;
	double exp;
	double co_eff=1;
	char prev_symbol;
};

}
#endif /* FUNCTION_FUNCTION_HPP_ */
