# Expression-parser
Mathematical expression parser and interpreter written in C++

![alt text](https://i.imgur.com/frWuQuM.png)

TO install the library and headers simply run install script provided.
To test the program execute the binary file in bin folder.

The program can read expressions which includes nested expressions with brackets and interprets its based 
on BEDMAS.

The result is printed out.
*****************************************************************************

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
