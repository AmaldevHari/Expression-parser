/*
 * integral_calculator.hpp
 *
 *  Created on: Aug. 29, 2020
 *      Author: amaldev
 */

#ifndef INTEGRAL_CALCULATOR_HPP_
#define INTEGRAL_CALCULATOR_HPP_

#include "expression_parser.hpp"
using namespace parser;

struct token;
std::string product_rule(string& expr);
std::string polynomial_int(string& polynomial);
std::string construct_polynomial(vector<token>& polynomial_tokens, vector<char>& signs);
double get_num_special(string& num);

struct token{

	string expression="";
	double coef=0;
	double power=0;
	bool x_found=false;;

	void decompose(){
		string temp;
		if(!expression.empty()){

			for(auto i= expression.begin(); i!= expression.end();i++){
				if(*i =='x'){
					coef = get_num_special(temp);
					temp="";
					x_found =true;
				}else if(*i=='^'){

				}else{
					temp+= *i;
				}

			}
			x_found?(get_num_special(temp)==0?power=1:power=get_num_special(temp)):coef=get_num_special(temp);
		}
	}
	void integrate(){

		power++;
		coef=coef/power;
	}
};
#endif /* INTEGRAL_CALCULATOR_HPP_ */
