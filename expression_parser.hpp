
#ifndef EXPR_PARSE

#define EXPR_PARSE

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define PLUS '+'
#define MINUS '-'
#define MULTI '*'
#define DIV '/'
#define POWER '^'
#define LBRAC '('
#define RBRAC ')'

using namespace std;

struct toks_and_ops{

	vector<double> toks;
	vector<char> ops;

};



class Parser{

public :

	static void remov(int pos, vector<double>& nums);

	static void remov(int pos, vector<char>& ops);

	static	double get_num(string num);

	static	double evaluate(string expr);

	static toks_and_ops tokenize(string expr);

	static void print_vector(vector<double> vec);

	static void print_vector(vector<char> vec);

	static double eval_with_braces(string expr);
};

struct expr_stack{


	int ind=0;

	vector<int> prev_l_bracs;
	int prev= -1;

	string expr;
	void push(char i){

		if(i == LBRAC){
			prev_l_bracs.push_back(ind);
			prev= ind;
			expr+= i;
		}else if(i == RBRAC && prev>=0){

			expr = expr.substr(0, prev)+ to_string(Parser::evaluate(expr.substr(prev +1 , ind -prev )));

			prev_l_bracs.erase(prev_l_bracs.end());

			prev = *prev_l_bracs.end();

		}else{

			expr+= i;
		}

		ind++;
	};

};

#endif
