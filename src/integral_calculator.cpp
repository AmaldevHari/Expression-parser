/*
 * Integral_calculator.cpp
 *
 *  Created on: Aug. 29, 2020
 *      Author: amaldev
 */




#include "integral_calculator.hpp"

std::string polynomial_int(string& polynomial){

	polynomial= parser::replace_expr(polynomial, " ","");
	vector<string> tokens;
	vector<char> signs;

	string tok="";


	for(auto i = polynomial.begin();i!= polynomial.end();i++){
		if(*i =='+' || *i == '-'){

				tokens.push_back(tok);
				tok="";
				signs.push_back(*i);

		}else{
			tok += *i;

		}

	}
	tokens.push_back(tok);

	token poly_token;
	vector<token> result_token;

	for(auto i=tokens.begin();i!= tokens.end();i++){
		poly_token.expression= *i;
		poly_token.decompose();
		poly_token.integrate();
		result_token.push_back(poly_token);

	}
	return construct_polynomial(result_token, signs);

};

std::string construct_polynomial(vector<token>& polynomial_tokens, vector<char>& signs){
	int count=0;
	string res="";
	signs.push_back(' ');
	for(auto i=polynomial_tokens.begin();i!=polynomial_tokens.end();i++){

		res+= to_string((*i).coef).substr(0,3);
		res+="x^";
		res+= to_string((*i).power).substr(0,3);
		res+= signs.at(count);
		count++;
	}
	return res;

};
double get_num_special(string& num){
	if(num.empty()){
		return 0;
	}
	return get_num(num);

}
