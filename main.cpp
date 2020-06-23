/*
 * main.cpp
 *
 *  Created on: Jun. 23, 2020
 *      Author: amaldev
 */


#include "expression_parser.hpp"

int main(int argc , char** argv){


	double num= Parser::evaluate("23.1  * 2 +2/2/2");
	printf("%f",num);
	return EXIT_SUCCESS;
}

