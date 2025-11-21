/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:48:21 by luide-ca          #+#    #+#             */
/*   Updated: 2025/11/21 16:04:41 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

void	test_inf(void)
{
	//------------------INF---------------
	std::cout << "---------INF---------" << std::endl;

	std::cout << "inf" << std::endl;
	ScalarConverter::convert("inf");
	std::cout << std::endl;

	std::cout << "+inf" << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << std::endl;

	std::cout << "-inf" << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << std::endl;
}

void	test_inff(void)
{
	//------------------INFF---------------
	std::cout << "---------INFF---------" << std::endl;

	std::cout << "inff" << std::endl;
	ScalarConverter::convert("inff");
	std::cout << std::endl;

	std::cout << "+inff" << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << std::endl;

	std::cout << "-inff" << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << std::endl;
}

void	test_nan(void)
{
	//------------------NAN---------------
	std::cout << "---------NAN---------" << std::endl;
	
	std::cout << "nan" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;
	
	std::cout << "+nan" << std::endl;
	ScalarConverter::convert("+nan");
	std::cout << std::endl;

	std::cout << "-nan" << std::endl;
	ScalarConverter::convert("-nan");
	std::cout << std::endl;
}

void	test_nanf(void)
{
	//------------------NANF---------------
	std::cout << "---------NANF---------" << std::endl;
	std::cout << "nanf" << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << std::endl;

	std::cout << "+nanf" << std::endl;
	ScalarConverter::convert("+nanf");
	std::cout << std::endl;

	std::cout << "-nanf" << std::endl;
	ScalarConverter::convert("+nanf");
}

void	test_char(void)
{
	//------------------CHAR---------------
	std::cout << "---------CHAR---------" << std::endl;
	std::cout << "a" << std::endl;
	ScalarConverter::convert("a");
	std::cout << std::endl;

	std::cout << "\'a\'" << std::endl;
	ScalarConverter::convert("\'a\'");
	std::cout << std::endl;
}

void	test_int(void)
{
	//------------------INTEGER---------------
	std::cout << "---------INTEGER---------" << std::endl;
	std::cout << "42" << std::endl;
	ScalarConverter::convert("42");
	std::cout << std::endl;

	std::cout << "67" << std::endl;
	ScalarConverter::convert("67");
	std::cout << std::endl;

	std::cout << "0" << std::endl;
	ScalarConverter::convert("0");
	std::cout << std::endl;

	std::cout << "-123" << std::endl;
	ScalarConverter::convert("-123");
	std::cout << std::endl;

	std::cout << "2147483647" << std::endl; // INT_MAX
	ScalarConverter::convert("2147483647");
	std::cout << std::endl;

	std::cout << "-2147483648" << std::endl; // INT_MIN
	ScalarConverter::convert("-2147483648");
	std::cout << std::endl;

	std::cout << "  123  " << std::endl; // Leading/trailing spaces
	ScalarConverter::convert("  123  ");
	std::cout << std::endl;

	std::cout << "+456" << std::endl; // Explicit plus sign
	ScalarConverter::convert("+456");
	std::cout << std::endl;

	std::cout << "-456" << std::endl; // Explicit plus sign
	ScalarConverter::convert("-456");
	std::cout << std::endl;

	std::cout << "12abc34" << std::endl; // Invalid integer input
	ScalarConverter::convert("12abc34");
	std::cout << std::endl;

	std::cout << "-0" << std::endl; // Negative zero
	ScalarConverter::convert("-0");
	std::cout << std::endl;
}

void	test_float(void)
{
	//------------------FLOAT---------------
	std::cout << "---------FLOAT---------" << std::endl;

	std::cout << "1.23456789f" << std::endl; // High precision
	ScalarConverter::convert("1.23456789f");
	std::cout << std::endl;

	std::cout << "3.4028235e+38f" << std::endl; // Float max
	ScalarConverter::convert("3.4028235e+38f");
	std::cout << std::endl;
}

void	test_double(void)
{
	//------------------DOUBLE---------------
	std::cout << "---------DOUBLE---------" << std::endl;

	std::cout << "-3.4028235e+38" << std::endl; // Double min
	ScalarConverter::convert("-3.4028235e+38");
	std::cout << std::endl;

	std::cout << "1.7976931348623157e+308" << std::endl; // Double max
	ScalarConverter::convert("1.7976931348623157e+308");
	std::cout << std::endl;

	std::cout << "-1.7976931348623157e+308" << std::endl; // Negative Double max
	ScalarConverter::convert("-1.7976931348623157e+308");
	std::cout << std::endl;
}

void	test_battery(void)
{
	test_inf();
	test_inff();
	test_nan();
	test_nanf();
	test_char();
	test_int();
	test_float();
	test_double();
}

#ifndef DEBUG
# define DEBUG 0
#endif

int main(int argc, const char *argv[])
{
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	if (DEBUG)
		test_battery();
	return (0);
}