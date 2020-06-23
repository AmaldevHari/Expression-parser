#include "expression_parser.hpp"

static double Parser::get_num(string num){

	return ::stod(num);
}

static toks_and_ops Parser::tokenize(string expr){

	const int len= expr.size();
	string tok ="";

	char current_char;

	 toks_and_ops res;

	vector<double> toks;
	vector<char> ops ;

	int	current_index=0;


	while(current_index<len){

		current_char=expr.at(current_index);

		if((current_char<58 && current_char>47) || current_char == 46){

			tok +=current_char;

		}else{
			toks.push_back( get_num(tok));
			ops.push_back(current_char);

			tok="";

		}
		current_index++;
	}

	 res.toks =toks;
	 res.ops=ops;
	 return res;

}

static double Parser::evaluate(string expr){

	toks_and_ops r =tokenize(expr);

	int ops_index=1;

	for(auto i = r.ops.begin(); i< r.ops.end();i++){

	}

};

