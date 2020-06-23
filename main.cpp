/*
 * main.cpp
 *
 *  Created on: Jun. 23, 2020
 *      Author: amaldev
 */


#include "expression_parser.hpp"

int main(int argc , char** argv){

	Parser p;
	double num=p.get_num("23987.99");
	printf("%f",num);
	return EXIT_SUCCESS;
}

