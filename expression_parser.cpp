#include "expression_parser.hpp"


using namespace parser;

double Parser::get_num(string num){
	/*
	 * renamed for convenience
	 */
	return ::stod(num);
}



toks_and_ops Parser::tokenize(string expr){
	/*
	 * This method tokenizes a string (without braces) into numbers and operands. The string must be a valid mathematical expression
	 * It is recommended to be called from evaluate() method since there is no support for braces.
	 * For evaluation of expressions with braces check out struct expr_stack.
	 *
	 */
	const int len= expr.size();
	string tok ="";
	char current_char;

	// struct toks_and_ops is used here and the following vector<> members are for the struct feilds.
	vector<double> toks;
	vector<char> ops ;
	int	current_index=0;

	while(current_index<len){

		current_char=expr.at(current_index);
		/*
		 * check if the character is  a number a.k.a between values 57 and 48 in ASCII
		 *'.' is 46 in ASCII and - is 45
		 *This method is faster than cross referencing character with every other numbers
		 */
		if((current_char<58 && current_char>44) && current_char != 47){

			if(current_char == MINUS){

				if(expr.at(current_index -1) > 47 &&  expr.at(current_index -1) <58){
					/*
					 * Pure subtraction is considered as addition of a negative value.
					 * if the character before the minus sign is a number its a pure subtraction
					 * if the character before is an operation it is a normal operation
					 * It is guaranteed that there will be always one character before minus sign
					 * evaluate() method will append '0' before an expression if the first character is '-'
					 * Furthermore evaluate() will only work with expressions without braces so an error is not possible
					 */
					ops.push_back(PLUS);
					toks.push_back(get_num(tok));
					tok="";
				}
			}
			tok +=current_char;

		}else{
			/*
			 * If the character is not a number , '.' or '-'
			 */
			toks.push_back( get_num(tok));
			ops.push_back(current_char);
			tok="";

		}
		current_index++;
	}
	toks.push_back(get_num(tok));
	toks_and_ops res ={toks,ops};
	return res;

}



double Parser::evaluate(string expr){

	/*
	 * Central method for evaluation.
	 * This method is not directly called by the user
	 * This method serves as a helper for the structure expr_stack to evaluate expressions with braces
	 * This method can be called if required to evaluate simple expressions i.ewithout any braces.
	 */
	if(expr.empty()){

		return 1;
	}if(expr.at(0) == MINUS){
		/*
		 *  preventing an error for tokenize() method
		 */
		expr ="0" +expr;
	}if(expr.size() ==1 ){

		return get_num(expr);
	}

	toks_and_ops r =tokenize(expr);
	double temp_val;
	int ops_index=0;
	/*
	 * The operations use BEDMAS
	 * In this context we exclude braces since this method does not evaluate expression with brace
	 * Power takes precedence then * ->/ -> +
	 * Indirectly expressions inside brackets are evaluated first by the expression_stack
	 */
	for(auto i = r.ops.begin(); i< r.ops.end();){

		if(*i == POWER){

			temp_val= pow(r.toks[ops_index] , r.toks[ops_index+1]);
			remov(ops_index+1, r.toks);
			remov(ops_index, r.ops);
			r.toks[ops_index] = temp_val;

		}else{

			i++;
			ops_index++;
		}
	}
	if(r.toks.size() ==1){

		return r.toks[0];
	}
	ops_index=0;

	for(auto i = r.ops.begin(); i< r.ops.end();){

		if(*i == MULTI){

			temp_val=r.toks[ops_index+1] * r.toks[ops_index];
			remov(ops_index+1, r.toks);
			remov(ops_index, r.ops);
			r.toks[ops_index] = temp_val;

		}else{

			i++;
			ops_index++;
		}
	}

	if(r.toks.size() ==1){

		return r.toks[0];

	}
	ops_index=0;

	for(auto i = r.ops.begin(); i< r.ops.end();){

		if(*i == DIV){

			temp_val= r.toks[ops_index] / r.toks[ops_index+1];
			remov(ops_index+1, r.toks);
			remov(ops_index, r.ops);
			r.toks[ops_index] = temp_val;

		}else{

			i++;
			ops_index++;
		}
	}

	if(r.toks.size() ==1){

		return r.toks[0];
	}
	ops_index=0;

	for(auto i = r.ops.begin(); i< r.ops.end();){

		if(*i == PLUS){

			temp_val= r.toks[ops_index+1] + r.toks[ops_index];
			remov(ops_index+1, r.toks);
			remov(ops_index, r.ops);
			r.toks[ops_index] = temp_val;

		}else{

			i++;
			ops_index++;
		}
	}
	return r.toks[0];

};




void Parser::remov(int pos,vector<double>& nums){

	/*
	 * Removes an element from the specified index from a vector<>
	 * more convenient than directly implementing an iterator loop
	 * This function is overloaded for char type and int type vectors
	 */

	int count =0;

	for(auto it =nums.begin() ; it<nums.end();it++){

		if(pos==count){

			nums.erase(it);
			break;
		}
		count++;
	}
};

void Parser::remov(int pos,vector<char>& ops){

	int count =0;

	for(auto it =ops.begin() ; it<ops.end();it++){

		if(pos==count){

			ops.erase(it);
			break;
		}
		count++;
	}
};

void Parser::remov(int pos,vector<int>& ops){

	int count =0;

	for(auto it =ops.begin() ; it<ops.end();it++){

		if(pos==count){

			ops.erase(it);
			break;
		}
		count++;
	}
};

void Parser::print_vector(vector<double> vec){

	/*
	 * prints out contents of a vector
	 */
	for(auto i =vec.begin(); i<vec.end() -1;i++ ){

		cout<<*i<<",";
	}
	cout<<*(vec.end()-1)<<"\n";
};

void Parser::print_vector(vector<char> vec){

	for(auto i =vec.begin(); i<vec.end() -1;i++ ){

		cout<<*i<<",";
	}
	cout<<*(vec.end()-1)<<"\n";
};

double Parser::eval_with_braces(string expr){

	/*
	 * evaluates expressions with braces
	 * see expr_stack structure for more information on evaluation of expressions with braces
	 */
	expr_stack eval;
	int ind=0;

	expr.erase( remove(expr.begin(),expr.end(), ' '), expr.end());
	expr = pre_process_trig_and_constants(expr);

	for(auto i =expr.begin();i<expr.end();){

		if(*i!=SIN && *i !=COS && *i != TAN){

			eval.push(*i);
			i++;
			ind++;
		}else{

			expr_stack trig_eval;
			int trig_ind =ind+1;

			while(!trig_eval.expr_done){

				trig_eval.push(expr.at(trig_ind));
				trig_ind++;
			}

			string temp;
			if(*i== SIN){

				temp= to_string(sin(evaluate(trig_eval.expr)));
			}else if(*i== COS){

				temp= to_string(cos(evaluate(trig_eval.expr)));
			}else{
				temp= to_string(tan(evaluate(trig_eval.expr)));
			}
			expr =expr.substr(0,ind) + temp +expr.substr(ind+ trig_eval.push_count +1, expr.size()-ind -trig_eval.ind -2);

		}
	}
	return evaluate(eval.expr);
};



string Parser::replace(string source, string del, string add){

	return regex_replace(source,regex(del),add);

}

string Parser::pre_process_trig_and_constants(string source){


	source =replace(source,"sin","s");
	source =replace(source,"cos", "c");
	source =replace(source,"tan", "t");
	source =replace(source,"e", to_string(exp(1)));
	source =replace(source,"pi", to_string(M_PI));
	return source;



}
