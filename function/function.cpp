/*
 * function.cpp
 *
 *  Created on: Jun. 24, 2020
 *      Author: amaldev
 */

#include "function.hpp"

using namespace function_space;


func::func(string function){

	function.erase( remove(function.begin(),function.end(), ' '), function.end());
	get_toks(this->func_, function);
};


void func::get_toks(vector<token>& func, string function){

	const int len=function.size();


};

token func::tokenize(string expr){

	token res;
	string temp;
	int ind=0;
	expr =expr+".0";

	for(auto i=expr.begin();i<expr.end();i++){

		if(*i =='x'){

			res.co_eff= parser::get_num(temp);
			if(*(i+1) !='^'){

				break;
			}else{

				temp ="";
			}
		}else if(*i == '^'){

			res.power= parser::get_num(expr.substr(ind+1));
			break;
		}else{

			temp+= *i;
		}
	ind++;
	}

	return res;

}

