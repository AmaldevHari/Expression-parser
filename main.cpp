/*
 * main.cpp
 *
 *  Created on: Jun. 23, 2020
 *      Author: amaldev
 */


#include "expression_parser.hpp"

using namespace parser;

int main(int argc , char** argv){

	cout<< BOLDCYAN<<"Enter mathematical expressions to evaluate, ENTER key denotes end of expression \n";
	cout<<"supported operations are +(addition), -(subtraction), *(multiplication) , /(division) ,^(power)\n";
	cout<<"Trigonometric functions are also supported, sin(.), cos(.), and tan(.) \n";
	cout<< "Built in constants are"<<BOLDRED<<" e "<<BOLDCYAN<<"and"<<BOLDRED<<" pi"<<BOLDWHITE <<"\n";
	cout<<"Operations are based on BEDMAS \n"<<BOLDWHITE;

	string expr;
	cout.precision(9);
	double ans=0;
	double prev=0;

	while(true){

		cout<< "$: ";

		try{

			getline(cin,expr);
			if(expr.compare("exit")==0){

				break;
			}

			prev=ans;

			expr.erase( remove(expr.begin(),expr.end(), ' '), expr.end());
			expr =regex_replace(expr,regex("prev"),to_string(prev));

			ans= Parser::eval_with_braces(expr);
			cout<<BOLDRED<<"Ans: "<<BOLDGREEN<<ans<<BOLDWHITE<<"\n";
			expr="";

		}catch(exception& e){

			//cout<<e.what();
			cout<<BOLDRED<<"error: error while parsing!"<<BOLDWHITE<<"\n";
		}

	}

	return EXIT_SUCCESS;
}

