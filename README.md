# Expression-parser
Mathematical expression parser and interpreter written in C++

![alt text](https://imgur.com/gallery/EeLe6Az)

The software can read expressions which includes nested expressions with brackets and interprets its based 
on BEDMAS.

The result is printed out.
*****************************************************************************
For building/cleaning/executing binary in windows:

1) execute 'win.bat' with one of the following arguments:
			(i)   run
			(ii)  clean
			(iii) compile

Note: start by compiling then running. Clean to rebuild if required
example: win compile
	 win run

For building/cleaning/executing binaryin Linux:
1) execute 'linux' file with oneof the following arguments:
			(i)   run
			(ii)  clean
			(iii) compile
	 
exmaple: ./linux compile
	 ./linux run

*****************************************************************************

A breif description of the methods are documented inside the 
expression_parser.cpp file

run the executable and type help for breif information on builtins 
and commands.

*****************************************************************************

Example valid expressions that can be parsed and computed by this software:

(1) sin(2*pi)
(2) (2*(3^2))
(3) ((((tan(pi/3)))))
(4) e^(-1)
(5) pi^2

and so on and so forth
*****************************************************************************
To generate documentation use the config_file that comes with this project
example: execute 'doxygen config_file'
