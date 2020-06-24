/*
 * main.cpp
 *
 *  Created on: Jun. 23, 2020
 *      Author: amaldev
 */


#include "expression_parser.hpp"

using namespace parser;

int main(int argc , char** argv){


	double num=Parser::eval_with_braces("(98 +3 -2 -1)/98 ");
	printf("%f",num);
	return EXIT_SUCCESS;
}

