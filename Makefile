all:
	g++ src/expression_parser.cpp src/main.cpp -o run

clean:
	rm run