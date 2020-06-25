/*
 * function.hpp
 *
 *  Created on: Jun. 24, 2020
 *      Author: amaldev
 */

#ifndef FUNCTION_FUNCTION_HPP_
#define FUNCTION_FUNCTION_HPP_

#include "../src/expression_parser.hpp"

using namespace parser;

namespace function_space{

struct token;


class func{

private:

	vector<token> func_;
	void get_toks(vector<token>& func, string function);
public:

	token tokenize(string expr);
	func(string function);
};

struct token{

	const char var ='x';
	double power=0;
	double co_eff=1;
	char prev_symbol= '\0';
};
}

#endif /* FUNCTION_FUNCTION_HPP_ */
