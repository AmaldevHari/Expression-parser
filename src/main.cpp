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
	cout<<GREEN<<"Note: sin(2pi) is not same as sin(2*pi) , implicitly leaving will result in concatenation \n";
	cout<<"Hint: result of the previous operation can be accessed using the expression prev"<<"\n";
	cout<< "example: prev * sin(3*pi) is a valid operation accesing the previous answer to the previous expression \n"<<BOLDWHITE;
	cout<<"type help and press ENTER for more information on commands available"<<"\n";

	string expr;
	cout.precision(9);
	double ans=0;
	double prev=0;

	while(true){

		cout<< "$: ";

		try{

			getline(cin,expr);
			expr.erase( remove(expr.begin(),expr.end(), ' '), expr.end());

			if(expr.compare("exit")==0){

				break;
			}if(expr.compare("help")==0){

				cout<<BOLDWHITE<<"Built in constants:\ne\npi\nbuilt in commands:\nprev - access the previosuly computed value\n";
				cout<<"precision - change the precision of outputs, example precision = 9\nexit - exits the current shell \n";
				goto no_eval;
			}if(expr.substr(0,10).compare("precision=")==0){

				cout.precision((int)get_num(replace_expr(expr,"precision=","")));
				cout<<"precision is now:"<<cout.precision()<<"\n";
				goto no_eval;
			}

			prev=ans;


			expr =regex_replace(expr,regex("prev"),to_string(prev));

			ans= eval_with_braces(expr);
			cout<<BOLDRED<<"Ans: "<<BOLDGREEN<<ans<<BOLDWHITE<<"\n";
			expr="";

		}catch(exception& e){

			//cout<<e.what();
			cout<<BOLDRED<<"error: error while parsing!"<<BOLDWHITE<<"\n";
		}
		no_eval:{ expr="";}
	}

	return EXIT_SUCCESS;
}

