

all: 
	g++ expression_parser.cpp main.cpp -o run

	
clean:
	rm -f run