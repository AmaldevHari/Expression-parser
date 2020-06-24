/*
 * main.cpp
 *
 *  Created on: Jun. 23, 2020
 *      Author: amaldev
 */


#include "expression_parser.hpp"

using namespace parser;

int main(int argc , char** argv){

	cout<<"Enter mathematical expressions to evaluate, ENTER key denotes end of expression \n ";
	cout<<"supported operations are +(addition), -(subtraction), *(multiplication) , /(division) ,^(power)\n";
	cout<<"Operations are based on BEDMAS \n";

	string expr;
	cout.precision(9);

	while(true){

		cout<< "$: ";

		try{
			cin>>expr;
			cout<<Parser::eval_with_braces(expr)<<"\n";


		}catch(exception& e){
			cout<<"error: error while parsing!"<<"\n";

		}
	}

	return EXIT_SUCCESS;
}

