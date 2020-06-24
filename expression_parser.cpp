#include "expression_parser.hpp"

using namespace parser;


double Parser::get_num(string num){

	return ::stod(num);
}



toks_and_ops Parser::tokenize(string expr){

	const int len= expr.size();
	string tok ="";

	char current_char;




	vector<double> toks;
	vector<char> ops ;

	int	current_index=0;


	while(current_index<len){

		current_char=expr.at(current_index);

		if((current_char<58 && current_char>44) && current_char != 47){


			if(current_char == MINUS){

				if(expr.at(current_index -1) > 47 &&  expr.at(current_index -1) <58){
				ops.push_back(PLUS);
				toks.push_back(get_num(tok));
				tok="";
				}

			}



			tok +=current_char;


		}else{





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


	expr.erase( remove(expr.begin(),expr.end(), ' '), expr.end());


	if(expr.empty()){

		return 1;
	}

	if(expr.at(0) == MINUS){
			expr ="0" +expr;
		}
	toks_and_ops r =tokenize(expr);


	double temp_val;

	int ops_index=0;


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

	for(auto i =vec.begin(); i<vec.end();i++ ){

		cout<<*i<<",";

	}
	cout<<"\n";
};

void Parser::print_vector(vector<char> vec){

	for(auto i =vec.begin(); i<vec.end();i++ ){

		cout<<*i<<",";

	}
	cout<<"\n";
};

double Parser::eval_with_braces(string expr){

	expr_stack eval;

	for(auto i =expr.begin();i<expr.end();i++){

		eval.push(*i);

	}


	return evaluate(eval.expr);



};





