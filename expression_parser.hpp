
#ifndef EXPR_PARSE

#define EXPR_PARSE

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

namespace parser{

//#define COLOROUTPUT 1

//For windows systems do not un-comment the above macro
// For linux systems uncomment COLOROUTPUT macro to get color formatted outputs

#ifdef COLOROUTPUT
//the following are colour codes for stdout in UBUNTU/LINUX
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#endif

#ifndef COLOROUTPUT

#define RESET   ""
#define BLACK   ""
#define RED     ""
#define GREEN   ""
#define YELLOW  ""
#define BLUE    ""
#define MAGENTA ""
#define CYAN    ""
#define WHITE   ""
#define BOLDBLACK  ""
#define BOLDRED    ""
#define BOLDGREEN   ""
#define BOLDYELLOW  ""
#define BOLDBLUE    ""
#define BOLDMAGENTA ""
#define BOLDCYAN   ""
#define BOLDWHITE  ""

#endif



#define PLUS '+'
#define MINUS '-'
#define MULTI '*'
#define DIV '/'
#define POWER '^'
#define LBRAC '('
#define RBRAC ')'

using namespace std;

struct toks_and_ops;
struct expr_stack;


class Parser{

public :

	static void remov(int pos, vector<double>& nums);

	static void remov(int pos, vector<int>& nums);

	static void remov(int pos, vector<char>& ops);

	static	double get_num(string num);

	static	double evaluate(string expr);

	static toks_and_ops tokenize(string expr);

	static void print_vector(vector<double> vec);

	static void print_vector(vector<char> vec);

	static double eval_with_braces(string expr);
};


struct toks_and_ops{

	vector<double> toks;
	vector<char> ops;

};


struct expr_stack{


	int ind=0;

	vector<int> prev_l_bracs;
	int prev= -1;

	string expr="";


	void push(char i){

		if(i == LBRAC){
			prev_l_bracs.push_back(ind);
			prev= ind;
			expr+= i;
			ind++;

		}else if(i == RBRAC && prev>=0){



			string ref=expr.substr(prev +1 , ind -prev  );

			ref=to_string(Parser::evaluate(ref));


			expr = expr.substr(0, prev)+ ref;
			ind =prev+ ref.size();

			Parser::remov(prev_l_bracs.size() -1 ,prev_l_bracs);



			if(!prev_l_bracs.empty()){

				prev = (prev_l_bracs.at(prev_l_bracs.size()-1));

			}else{
				prev =-1;
			}


		}else{

			expr+= i;
			ind++;
		}

	};

};





}
#endif
