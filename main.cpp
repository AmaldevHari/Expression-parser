/*
 * main.cpp
 *
 *  Created on: Jun. 23, 2020
 *      Author: amaldev
 */


#include "expression_parser.hpp"

using namespace parser;

int main(int argc , char** argv){

	cout<< BOLDCYAN<<"Enter mathematical expressions to evaluate, ENTER key denotes end of expression \n ";
	cout<<"supported operations are +(addition), -(subtraction), *(multiplication) , /(division) ,^(power)\n";
	cout<<"Operations are based on BEDMAS \n"<<BOLDWHITE;

	string expr;
	cout.precision(9);

	while(true){

		cout<< "$: ";

		try{
			cin>>expr;
			cout<<BOLDGREEN<<Parser::eval_with_braces(expr)<<BOLDWHITE<<"\n";


		}catch(exception& e){
			cout<<BOLDRED<<"error: error while parsing!"<<BOLDWHITE<<"\n";

		}
	}

	return EXIT_SUCCESS;
}

