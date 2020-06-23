/*
 * main.cpp
 *
 *  Created on: Jun. 23, 2020
 *      Author: amaldev
 */


#include "expression_parser.hpp"

int main(int argc , char** argv){


	double num= Parser::evaluate("23987.99*2");
	printf("%f",num);
	return EXIT_SUCCESS;
}

