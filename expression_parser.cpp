#include "expression_parser.hpp"

double Parser::get_num(string num){

	return ::stod(num);
}

 toks_and_ops Parser::tokenize(string expr){

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
			cout<<tok<<"\n";
			cout<<current_char<<"\n";
			toks.push_back( get_num(tok));
			ops.push_back(current_char);

			tok="";

		}
		current_index++;
	}
	toks.push_back(get_num(tok));

	 res.toks =toks;
	 res.ops=ops;
	 return res;

}

 double Parser::evaluate(string expr){

	double res;
	toks_and_ops r =tokenize(expr);

	int ops_index=0;

	for(auto i = r.ops.begin(); i< r.ops.end();i++){

		if(*i == MULTI){
			res += r.toks[ops_index+1] * r.toks[ops_index];

		}
		ops_index++;
	}
	ops_index=0;
	for(auto i = r.ops.begin(); i< r.ops.end();i++){

		if(*i == DIV){
			res += r.toks[ops_index] / r.toks[ops_index+1];

		}
		ops_index++;
	}

	ops_index=0;
		for(auto i = r.ops.begin(); i< r.ops.end();i++){

			if(*i == PLUS){
				res += r.toks[ops_index+1] + r.toks[ops_index];

			}
			ops_index++;
		}

		ops_index=0;
			for(auto i = r.ops.begin(); i< r.ops.end();i++){

				if(*i == MINUS){
					res += r.toks[ops_index] - r.toks[ops_index+1];

				}
				ops_index++;
			}

			return res;

};

